#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    int mx=-1;
    int x;
    for(int i=1; i<=n; i++){
        cin >> x;
        if(x > mx+1){cout << i; return 0;}
        mx = max(x, mx);
    }
    cout << -1;
    return 0;
}