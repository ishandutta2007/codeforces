#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 10E4 +7;
const ll INF = 10E17;

ll n,A[DIM],B[DIM],ptr = 1;
pp lines[DIM];
ld intersect(pp line_1,pp line_2){
    return ld(line_2.sc-line_1.sc)/(line_1.fi-line_2.fi);
}
void addline(ll k,ll b){
    pp line = {k,b};
    while(ptr>2){
        if (intersect(lines[ptr-2],line)>intersect(lines[ptr-2],lines[ptr-1]))break;
        ptr--;
    }
    lines[ptr] = line;
    ptr++;
}
ll getval(pp line,ll val){
    return line.sc+line.fi*val;
}
ll get(ll val){
    ll l = 1,r = ptr-1;
    while(l!=r){
        ll mid = (l+r)/2;
        if (getval(lines[mid],val)<getval(lines[mid+1],val))r = mid;
        else l = mid+1;
    }
    return getval(lines[r],val);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n)cin>>A[i];
    forn(i,n)cin>>B[i];
    addline(B[1],0);
    ll d;
    for(ll i = 2;i<=n;i++){
        d = get(A[i]);
        addline(B[i],d);
    }
    cout<<d<<endl;
    return 0;
}