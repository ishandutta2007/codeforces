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
        cin >> n >> x;
        int sam = 0;
        for1(i, 1, n){
            cin >> a[i];
            sam += a[i];
        }
        if(sam == x){
            cout << "NO\n"; continue;
        }
        sam = 0;
        sort(a + 1, a + n + 1);
        for1(i, 1, n - 1){
            sam += a[i];
            if(sam == x){
                swap(a[i], a[i + 1]);
                break;
            }
        }
        cout << "YES\n";
        for1(i, 1, n){
            cout << a[i] << " ";
            sam += a[i];
        }
        cout << endl;
    }
}