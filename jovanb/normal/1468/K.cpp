#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define fb(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define mod 998244353
#define xx first
#define yy second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define ll long long
#define pii pair<int,int>


using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;/// find_by_order(x)(x+1th) , order_of_key() (strictly less)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());



int n;
string x;


void solve(){
    cin >> x;
    n = x.length();
    vector<pii> p;
    pii tr = {0,0};
    ff(i,0,n - 1){
        if(x[i] == 'L')tr.xx--;
        if(x[i] == 'R')tr.xx++;
        if(x[i] == 'U')tr.yy++;
        if(x[i] == 'D')tr.yy--;
        p.pb(tr);
    }
    p.pb({1e9,1e9});
    for(auto c:p){
        if(c.xx == 0 && c.yy == 0)continue;
        tr = {0,0};
        ff(i,0,n - 1){
            pii nxt = tr;
            if(x[i] == 'L')nxt.xx--;
            if(x[i] == 'R')nxt.xx++;
            if(x[i] == 'U')nxt.yy++;
            if(x[i] == 'D')nxt.yy--;
            if(nxt == c)nxt = tr;
            tr = nxt;
        }
        if(tr.xx == 0 && tr.yy == 0){
            cout << c.xx << " " << c.yy << "\n";
            return;
        }
    }
    cout << "0 0" << "\n";
}


int main()
{

    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}