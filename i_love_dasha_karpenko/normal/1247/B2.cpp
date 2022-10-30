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
ll t,n,k,d,A[200007],col[1000007],cnt = 0;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    forn(query,t){
        cin>>n>>k>>d;
        
        forn(i,n){
            cin>>A[i];
            col[A[i]] = 0;
        }
        ll res = INF;
        cnt = 0;
        forn(i,n){
            if (col[A[i]]==0)cnt++;
            col[A[i]]++;
            if (i>=d){
                col[A[i-d]]--;
                if (col[A[i-d]]==0)cnt--;
            }
            if (i>=d-1){
                res = min(res,cnt);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}