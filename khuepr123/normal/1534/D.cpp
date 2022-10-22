#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
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

set<ii> st;

void past(int i, int j){
    if(i > j) swap(i, j);
    st.insert(ii(i, j));
}

void solve(int node, vector<ii> dumb){
    int ind = 0;
    int mx = 0;
    for(ii chime : dumb){
        int i = chime.fi;
        int j = chime.se;
        if(mx < j){
            mx = j;
            ind = i;
        }
    }
    if(mx <= 1){
        for(ii chime : dumb){
            int i = chime.fi;
            int j = chime.se;
            past(node, i);
        }
    }
    else{
        vector<int> arr(n + 1);
        cout << "? " << ind << endl;
        vector<int> head(mx + 1);
        vector<ii> fool[mx + 1];
        head[mx] = ind;
        head[0] = node;
        for1(i, 1, n){
            cin >> arr[i];
        }
        for(ii chime : dumb){
            int i = chime.fi;
            int j1 = chime.se;
            int j2 = arr[i];
            int ran = (j1 + j2 - mx) / 2;
            int ds = j1 - ran;
            x++;
            if(ran == 0) head[ds] = i;
            else{
                fool[ds].pb(ii(i, ran));
            }
        }
        for1(i, 0, mx){
            if(i) past(head[i], head[i - 1]);
            solve(head[i], fool[i]);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cout << "? 1" << endl;
    vector<ii> dumb;
    cin >> x;
    for1(i, 2, n){
        cin >> x;
        dumb.pb(ii(i, x));
    }
    solve(1, dumb);
    cout << "!" << endl;
    for(ii child : st){
        if(child.fi <= n && child.se <= n)
        cout << child.fi << " " << child.se << endl;
    }

}