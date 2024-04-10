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
int n; char c; int c0, c1, h;
bool s[maxN]; int cnt1, cnt0;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> c0 >> c1 >> h; cnt1 = 0; cnt0 = 0; int ans;
        for(int i = 1; i <= n; i++){
            cin >> c;
            if(c == 49) cnt1++;
            else cnt0++;
        }
        if(c0 > c1){
            swap(c0, c1); swap(cnt1, cnt0);
        }
        
        // c0 < c1
        if(h <= c1 - c0){
            cout << c0 * n + h * cnt1 << endl; continue;
        }
        cout << c0 * cnt0 + c1 * cnt1 << endl;
    }
}