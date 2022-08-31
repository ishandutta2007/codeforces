#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll,ll>
#define pb push_back
#define mp(x, y) make_pair((x), (y))
#define F first
#define S second
#define I insert
#define vll vector<ll>
#define vpll vector<pll>
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()

    
const ll Mod = 1e9 + 7;
ll A[10];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int n; cin >> n;
    string s; cin >> s;

    for(int i = 0 ;i < n ; i++){
    	A[s[i]-'0']++;
    }
    int ans = 0;
    for(int i = 0 ; i <= A[8] ; i++)
    	ans = max(ans , min(i , (n-i)/10));
    cout << ans << endl;
    return 0;
}