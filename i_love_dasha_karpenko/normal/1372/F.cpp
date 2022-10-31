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
//#define endl '\n'
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
    pp fi,sc;
};
pp ask(ll l,ll r){
    cout<<"? "<<l<<' '<<r<<endl;
    ll x,f;
    cin>>x;
    if (x==-1)exit(0);
    cin>>f;
    return {x,f};
}
queue<node> Q;
void add(ll l,ll r){
    if (l>r)return;
    pp x = ask(l,r);
    Q.push({{l,r},x});
}
ll A[DIM];
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    pp x = ask(1,n);

    Q.push({{1,n},x});
    while(!Q.empty()){
        node t = Q.front();
        Q.pop();
        if (t.sc.sc==t.fi.sc-t.fi.fi+1){
            for(ll i = t.fi.fi;i<=t.fi.sc;++i)A[i] = t.sc.fi;
            continue;
        }
        ll tm = (t.fi.fi+t.fi.sc)/2;
        pp q1 = ask(t.fi.fi,tm);
        pp q2 = ask(tm+1,t.fi.sc);
        if (q1.fi==t.sc.fi && (q1.sc!=t.sc.sc || q1.sc==tm+1-t.fi.fi)){
            ll dif = t.sc.sc-q1.sc;
            for(ll i = tm-q1.sc+1;i<=tm+dif;++i)A[i] = q1.fi;

            add (t.fi.fi,tm-q1.sc);
            if (dif>0)
                add(tm+1+dif,t.fi.sc);
            else Q.push({{tm+1,t.fi.sc},q2});
        }
        else if (q2.fi==t.sc.fi && (q2.sc!=t.sc.sc || q2.sc==t.fi.sc-tm)){
            ll dif = t.sc.sc-q2.sc;
            for(ll i = tm-dif+1;i<=tm+q2.sc;++i)A[i] = q2.fi;
            if (dif>0)
                add(t.fi.fi,tm-dif);
            else Q.push({{t.fi.fi,tm},q1});
            add(tm+q2.sc+1,t.fi.sc);
        }
        else{
            Q.push({{t.fi.fi,tm},q1});
            Q.push({{tm+1,t.fi.sc},q2});
        }
    }
    cout<<"! ";
    forn(i,n)cout<<A[i]<<' ';
    cout<<endl;
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