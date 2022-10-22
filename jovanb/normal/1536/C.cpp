#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map <pair <int, int>, int> ima;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ck = 0, cd = 0;
    ima.clear();
    for(int i=0; i<n; i++){
        if(s[i] == 'K') ck++;
        else cd++;
        int g = __gcd(ck, cd);
        int a = ck/g;
        int b = cd/g;
        ima[{a, b}]++;
        cout << ima[{a, b}] << " ";
    }
    cout << "\n";
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