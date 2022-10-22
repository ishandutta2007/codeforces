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
int n, a[105][105];
int x, y, z, k;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        if(n < 4){
            if(n == 1) cout << "1\n";
            if(n == 2) cout << "-1\n";
            if(n == 3) cout << "2 9 7\n4 6 3\n1 8 5\n";
            continue;
        }
        int cur = 1;
        for1(i, 1, n){
            for1(j, 1, n){
                cout << cur << " ";
                cur += n - 1;
                if(cur > n * n) cur -= n * n;
            }
            cout << endl;
        }
    }
}