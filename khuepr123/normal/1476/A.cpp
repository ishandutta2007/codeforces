#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
bool chk[maxN];



signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n;
        int k; cin >> k;
        if(k >= n){
            if(k % n == 0) cout << k / n << endl;
            else cout << (k / n) + 1 << endl;
        }
        else{
            if(n % k == 0) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
}