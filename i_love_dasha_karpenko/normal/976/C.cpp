#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 300007;
const ll INF = 10000000007;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
struct node{
    ll fi,sc,pos;
};
ll n;
node A[DIM];
bool mc(node a,node b){
    if (a.fi==b.fi)return a.sc>b.sc;
    return a.fi<b.fi;
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n){
        cin>>A[i].fi>>A[i].sc;
        A[i].pos = i;
    }
    sort(A+1,A+1+n,mc);
    ll cur = 0,last = 0;

    for(ll i = 1;i<=n;i++){
        if (A[i].fi>last){
            last = A[i].sc;
            cur = A[i].pos;
        }
        else if (A[i].sc<=last){
            cout<<A[i].pos<<' '<<cur<<endl;
            return 0;
        }
        else{
            last = A[i].sc;
            cur = A[i].pos;
        }
    }
    cout<<"-1 -1\n";
    return 0;
}