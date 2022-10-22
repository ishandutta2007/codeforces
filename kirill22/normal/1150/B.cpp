#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD =1e9 + 7;
signed main() {
    int n;
    cin >> n;
    char a[n][n];
    for(int i=0;i<n;i++){
        for(int u=0;u<n;u++){
            cin >> a[i][u];
        }
    }
    bool  f = true;
    for(int i =0;i<n;i++){
        for(int u=0;u<n;u++){
            if(a[i][u] =='.'){
                if(i >= n - 2 || u == 0 || u == n - 1){
                    f =false;
                    break;
                }
                a[i][u]='#';
                if(a[i+1][u]!='.'){
                    f=false;
                    break;
                }
                else{
                    a[i+1][u]='#';
                }
                if(a[i+1][u-1]!='.'){
                    f=false;
                    break;
                }
                else{
                    a[i+1][u-1]='#';
                }
                if(a[i+1][u+1]!='.'){
                    f=false;
                    break;
                }
                else{
                    a[i+1][u+1]='#';
                }
                if(a[i+2][u]!='.'){
                    f=false;
                    break;
                }
                else{
                    a[i+2][u]='#';
                }
            }
        }
    }
    if(f){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

}