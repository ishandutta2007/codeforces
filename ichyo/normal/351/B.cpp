#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;
ll calc(ll rev){
    if(rev == 0) return 0;
    if(rev == 1) return 1;
    if(rev % 2 == 0){
        return rev / 2 * 4;
    }else{
        return rev / 2 * 4 + 1;
    }
}

int main(){
    int n;
    while(cin >> n && n){
        vector<int> v(n);
        REP(i, n) cin >> v[i];
        ll rev = 0;
        REP(i, n) for(int j = i + 1; j < n; j++) if(v[i] > v[j]){
            rev++;
        }
        cout << calc(rev) << endl;
    }
    return 0;
}