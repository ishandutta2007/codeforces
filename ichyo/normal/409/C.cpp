#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int a[5];
    REP(i, 5) cin >> a[i];
    int b[5] = {1, 1, 2, 7, 4};
    int ans = 0;
    while(true){
        REP(i, 5) a[i] -= b[i];
        bool end = false;
        REP(i, 5) if(a[i] < 0) end = true;
        if(end) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}