#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> V[100005];
int A[100005], B[100005], W[100005];
int N, S[100005], PW[100005];

void dfS(int c, int p) {
    S[c]=1;
    FO(i,0,sz(V[c])) {
        int e=V[c][i];
        int x=A[e]^B[e]^c;
        if (x!=p) {
            PW[x]=W[e];
            dfS(x,c);
            S[c]+=S[x];
        }
    }
}

void dfA(int c, int p, vector<int> &v) {
    v.push_back(c);
    FO(i,0,sz(V[c])) {
        int e=V[c][i];
        int x=A[e]^B[e]^c;
        if (x!=p) dfA(x,c,v);
    }
}

void pv(vector<int> v) {
    FO(i,0,sz(v)) printf("%d ", v[i]);
    printf("\n");
}

int G[100005];
int Q[100005], R[100005];
set<int> M[100005];

vector<int> solve(const vector<vector<int> > &v) {
    //printf("SLV\n");
    //FO(i,0,sz(v)) pv(v[i]);

    int tot = 0;
    int mx = 0;
    FO(i,1,N+1) G[i]=-1;
    FO(i,0,sz(v)) {
        Q[i] = R[i] = sz(v[i]);
        tot += sz(v[i]);
        mx = max(mx,sz(v[i]));
        FO(j,0,sz(v[i])) G[v[i][j]] = i;
        M[i] = set<int>(v[i].begin(),v[i].end());
    }
    if (mx > tot-mx) return vector<int>(1,1e9);
    set<int> h;
    FO(i,0,sz(v)) h.insert(*M[i].begin());
    multiset<pair<int,int> > gg;
    FO(i,0,sz(v)) gg.insert(make_pair(Q[i]+R[i],i));

    vector<int> res(N);
    FO(i,1,N+1) {
        if (G[i]==-1) {
            res[i-1]=i;
            continue;
        }
        int gi = G[i];
        int gj = -1;
        // need maxval of Q[i]+R[i] to be <= tot
        for (multiset<pair<int,int> >::reverse_iterator it = gg.rbegin(); it != gg.rend() &&  it->first == tot; ++it) {
            if (it->second == gi) continue;
            // must pair with it->second
            gj = it->second;
            break;
        }
        if (gj == -1) {
            for (set<int>::iterator it = h.begin(); it != h.end(); ++it) {
                if (G[*it] == gi) continue;
                gj = G[*it];
                break;
            }
        }
        int j = *M[gj].begin();
        //printf("pair %d with %d\n", i, j);

        // Q, R, M, gg, h, tot, res
        gg.erase(make_pair(Q[gi]+R[gi],gi));
        gg.erase(make_pair(Q[gj]+R[gj],gj));
        Q[gi]--; R[gj]--;
        gg.insert(make_pair(Q[gi]+R[gi],gi));
        gg.insert(make_pair(Q[gj]+R[gj],gj));
        M[gj].erase(j);
        h.erase(j);
        if (sz(M[gj])) h.insert(*M[gj].begin());
        tot--;

        res[i-1] = j;
    }

    return res;
}

int main() {
    scanf("%d",&N);
    FO(i,0,N-1) {
        scanf("%d%d%d",A+i,B+i,W+i);
        V[A[i]].push_back(i);
        V[B[i]].push_back(i);
    }
    dfS(1,0);
    int r = -1;
    FO(i,1,N+1) {
        int mc=N-S[i];
        FO(j,0,sz(V[i])) {
            int e=V[i][j];
            int x=A[e]^B[e]^i;
            if (S[x] < S[i]) mc = max(mc,S[x]);
        }
        if (mc <= N/2) r = i;
    }
    assert(r!=-1);
    //printf("r=%d\n", r);
    PW[r]=0;
    dfS(r,0);
    long long sum=0;
    FO(i,1,N+1) sum+=PW[i]*2ll*S[i];

    vector<int> res;
    {
        vector<vector<int> > v(sz(V[r]));
        FO(i,0,sz(V[r])) {
            dfA(A[V[r][i]]^B[V[r][i]]^r,r,v[i]);
        }
        res = solve(v);
        vector<int> _v(1,r);
        v.push_back(_v);
        res = min(res,solve(v));
    }
    printf("%lld\n", sum);
    pv(res);
}