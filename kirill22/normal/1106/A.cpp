#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m,k,ans=0;
    cin >> n;
    char a[n][n];
    for(int i=0;i<n;i++){
        for(int u=0;u<n;u++){
            cin >> a[i][u];
        }

    }
    for(int i=1;i<n-1;i++){
        for(int u=1;u<n-1;u++){
            if (a[i][u]=='X' && a[i-1][u-1]=='X' && a[i-1][u+1]=='X' && a[i+1][u+1]=='X' && a[i+1][u-1]=='X'){
                ans++;
            }
        }

    }
    cout << ans;





}