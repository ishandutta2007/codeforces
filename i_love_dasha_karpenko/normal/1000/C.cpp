#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 200007;
const ll INF = 10000000007;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
struct node{
    ll fi,sc,pos;
};
ll n,cnt[DIM];
pp A[DIM*2];
bool mc(pp a,pp b){
    if (a.fi==b.fi)return a.sc>b.sc;
    return a.fi<b.fi;
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    ll all = 1;
    forn(i,n){
        ll x,y;
        cin>>x>>y;
        A[all++]= {x,1};
        A[all++] = {y,-1};
    }
    //A[all] = {n,-2};
    //all++;
    sort(A+1,A+all,mc);
    ll last = 0,num = 0;
    for(ll i = 1;i<all;i++){
        if (A[i].sc==-1){
            cnt[num] += (A[i].fi-last+1);
            last = A[i].fi+1;
        }
        else {cnt[num] += (A[i].fi-last);

        last = A[i].fi;
        }
        num+=A[i].sc;
    }
    forn(i,n)cout<<cnt[i]<<' ';
    cout<<endl;

    return 0;
}