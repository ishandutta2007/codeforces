#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    int mx = -1, d = 0;
    set<int> myst;
    for (int i = 0; i < n; i++){
        mx = max(mx, a[i]);
        if (i==mx) d++;
    }
    cout << d;
    return 0;
}