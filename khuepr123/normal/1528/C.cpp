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
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

vector<int> v1[maxN];
vector<int> v2[maxN];

int ans;
int in[maxN];
int out[maxN];
int cnt;
set<ii> st;

void df1(int node){
    ii pr = ii(in[node], out[node]);
    ii user;
    int useless = 0;
    user = *st.upper_bound(pr);
    if(user.se < pr.se) useless = 1;
    else{
        st.insert(pr);
        user = *(--st.lower_bound(pr));
        if(user.se > pr.se){
            useless = 2; st.erase(user);
        }
    }
    x = st.size();
    ans = max(ans, x);
    for(int child : v1[node]){
        df1(child);
    }
    if(useless != 1){
        st.erase(pr);
        if(useless == 2) st.insert(user);
    }
}

void df2(int node){
    in[node] = ++cnt;
    for(int child : v2[node]) df2(child);
    out[node] = ++cnt;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    st.insert(ii(-1, 0));
    st.insert(ii(maxN * 3, maxN * 3 + 1));
    while(o--){
        cin >> n;
        ans = 0;
        cnt = 0;
        for1(i, 1, n){
            v1[i].clear();
            v2[i].clear();
        }
        for1(i, 2, n){
            cin >> x; v1[x].pb(i);
        }
        for1(i, 2, n){
            cin >> x; v2[x].pb(i);
        }
        df2(1);
        df1(1);
        cout << ans - 2 << endl;
    }
}