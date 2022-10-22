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
int k;
set<int> st;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> k;
        st.clear();
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            st.insert(a[i]);
        }
        int choke = 1;
        sort(a + 1, a + n + 1);
        for(int i = 1; i < n; i++){
            if(a[i] != i - 1) choke = 0;
        }
        if(choke && (a[n] == n - 1)){
            cout << n + k << endl;
            continue;
        }
        int mk;
        for(int i = 0; i <= n; i++){
            if(st.find(i) == st.end()){
                mk = i; break;
            }
        }
        if(k > 0) st.insert((*st.rbegin() + mk + 1) / 2);
        cout << st.size() << endl;
        // if(n == 3 && k == 0){
        //     for(a)
        // }
    }
}