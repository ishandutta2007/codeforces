#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
#define x1 dsfdsfes
#define y1 sfsdfdse
#define po(x) (1ll<<x)
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 10E4+107;
const ll INF = 10E17;
const ll MAXN = DIM-5;
struct node{
    ll fi,sc,th;
};
ll n,w,h,com[DIM];
pp en[DIM];
vector<pp> A[2][DIM*2];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>w>>h;

    forn(i,n){
        ll g,p,t; cin>>g>>p>>t;
        g--;
        A[g][MAXN+p-t].pb({p,i});
        if (g==0)en[i] = {p,h};
        else en[i] = {w,p};
    }
    forn(i,DIM*2-1){
        if (A[0][i].size()*A[1][i].size()==0)continue;
        sort(A[0][i].begin(),A[0][i].end());
        sort(A[1][i].begin(),A[1][i].end());
        for(ll k = 0;k<2;k++){
            ll p = -1,flag = 0;
            for(ll j = ll(A[k][i].size())-1;j>=0ll;j--){
                if (flag==0)p++;
                else p--;
                if (p>=A[k^1][i].size() && flag==0){
                    p = A[k][i].size()-1;
                    flag = 1;
                }
                //if (flag==1 && p-j>A[k^1][i].size())break;
                if (flag==1)com[A[k][i][j].sc] = A[k][i][p].sc;
                else com[A[k][i][j].sc] = A[k^1][i][p].sc;
            }
        }
    }
    forn(i,n){
        if (com[i]==0)com[i] = i;
        //cout<<com[i]<<endl;
        cout<<en[com[i]].fi<<' '<<en[com[i]].sc<<endl;
    }
    return 0;
}