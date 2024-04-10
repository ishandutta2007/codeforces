#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> a;
int main(){
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        a[arr[i]] ++;
    }
    vector<pair<int, pair<int, int>>> ans;
    int m = -1;
    for (auto& [k, v]:a){
        if (m == -1 || a[m] < v) m = k;
    }
    int mid = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == m) {mid = i; break;}
    }
    for (int i = mid+1; i < n; i++){
        if (arr[i] > m) ans.push_back({2, {i, i-1}});
        if (arr[i] < m) ans.push_back({1, {i, i-1}});
    }
    for (int i = mid-1; i >= 0; i--){
        if (arr[i] > m) ans.push_back({2, {i, i+1}});
        if (arr[i] < m) ans.push_back({1, {i, i+1}});
    }
    cout << ans.size() << endl;
    for (auto& [t, p]:ans){
        cout << t << ' ' << p.first+1 << ' ' << p.second+1 << endl;
    }
    return 0;
}