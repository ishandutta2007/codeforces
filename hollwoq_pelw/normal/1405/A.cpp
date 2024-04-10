#include<bits/stdc++.h>
using namespace std;

int n, t, a[101];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = n; i; i--) cout << a[i] << ' ';
        cout << endl;
    }
}