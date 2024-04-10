#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 2E5+7;
const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

struct node{
    ll fi,sc,pos;
};
const bool operator<(const node &a,const node &b){
    if (a.fi==b.fi)return a.sc<b.sc;
    return a.fi<b.fi;
}
ll pref[4][DIM];
vector<pp> V[4];
node A[DIM];
ll sum[DIM],cnt[DIM][4];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;

    forn(i,n){
        ll t,a,b;
        cin>>t>>a>>b;
        ll ps = a*2+b;
        A[i] = {t,ps,i};
        V[ps].pb({t,i});

    }
    for(ll i = 0;i<4;++i){
        sort(V[i].begin(),V[i].end());
        ll sum = 0;
        for(ll j = 0;j<V[i].size();++j){
            sum+=V[i][j].fi;
            pref[i][j+1] = sum;
        }
    }
    sort(A+1,A+1+n);
    forn(i,n){
        for(ll j = 0;j<=4;++j)
        cnt[i][j] = cnt[i-1][j];
        cnt[i][A[i].sc]++;
        sum[i]= sum[i-1]+A[i].fi;
    }
    ll res = INF;
    ll p1,p2,p3,p4;
    for(ll i = 0;i<=k;++i){
        ll l = 0,r = n;
        ll Aa[4];
        Aa[0] = 0;
        Aa[1] = k-i;
        Aa[2] = k-i;
        Aa[3] = i;
        ll need = m-k*2+i;
        if (need<0)continue;
        while(l!=r){
            ll ct = 0;
            ll tm = (l+r)/2;
            for(ll j = 0;j<4;++j){
                ct+=max(0ll,cnt[tm][j]-Aa[j]);
            }
            if (ct>=need)r = tm;
            else l = tm+1;
        }
        ll ss = sum[l],flag = 0;
        for(ll j = 0;j<4;++j){
            Aa[j] = max(Aa[j],cnt[l][j]);
            if (Aa[j]>V[j].size()){
                flag = 1;
                break;
            }
            ss+=pref[j][Aa[j]]-pref[j][cnt[l][j]];
        }
        if (flag)continue;
        if (ss<res){
            res = ss;
            p1 = Aa[0];
            p2 = Aa[1];
            p3 = Aa[2];
            p4 = Aa[3];
        }
    }
    if (res==INF)cout<<"-1\n";
    else{
        cout<<res<<endl;
        for(ll i = 0;i<p1;++i)cout<<V[0][i].sc<<' ';
        for(ll i = 0;i<p2;++i)cout<<V[1][i].sc<<' ';
        for(ll i = 0;i<p3;++i)cout<<V[2][i].sc<<' ';
        for(ll i = 0;i<p4;++i)cout<<V[3][i].sc<<' ';
        cout<<endl;
    }
    return 0;
}
// (i-1)%p
// l = A[i],r = A[i+1]
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,