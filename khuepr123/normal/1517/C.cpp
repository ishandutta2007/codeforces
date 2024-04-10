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
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
vector<int> vc[505];
int x, y, z, k;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int m = n;
    while(m){
        bool toggle = 0;
        for(int i = m; i > 0; i--){
            vc[m + 1 - i].pb(a[i]);
        }
        for(int i = 1; i < m; i++){
            if(a[i] == n - m + 1) toggle = 1;
            if(toggle) a[i] = a[i + 1];
        }
        m--;
    }
    for(int i = n; i > 0; i--){
        reverse(vc[i].begin(), vc[i].end());
        for(auto j : vc[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}