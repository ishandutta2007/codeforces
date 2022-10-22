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
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int mn[55];
int col;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int o;
    cin >> o;
    for(int i = 0; i < 55; i++) mn[i] = mod;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mn[a[i]] = min(mn[a[i]], i);
    }
    while(o--){
        cin >> col;
        cout << mn[col] << " ";
        for(int i = 1; i <= 50; i++){
            if(mn[i] < mn[col]) mn[i]++;
            // cout << mn[i] << " ";
        }
        // cout << endl;
        mn[col] = 1;
    }
}