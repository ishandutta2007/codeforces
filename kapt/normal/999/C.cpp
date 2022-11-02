#include <bits/stdc++.h>
using namespace std;

main(){
    int k, n;
    cin >> n >> k;
    string str;
    cin >> str;
    char arr[n];
    for (int i = 0; i < n; ++i){
        arr[i] = str[i];
    }
    unordered_set <int> s;
    for (int i = 0; i < 26; ++i){
        if (k == 0){
            break;
        }
        for (int j = 0; j < n; ++j){
            if (k == 0){
                break;
            }
            if (arr[j] - 'a' == i){
                k--;
                s.insert(j);
            }
        }
    }
    for (int i = 0; i < n; ++i){
        if (!s.count(i)){
            cout << arr[i];
        }
    }
    return 0;
}