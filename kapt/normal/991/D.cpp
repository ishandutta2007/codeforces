#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main(){
    string arr1[2];
    cin >> arr1[0];
    cin >> arr1[1];
    int n = arr1[0].size();
    char arr[2][n];
    for (int i = 0; i < n; ++i){
        arr[0][i] = arr1[0][i];
        arr[1][i] = arr1[1][i];
    }
    int i = 0;
    int ans = 0;
    while (i < n - 1){
        if (arr[0][i] == arr[1][i] && arr[0][i] == '0'){
            if (arr[0][i + 1] == '0'){
                arr[0][i + 1] = 'X';
                // cout << i << endl;
                ans++;
            }
            else if (arr[1][i + 1] == '0'){
                arr[1][i + 1] = 'X';
                // cout << i << endl;
                ans++;
            }
        }
        else if (arr[0][i] == '0' || arr[1][i] == '0'){
            if (arr[0][i + 1] == '0' && arr[1][i + 1] == '0'){
                // cout << i << endl;
                ans++;
                i++;
            }
        }
        i++;
    }
    cout << ans;
    return 0;
}