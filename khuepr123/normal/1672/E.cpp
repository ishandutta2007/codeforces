/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option
 
#include<bits/stdc++.h>
using namespace std;
 
#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
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
 
int stock = 0;
 
int qry(int num){
    if(num <= 0) return mod;
    cout << "? " << num << endl;
    cin >> num;
    if(num <= 0) return mod;
    return num;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int l = 1, r = 1e9;
    while(l != r){
        int mid = (l + r) / 2;
        if(qry(mid) == 1) r = mid;
        else l = mid + 1;
    }
    int curr = r;
    for2(i, n, 2){
        // try to ask for n - 1 row of height
        while(1){
            int infu = r - (i - 1); // best possible
            int asker = curr / i;
            if(asker * i == curr) --asker;
            if(asker * i < infu) break;
            int h = qry(asker);
            if(h * asker >= curr) break;
            curr = h * asker;
        }
    }
    cout << "! " << curr << endl;
}