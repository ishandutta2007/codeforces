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
int b[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        queue<int> q1;
        int sm = 0;
        for1(i, 1, n) cin >> a[i];
        for1(i, 1, n) cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1, greater<int>());
        for1(i, 1, n){
            q1.push(a[i]);
            sm += a[i];
        }
        while(q1.size() > (n - n / 4)){
            sm -= q1.front();
            q1.pop();
        }
        int it = 0;
        while(it < (n - n / 4)){
            ++it;
            sm -= b[it];
        }
        int m = n;
        while(sm < 0){
            ++m;
            q1.push(100);
            sm += 100;
            while(q1.size() > (m - m / 4)){
                sm -= q1.front();
                q1.pop();
            }
            while(it < (m - m / 4) && it < n){
                ++it;
                sm -= b[it];
            }
        }
        cout << m - n << endl;
    }
}