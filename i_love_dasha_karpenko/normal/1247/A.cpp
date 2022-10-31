#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 1007;
const ll INF = 10E16;
#define forn(i,n) for(ll i = 0;i<n;i++)
#define pb push_back
#define fi first
#define sc second
#define endl '\n'
const bool operator<(const pp &a,const pp &b){
    if (a.fi==b.fi)return a.sc<b.sc;
    return a.fi<b.fi;
}
const bool operator>(const pp &a,const pp &b){
    if (a.fi==b.fi)return a.sc>b.sc;
    return a.fi>b.fi;
}
const bool operator==(const pp &a,const pp &b){
    return a.fi==b.fi && a.sc==b.sc;
}
ll a,b;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>a>>b;
    if (a==9 && b==1) {
        cout << 9 << ' ' << 10 << endl;
        return 0;
    }

    if (a>b || b-a>=2){
        cout<<-1<<endl;
        return 0;
    }
    if (a==b)cout<<a*10+1<<' '<<b*10+2<<endl;
    else cout<<a*10+9<<' '<<b*10<<endl;
    return 0;
}