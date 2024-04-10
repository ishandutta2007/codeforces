#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    printf("%s\n",(a[2]==a[0]+a[1]||a[0]==a[1]||a[1]==a[2])&&(a[0]+a[1]+a[2])%2==0?"YES":"NO");
}

int main() {
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}