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

set<int> st;
int pre[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; st.clear();
        pre[0] = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
            
        }
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                st.insert(a[j] - a[i]);
            }
        }
        cout << st.size();
        cout << endl;
        
    }
}