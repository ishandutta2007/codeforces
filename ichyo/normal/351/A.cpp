#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;

int main(){
    int n;
    while(cin >> n && n){
        vector<int> v(2 * n);
        int zeros = 0;
        REP(i, 2 * n){
            string s;
            cin >> s;
            s = s.substr(s.size() - 3, 3);
            stringstream ss(s);
            ss >> v[i];
            if(v[i] == 0) zeros ++;
        }
        ll sum = 0;
        for(int i = 0; i < 2 * n; i++) sum += v[i];
        ll ans = 10000000000000000LL;
        for(int lz = 0; lz <= n; lz++){
            int rz = zeros - lz;
            if(rz < 0 || rz > n) continue;
            ll diff = 1000LL * (n - lz) - sum;
            ans = min(ans, abs(diff));
        }
        cout << ans / 1000 << ".";
        printf("%03d\n", int(ans % 1000));
    }
    return 0;
}