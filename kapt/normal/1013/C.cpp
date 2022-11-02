#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main(){
    int n;
    cin >> n;
    int arr[2 * n];
    for (int i = 0; i < 2 * n; ++i){
        cin >> arr[i];
    }
    sort(arr, arr + 2 * n);
    int x1 = (arr[n - 1] - arr[0]) * (arr[2 * n - 1] - arr[n]);
    int x2 = 1e19;
    for (int i = 1; i < n; ++i){
        if ((arr[2 * n - 1] - arr[0]) * (arr[i + n - 1] - arr[i]) < x2){
            x2 = (arr[2 * n - 1] - arr[0]) * (arr[i + n - 1] - arr[i]);
        }
    }
    cout << min(x1, x2);
    return 0;
}