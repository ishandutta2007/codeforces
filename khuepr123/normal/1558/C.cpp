/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
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

vector<int> ord;

void rev(int val){
    reverse(a + 1, a + val + 1);
    ord.pb(val);
    for1(i, 1, n){
        if(a[i] == n) x = i;
        if(a[i] == n - 1) y = i;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        bool killed = 0;
        for1(i, 1, n){
            cin >> a[i];
            if((a[i] - i) % 2) killed = 1;
        }
        if(killed){
            cout << "-1\n";
            continue;
        }
        k = n;
        ord.clear();
        while(n != 1){
            rev(1);
            ord.pop_back();
            rev(x);
            rev(y - 1);
            rev(n);
            rev(x);
            rev(n);
            n -= 2;
        }
        cout << ord.size() << endl;
        for(int cc : ord){
            cout << cc << " ";
        }
        cout << endl;
    }
}