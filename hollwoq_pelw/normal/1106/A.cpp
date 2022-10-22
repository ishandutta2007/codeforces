#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, c = 0;
    cin >> n;
    char a[n][n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n-1; i++){
        for (int j = 1; j < n-1; j++){
            if (a[i][j] == 'X' && a[i-1][j-1] == 'X' && a[i+1][j+1] == 'X'
                && a[i+1][j-1] == 'X' && a[i-1][j+1] == 'X') ++c;
        }
    }
    cout << c;
    return 0;
}