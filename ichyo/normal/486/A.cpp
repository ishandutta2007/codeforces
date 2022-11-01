#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef long long LL;

int main(){
    LL n;
    cin >> n;
    LL ans = 0;
    ans += (n / 2);
    if(n % 2 == 1) ans -= n;
    cout << ans << endl;
    return 0;
}