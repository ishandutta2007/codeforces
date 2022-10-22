#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve(){
    int n;
    cin >> n;
    if(n <= 10){
        for(int i=0; i<n; i++) cout << char(i + 'a');
        cout << "\n";
    }
    else if(n%2){
        int len = (n-2)/2;
        for(int i=0; i<len; i++) cout << "a";
        cout << "bc";
        for(int i=0; i<len+1; i++) cout << "a";
        cout << "\n";
    }
    else{
        int len = (n-1)/2;
        for(int i=0; i<len; i++) cout << "a";
        cout << "b";
        for(int i=0; i<len+1; i++) cout << "a";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}