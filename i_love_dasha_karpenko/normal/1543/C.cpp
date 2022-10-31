#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
const int DIM = 2E5+7;
typedef pair<pair<ll,ll>,ll> node;
ld eps = 0.000001;
ll MULT = 10000000;
int solve(){

    ld cd,md,p,vd;
    cin>>cd>>md>>p>>vd;
    ll c = cd*MULT,m = md*MULT,v = vd*MULT;
    queue<node> Q;
    map<node,ld> M;
    node start = {{c,m},1};
    M[start] = 1.0;
    ld res = 0;
    Q.push(start);
    while(!Q.empty()){
        pair<ll,ll> cur = Q.front().first;
        ll st = Q.front().second;
        Q.pop();
        ld prob = M[{cur,st}];
        ll out = ld(MULT-cur.first-cur.second);
        res+=ld(out*prob*st)/MULT;
        if (cur.first==0 && cur.second==0)
            continue;
        if (cur.first==0){
            node nw = {{cur.first,max(ll(0),cur.second-v)},st+1};
            if (M.count(nw)==0)
                Q.push(nw);
            M[nw]+=prob*cur.second/MULT;

        }
        else if (cur.second==0){
            node nw = {{max(ll(0),cur.first-v),cur.second},st+1};
            if (M.count(nw)==0)
                Q.push(nw);
            M[nw]+=prob*cur.first/MULT;

        }
        else{
            {
                ll val = min(v,cur.first);
                node nw = {{max(ll(0),cur.first-v),cur.second+val/2},st+1};
                if (M.count(nw)==0)
                    Q.push(nw);
                M[nw]+=prob*cur.first/MULT;

            }
            {
                ll val = min(v,cur.second);
                node nw = {{cur.first+val/2,max(ll(0),cur.second-v)},st+1};
                if (M.count(nw)==0)
                    Q.push(nw);
                M[nw]+=prob*cur.second/MULT;

            }
        }
    }
    cout<<fixed<<setprecision(10)<<res<<endl;
    return 1;
}
int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}