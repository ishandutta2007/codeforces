#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    int ans = 0;
    REP(i, m){
        if(i < n){
            ans += a[i];
        }else{
            ans -= d;
        }
    }
    cout << ans << endl;
    return 0;
}