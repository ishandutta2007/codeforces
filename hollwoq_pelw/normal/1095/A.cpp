#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

int n;
string s;
int g[] = {0,1,3,6,10,15,21,28,36,45,55};

void solve(){
    cin >> n >> s;
    for (auto i: g){
        if (i >= n) break;
        cout << s[i];
    }
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