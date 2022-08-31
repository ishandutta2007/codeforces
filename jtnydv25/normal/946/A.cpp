#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){

        int x;
        cin>>x;
        ans += abs(x);
    }
    cout << ans;
}