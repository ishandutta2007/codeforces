#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map <int, int> ima;

int a[1005];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    vector <int> vec;
    int sad = 0;
    ima.clear();
    for(int i=1; i<=n; i++){
        if(a[i] == sad){
            sad++;
        }
        else ima[a[i]]++;
    }
    for(int val=0; val<=105; val++){
        if(!ima[val]){
            cout << sad + val << "\n";
            return;
        }
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