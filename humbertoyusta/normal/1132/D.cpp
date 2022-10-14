#include<bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define lg2(x) 31 - __builtin_clz(x)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> par;

struct two{
    ll f,s,t;
    bool operator < ( const two & other ) const {
        return t > other.t;
    }
};

int n,m;
par a[maxn];

bool can(ll ch){
    priority_queue<two> q;

    for(int i=1; i<=n; i++)
        q.push(two{a[i].f,a[i].s,a[i].f/a[i].s});

    for(ll i=1; i<m; i++){
        two a = q.top(); q.pop();
        if( (a.f-a.s*i+ch) < 0 ) return false;
        if(n>=2){
            two b = q.top();
            if( (b.f-b.s*i) < 0 ) return false;
        }
        q.push(two{a.f+ch,a.s,i+(a.f-a.s*i+ch)/a.s});
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w".stdout);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        cin >> a[i].f;
    for(int i=1; i<=n; i++)
        cin >> a[i].s;

    ll l = 0 , r = 2000000000000;
    while( l < r ){
        ll mi = ( l + r ) / 2;
        if( can(mi) ) r = mi;
            else l = mi + 1;
    }
    if( !can(l) ) l--;

    if( l >= 2000000000000ll - 1ll ) cout << -1;
        else cout << l;

    return 0;
}