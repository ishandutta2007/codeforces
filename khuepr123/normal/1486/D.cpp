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
int dif[maxN];

bool ofc(int num){
    for1(i, 1, n){
        a[i] = b[i] - num;
    }
    dif[0] = 0;
    int mxdif = oo;
    for1(i, 1, n){
        if(a[i] >= 0) dif[i] = dif[i - 1] + 1;
        else          dif[i] = dif[i - 1] - 1;
        if(i >= k){
            mxdif = min(mxdif, dif[i - k]);
            if(dif[i] > mxdif) return 1;
        }
    }
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for1(i, 1, n){
        cin >> b[i];
    }
    int l = 1; int r = n;
    while(l != r){
        int mid = (l + r) / 2;
        mid = (l + r) - mid;
        if(ofc(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}