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
int n, a[maxN], k; vector<int> vc;
signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> k; vc.clear();
        for(int i = 1; i < 2 * k - n; i++) cout << i << " ";
        for(int i = 2 * k - n; i <= k; i++){ cout << 3 * k - n - i << " ";
            
        }
        //for(int i = 2 * k - n + 1; i <= k; i++) cout << i << " ";
        cout << endl;
    }
}