#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;

int main(){
    int ans = 0;
    int n;
    cin >> n;
    vector<int> v(n);
    REP(i, n) cin >> v[i];
    REP(i, n) v[i] = abs(v[i]);
    for(int i = 0; i < n; i++){
        int add = INF;
        int cur = 0;
        for(int j = 0; j < i; j++){
            if(-v[j] > -v[i]) cur++;
        }
        for(int j = i + 1; j < n; j++){
            if(-v[i] > v[j]) cur++;
        }
        add = min(add, cur);
        cur = 0;
        for(int j = 0; j < i; j++){
            if(-v[j] > v[i]) cur++;
        }
        for(int j = i + 1; j < n; j++){
            if(v[i] > v[j]) cur++;
        }
        add = min(add, cur);
        ans += add;
    }
    cout << ans << endl;
    return 0;
}