#include<bits/stdc++.h>
using namespace std;

#define ll long long
char c[2005][2005]; int a[2005][2005]; ll sum = 0;

int main(){
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    if(n <3 || m < 3){
        n = n * m; cout << n; return 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
        }
    }
    for(int j = 1; j <= m; j++){
        a[1][j] = 1; a[2][j] = 1;
    }
    for(int i = 1; i <= n; i++){
        a[i][1] = 1;
        a[i][m] = 1;
    }
    m = m - 1; // hightlight the deceased
    for(int i = 3; i <= n; i++){
        for(int j = 2; j <= m; j++){
            if(c[i][j] == c[i - 1][j] && 
            c[i][j] == c[i - 1][j - 1] &&
            c[i][j] == c[i - 1][j + 1] &&
            c[i][j] == c[i - 2][j]){
                a[i][j] = min(a[i - 1][j - 1], min(a[i - 1][j + 1], a[i - 2][j])) + 1;
            }
            else{
                a[i][j] = 1;
            }
        }
    }
    m = m + 1; // highlight the zombie version return
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            sum = sum + a[i][j];
        }
    }
    cout << sum;
}