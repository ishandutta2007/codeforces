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
ll n;
vector<int> vc;
int cnt;


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; vc.clear(); cnt = -1;
        if(n % 2){
            cout << "-1\n"; continue;
        }
        n /= 2;
        while(n){
            cnt++;
            if(n % 2 == 0){n = n / 2;continue;}
            n = n / 2;
            vc.pb(1);
            
            for(int i = 0; i < cnt - 1; i++){
                vc.pb(0);
            }
            vc.pb(1);
            if(cnt == 0) vc.pop_back();
        }
        cout << vc.size() << endl;
        for(int i = 0; i < vc.size(); i++){
            cout << vc[i] << " ";
        }
        cout << endl;
    }
}