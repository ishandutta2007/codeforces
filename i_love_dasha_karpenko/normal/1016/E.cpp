//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e5+7;
const ll INF = 1E18;
ll sy,a,b,pref[N];
pair<ll,ll> A[N];
void solve(){
    cin>>sy>>a>>b;
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>A[i].first>>A[i].second;
    for(int i = 1;i<=n;++i){
        pref[i] = pref[i-1]+A[i].second-A[i].first;
    }
    int q;
    cin>>q;
    while(q--){
        ll x,y;
        cin>>x>>y;
        ld cof = ld(-y)/(sy-y);
        ld xl = ld(x)+ld(a-x)*cof;
        ld xr = ld(x)+ld(b-x)*cof;
        int pos_l = lower_bound(A+1,A+1+n,pair<ll,ll>{ceil(xl),0})-A;
        int pos_r = lower_bound(A+1,A+1+n,pair<ll,ll>{ceil(xr),0})-A;
        pos_l = max(1,pos_l-3);
        pos_r = min(pos_r+3,n);
        ld res = 0;
        while(pos_l<=n && ld(A[pos_l].second)<xl){
            ++pos_l;
        }
        while(pos_r>=1 && ld(A[pos_r].first)>xr){
            --pos_r;
        }
        if (pos_l==pos_r){
            pair<ld,ld> segm = A[pos_l];
            segm.first = max(segm.first,xl);
            segm.second = min(segm.second,xr);
            res+=max(ld(0),segm.second-segm.first)/cof;
        }
        else if (pos_l<pos_r){
            pair<ld,ld> segm = A[pos_l];
            segm.first = max(segm.first,xl);
            res+=max(ld(0),segm.second-segm.first)/cof;
            segm = A[pos_r];
            segm.second = min(segm.second,xr);
            res+=max(ld(0),segm.second-segm.first)/cof;
            if (pos_r-1>=pos_l+1)
                res+=(pref[pos_r-1]-pref[pos_l])/cof;
        }



        cout<<fixed<<setprecision(10)<<res<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}