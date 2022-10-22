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
    int o; cin >> o;
    while(o--){
        cin >> n;
        bool bk = 1;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            int h = sqrt(a[i]);
            if(h * h != a[i]) bk = 0;
        }
        if(bk) cout << "NO\n";
        else cout << "YES\n";
    }
}