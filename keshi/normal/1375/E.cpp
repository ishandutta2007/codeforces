//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, a[maxn], b[maxn], c[maxn], cnt;

int main(){
    fast_io;

    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        for(ll j = 0; j < i; j++){
            if(a[j] > a[i]){
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(Mp(a[i], i) < Mp(a[j], j)){
                b[i]++;
            }
        }
        c[b[i]] = i;
    }
    for(ll i = n; i--;){
        for(ll j = b[i]; j--;){
            if(c[j] < i){
                cout << c[j] + 1 << " " << i + 1 << '\n';
            }
        }
    }

    return 0;
}