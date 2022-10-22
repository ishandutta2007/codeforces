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
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n; ll a[maxN]; ll wei; ll dup; ll sum; vector<int> ray;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> wei; bool sign = 0; sum = 0;
        ray.clear();
        dup = (wei + 1) / 2;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            if(a[i] > wei) continue;
            else if(a[i] <= wei && a[i] >= dup){
                cout << "1\n" << i << endl; sign = 1; break;
            }
            else{
                sum = sum + a[i];
                ray.pb(i);
            }
            if(sum > dup) break;
        }
        if(sign) continue;
        if(sum < dup){
            cout << "-1\n"; continue;
        }
        cout << ray.size() << endl;
        for(int i = 0; i < ray.size(); i++){
            cout << ray[i] << " ";
        }
        cout << endl;
    }
}