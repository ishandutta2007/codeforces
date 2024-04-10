#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;
string itos(ll n){
    stringstream ss;
    ss << n;
    return ss.str();
}
ll mystl(string s){
    stringstream ss(s);
    ll res;
    ss >> res;
    return res;
}
const int lucky[3] = {0, 4, 7};
vector< vector<int> > opes;
vector< int > ope_sum;
void init(){
    const int MS = 3 * 3 * 3 * 3 * 3 * 3;
    REP(S, MS){
        vector<int> v(6);
        int tmpS = S;
        int sum = 0;
        REP(i, 6) {
            v[i] = tmpS % 3;
            tmpS /= 3;
        }
        REP(i, 5) if(v[i] > v[i + 1]) goto NEXT;
        REP(i, 6) sum += lucky[v[i]];
        opes.push_back(v);
        ope_sum.push_back(sum);
NEXT:;
    }
}
vector<ll> solve(ll n){
    string s = itos(n);
    reverse(s.begin(), s.end());
    bool dp[30][10] = {};
    int memoS[30][10] = {};
    int memoC[30][10] = {};
    dp[0][0] = true;
    for(int i = 0; i < s.size(); i++){
        for(int c = 0; c < 10; c++){
            if(!dp[i][c]) continue;
            REP(j, opes.size()){
                int sum = c + ope_sum[j];
                if(sum % 10 == s[i] - '0'){
                    dp[i + 1][sum / 10] = true;
                    memoS[i + 1][sum / 10] = j;
                    memoC[i + 1][sum / 10] = c;
                }
            }
        }
    }
    if(dp[s.size()][0]) {
        string res[6];
        int C = 0;
        int I = s.size();
        while(I > 0){
            int S = memoS[I][C];
            REP(i, 6) {
                res[i] += string(1, lucky[ opes[S][i] % 3 ] + '0');
            }
            C = memoC[I][C];
            I--;
        }
        vector<ll> v;
        REP(i, 6){
            //reverse(res[i].begin(), res[i].end());
            v.push_back(mystl(res[i]));
        }
#ifdef MYDEBUG
        ll sum = n;
        REP(i, 6) sum -= v[i];
        assert(sum == 0);
#endif
        return v;
    }
    return vector<ll>(1, -1);
}

int main(){
    init();
    int T;
    cin >> T;
#ifdef MYDEBUG
    for(ll n = 0; n < 5000; n++){
        solve(10000000000000000LL + n);
    }
#endif
    REP(i, T){
        ll n;
        cin >> n;
        vector<ll> ans = solve(n);
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
            if(i != ans.size() - 1) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}