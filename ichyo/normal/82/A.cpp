#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;

int main(){
    ll n;
    while(cin >> n){
        n--;
        ll curr = 1;
        while(curr * 5 <= n){
            n -= curr * 5;
            curr *= 2;
        }
        n /= curr;
        string ans[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
        assert(n >= 0 && n < 5);
        cout << ans[n] << endl;
    }
    return 0;
}