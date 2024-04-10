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
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, k;
int cnta[maxN]; int cntb[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o; int store;
    while(o--){
        for(int i = 0; i < 30; i++){
            cnta[i] = 0; cntb[i] = 0;
        }
        bool choke = 0;
        store = 0;
        cin >> n >> k; char c;
        for(int i = 1; i <= n; i++){
            cin >> c;
            cnta[c - 96]++;
        }
        for(int i = 1; i <= n; i++){
            cin >> c;
            cntb[c - 96]++;
        }
        for(int i = 1; i <= 26; i++){
            if((cnta[i] + store < cntb[i]) || ((cntb[i] - cnta[i]) % k != 0)){
                choke = 1; break;
            }
            
            store = store + cnta[i] - cntb[i];
        }
        if(choke) cout << "NO";
        else cout << "YES";
        cout << endl;
    }
}