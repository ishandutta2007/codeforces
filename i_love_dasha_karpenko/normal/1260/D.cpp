#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pp;
const ll DIM = 200007;
const ll INF = 10E16;
struct node{
    ll l,r,d;
};
bool const operator<(const node &a,const node &b){
    return a.l<b.l;
}
ll n,m,k,t,A[DIM];
node T[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>t;
    forn(i,n)cin>>A[i];
    forn(i,k){
        cin>>T[i].l>>T[i].r>>T[i].d;
    }
    sort(T+1,T+1+k);
    sort(A+1,A+1+n,greater<ll>());
    ll l = 0,r = n,cost;
    while(l!=r){
        ll tm = (l+r+1)/2;
        ll power = A[tm];
        ll squad_pos = 0,hero_pos = 0;cost = 0;
        forn(i,k){
            cost+=abs(T[i].l-1-hero_pos);
            hero_pos = squad_pos = T[i].l-1;
            if (T[i].d>power){
                cost+=abs(T[i].r-hero_pos);
                hero_pos = T[i].r;
            }
            while(i<k && hero_pos>=T[i+1].l){
                i++;
                if (T[i].d<=power)continue;
                if (hero_pos<T[i].r){
                    cost+=T[i].r-hero_pos;
                    hero_pos=  T[i].r;
                }
            }
            cost+=2*(hero_pos-squad_pos);
            squad_pos = hero_pos;
        }
        cost+=2*(hero_pos-squad_pos);
        squad_pos = hero_pos;
        cost+=(m+1-squad_pos);
        if (cost>t)r = tm-1;
        else l = tm;
    }

    cout<<l<<endl;
    return 0;
}