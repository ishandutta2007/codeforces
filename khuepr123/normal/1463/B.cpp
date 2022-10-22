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
const int maxN = 100005;
const ll oo = 1e18 + 7;

int n; int a[maxN];
signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    int s;
    while(o--){
        cin >> n; s = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s = 1;
            for(int j = 1; j <= 100; j++){
                if(abs(a[i] - s) <= a[i] / 2) break;
                s = s * 2;
            }
            // cout << a[i] << " ";
            cout << s << " ";
        }
        cout << endl;
    }
}