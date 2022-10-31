//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E6+7;
struct node{
    ll x,y,a;
};
node A[DIM];
bool mc(node &a,node &b){
    return a.x<b.x;
}
struct line{
    ll k,b; // y = k*x+b
    ll val(ll x){
        return k*x+b;
    }
};
vector<line> hull;
ll get(ll x){
    if (hull.empty())return 0;
    ll l = 0,r = hull.size()-1;
    while(l!=r){
        ll tm = (l+r)/2;
        if (hull[tm].val(x)>hull[tm+1].val(x))r = tm; // no tm==hull.size()-1 case
        else l = tm+1;
    }
    return max(0ll,hull[l].val(x));
}
ld intersect(line a,line b){
    // k1*x+b1 == k2*x+b2;
    // x*(k1-k2) = b2-b1
    return ld(b.b-a.b)/(a.k-b.k);
}
void add(line a){
    while(hull.size()>=2){
        ll sz = hull.size()-1;
        if (intersect(hull[sz-1],a)<intersect(hull[sz-1],hull[sz]))break; // adding lines to begining, hull order reversed
        hull.pop_back();
    }
    hull.push_back(a);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i){
        cin>>A[i].x>>A[i].y>>A[i].a;
    }
    sort(A+1,A+1+n,mc);
    ll res = 0;
    for(ll i = 1;i<=n;++i){
        A[i].a=A[i].x*A[i].y+get(A[i].y)-A[i].a; // dp[i]
        res = max(res,A[i].a);
        add({-A[i].x,A[i].a}); // no subrectangles, staited in statement
    }
    cout<<res<<endl;
    return 0;
}