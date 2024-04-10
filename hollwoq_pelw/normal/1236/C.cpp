#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n][n];
    int j = 0, k = 1;
    for (int j = 0; j < n; j ++){
        for (int i = 0; i < n; i ++){
            if (j%2==0){
                a[i][j] = k;
            }else{
                a[n-i-1][j] = k;
            }
            k ++;
        }
    }
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}