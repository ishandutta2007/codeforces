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
int x, y, z, k;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) a[i] = i;
        for(int i = n; i > 2; i -= 2){
            if(k){
                swap(a[i], a[i - 1]);
                k--;
            }
        }
        if(k) cout << "-1\n";
        else{
            for(int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << endl;
        }
    }
}