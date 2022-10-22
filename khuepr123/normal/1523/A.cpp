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
int n, a[maxN], b[maxN];
int x, y, z, k;
int m;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> m;
        a[0] = 0; a[n + 1] = 0;
        char c;
        for1(i, 1, n){
            cin >> c; a[i] = (c == '1');
        }
        m = min(m, 1000ll);
        for1(wtfff, 1, m){
            for1(i, 1, n){
                b[i] = 0;
                if(a[i]) b[i] = 1;
                if(a[i - 1] + a[i + 1] == 1) b[i] = 1;
            }
            for1(i, 1, n){
                a[i] = b[i];
            }
        }
        for1(i, 1, n){
            cout << a[i];
        }
        cout << endl;
    }
}