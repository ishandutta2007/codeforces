#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int ans = 1;
    vector<int> vc;
    for(int i = 1; i <= n; i++){
        if(__gcd(n, i) == 1){
            ans *= i;
            ans %= n;
        }
    }
    if(ans == 1) ans = 0;
    for(int i = 1; i <= n; i++){
        if(__gcd(n, i) == 1 && ans != i){
            vc.pb(i);
        }
    }
    cout << vc.size() << endl;
    for(auto i : vc){
        cout << i << " ";
    }
}