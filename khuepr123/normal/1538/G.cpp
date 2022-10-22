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
int n, a, b;
int x, y, z, k;
int ans;

void pin(int num){
    if(num < 0 || num > y) return;
    ans = max(ans, num / (a + b) * 2 +
              min((x - num) / a, (y - num) / b));
}

void func(int num){
    num /= (a + b);
    for1(i, num - 500, num + 500) pin(i * (a + b));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        ans = 0;
        cin >> x >> y >> a >> b;
        if(a == b){
            cout << min(x, y) / a << endl; continue;
        }
        if(a < b) swap(a, b);
        if(x < y) swap(x, y);
        func(0);
        int dif = ((x - y)) / (a - b);
        func(x - dif * a);
        func(x - dif * a - a);
        func(x - dif * a + a);
        cout << ans << endl;
    }
}