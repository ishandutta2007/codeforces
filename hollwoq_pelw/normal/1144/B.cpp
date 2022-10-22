#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin >> n;
    vector<int> a[2];
    long s = 0;
    while(n--){
        cin >> x;
        s += x;
        a[x%2].push_back(x);
    }
    sort(a[0].begin(), a[0].end(), greater<int>());
    sort(a[1].begin(), a[1].end(), greater<int>());
    int id = 0;
    while(id < min(a[0].size(), a[1].size())){
        s -= a[0][id]+a[1][id];
        id++;
    }
    if (id < a[0].size()) s-= a[0][id];
    if (id < a[1].size()) s-= a[1][id];
    cout << s;
    return 0;
}