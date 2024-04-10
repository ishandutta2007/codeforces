#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_bac
#define fi first
#define se second
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k, p;
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    cin >> n >> k;
    int l = 1;
    int r = n;
    string s;
    while(1){
        int mid = (l + r) / 2;
        cout << l << " " << mid << endl;
        cin >> s;
        if(s[0] == 'B') return 0;
        if(s[0] == 'Y') r = mid;
        else            l = mid + 1;
        l = max(l - k, 1ll);
        r = min(r + k, n);
        int h1 = (int)(rand()) * (int)(rand());
        if(h1 < 0) h1 += oo;
        h1 = h1 % (r - l + 1) + l;
        cout << h1 << " " << h1 << endl;
        cin >> s;
        if(s[0] == 'B') return 0;
        if(s[0] == 'Y') return 0;
        l = max(l - k, 1ll);
        r = min(r + k, n);
    }
}