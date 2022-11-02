#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main(){
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    unordered_set <int> s;
    for (auto elem : arr){
        s.insert(elem);
    }
    if (s.size() < n){
        cout << 0;
        return 0;
    }
    int arr2[n];
    for (int i = 0; i < n; ++i){
        arr2[i] = arr[i] & x;
        if (s.count(arr2[i]) && arr2[i] != arr[i]){
            cout << 1;
            return 0;
        }
    }
    unordered_set <int> s2;
    for (auto elem : arr2){
        s2.insert(elem);
    }
    if (s2.size() < n){
        cout << 2;
    }
    else{
        cout << -1;
    }
    return 0;
}