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
void typre(){
    for(int i = 0; i <= n + 3; i++){
        chk[i] = 0;
    }
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        vector<int> vc;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        a[0] = -1;
        for(int i = 1; i <= n; i++){
            if(a[i] != a[i - 1])cout << a[i] <<  " ";
            else vc.pb(a[i]);
        }
        for(auto i : vc){
            cout << i << " ";
        }
        cout << endl;
    }
}