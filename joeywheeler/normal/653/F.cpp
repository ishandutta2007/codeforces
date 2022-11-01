#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

namespace SA
{
    const int MAXN = 1 << 20;
    char * S;
    int N, gap;
    int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

    bool sufCmp(int i, int j)
    {
        if (pos[i] != pos[j])
            return pos[i] < pos[j];
        i += gap;
        j += gap;
        return (i < N && j < N) ? pos[i] < pos[j] : i > j;
    }

    void buildSA()
    {
        N = strlen(S);
        REP(i, N) sa[i] = i, pos[i] = S[i];
        for (gap = 1;; gap *= 2)
        {
            sort(sa, sa + N, sufCmp);
            REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
            REP(i, N) pos[sa[i]] = tmp[i];
            if (tmp[N - 1] == N - 1) break;
        }
    }

    void buildLCP()
    {
        for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
        {
            for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
                ++k;
            lcp[pos[i]] = k;
            if (k)--k;
        }
    }
}

char s[500005];
int v[500005];
int n;
int nkless[500005];
vector<int> vls[1000005];

int cwv(int vl, int s, int e) {
    if (e-s <= 0) return 0;
    // count vl in [s,e)
    vl += 500002;
    return lower_bound(vls[vl].begin(),vls[vl].end(),e) - lower_bound(vls[vl].begin(),vls[vl].end(),s);
}

int proc(int i, int mj) {
    int ej = nkless[i];
    // proc [i,j) mj <= j <= ej
    //printf("PROC(%d,%d)\n", i, mj);
    return cwv(v[i], mj, ej+1);
}

int main() {
    scanf("%d %s", &n, s);
    SA::S = s;
    SA::buildSA();
    SA::buildLCP();
    //FO(i,0,n) printf("%s\n", s+SA::sa[i]);
    //FO(i,0,n-1) printf("%d\n", SA::lcp[i]);

    FO(i,0,n) {
        v[i+1] = v[i];
        if (s[i] == '(') v[i+1]++;
        else v[i+1]--;
    }
    FO(i,0,n+1) {
        vls[v[i]+500002].push_back(i);
    }

    vector<pair<int,int> > stk;
#define val first
#define pos second
    stk.emplace_back(-1e8, n);
    for (int i = n-1; i >= 0; i--) {
        while (stk.back().val >= v[i]) stk.pop_back();
        nkless[i] = stk.back().pos;
        stk.emplace_back(v[i], i);
    }

    //FO(i,0,n+1) printf("v[%d]=%d\n", i, v[i]);
    //FO(i,0,n) printf("nkless[%d]=%d\n", i, nkless[i]);
    int clen = 0;
    long long res = 0;
    FO(z,0,n) {
        int i = SA::sa[z];
        // [i,j) with j > i+clen?
        int a = proc(i,i+clen+1);
        //printf("result=%d\n", a);
        res += a;
        clen = SA::lcp[z];
    }
    printf("%lld\n", res);
}