#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6+5;
int n;

typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int, int> pii;

vl convert(LL x) {
    vl res;
    for (int i=2; x; ++i) {
        res.push_back(x%i);
        x /= i;
    }
    return res;
}

bool operator == (vl a, vl b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a.size() != b.size()) return false;
    for (int i=0; i<a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void output(const vl &a) {
    for (LL x : a) printf("%lld ", x);
    puts("");
}


LL C[100][100];



LL tryit(const vector<pii> &p) {
    int ele = 0;
    LL ans = 1;
    int n = 0;
    for (auto &pp : p) n += pp.second;
    // printf("n= %d\n", n);
    for (int i=p.size()-1; i>=0; --i) {
        // ele += p[i].first;
        int can = n - p[i].first + 1 - ele;
        if (p[i].first <= 1) can = n - ele;
        ans *= C[can][p[i].second]; 
        // printf("%d %d %d %lld\n", i, can, p[i].second, ans);
        ele += p[i].second;
    }
    return ans;
}

int main() {


    C[0][0] = 1;
    C[1][0] = C[1][1] = 1;
    for (int i=2; i<=30; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j=1; j<i; ++j)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }



    int t;
    scanf("%d", &t);
    for (int kk=0; kk<t; ++kk) {
        LL x;
        scanf("%lld", &x);
        if (x == 1) {
            puts("0");
            continue;
        }
        vl v = convert(x);
        sort(v.begin(), v.end());
        vector<pii> p;
        for (int i=0, j; i<v.size(); i=j+1) {
            j = i;
            while (j+1<v.size() && v[j+1] == v[i]) ++j;
            p.push_back(make_pair(v[i], j-i+1));
        }
        LL ans = tryit(p);
        // printf("ans1=%lld\n", ans);
        if (p[0].first == 0) {
            --p[0].second;
            ans -= tryit(p);
        }
        printf("%lld\n", ans-1);
    }


    return 0;
}