#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>

int main(){
    IOS;
    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        if (n%m==0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}