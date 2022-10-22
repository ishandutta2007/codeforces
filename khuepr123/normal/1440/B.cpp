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
#define int long long
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, k; int a[maxN]; int bg;


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> k; int sum = 0;
        bg = n * k;
        for(int i = 1; i <= n * k; i++){
            cin >> a[i];
        }
        int dup = n / 2; dup++;
        bg++;
        bg -= dup;
        while(k--){
            sum = sum + a[bg];
            bg = bg - dup;
        }
        cout << sum << endl;
    }
}