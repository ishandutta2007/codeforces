#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;

int main(){
    int N, M;
    while(cin >> N >> M){
        vector<int> L(M);
        vector<int> R(M);
        vector<int> X(M);
        REP(i, M) cin >> L[i] >> R[i] >> X[i];
        REP(i, M) L[i]--;
        REP(i, M) R[i]--;
        REP(i, M) X[i]--;
        vector<int> least(N, 0);
        for(int i = 0; i < M; i++){
            least[ X[i] ] = i + 1;
        }
        vector<vector<int>> add(N);
        vector<vector<int>> sub(N);
        for(int i = 0; i < M; i++){
            add[ L[i] ].push_back(i);
            sub[ R[i] ].push_back(i);
        }
        set<int> cand;
        vector<int> ans(N);
        for(int i = 0; i < N; i++){
            for(auto ai : add[i]) cand.insert(ai);
            //cout << least[i] << " ";
            if(least[i] != M) {
                int id = *cand.lower_bound(least[i]);
                //cout << id << " ";
                ans[i] = X[id] + 1;
                //cout << ans[i] << endl;
            }
            for(auto si : sub[i]) cand.erase(si);
        }
        for(int i = 0; i < N; i++){
            cout << ans[i];
            if(i == N - 1) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}