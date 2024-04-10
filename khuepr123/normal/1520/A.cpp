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
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        char c;
        for1(i, 1, n){
            cin >> c;
            a[i] = c - 'A';
            // cout << c;
        }
        bool perf = 1;
        for1(j, 0, 25){
            int l = 1;
            int r = n;
            while(a[l] != j && l < r) l++;
            while(a[r] != j && l <= r) r--;
            while(l <= r){
                if(a[l] != j) perf = 0;
                l++;
            }
        }
        if(perf) cout << "YES\n";
        else cout << "NO\n";
    }
}