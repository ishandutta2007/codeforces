#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve(){
    string s,a;
    cin >> s;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        if (s[0] == a[0] || s[1] == a[1]) {cout << "YES"; return ;}
    }
    cout << "NO";
}

int main(){
    IOS;
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}