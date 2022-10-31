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
const ll DIM = 10E4+7;
const ll INF = 10E17;

ll A[DIM];
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    forn(q,t){
        ll n,k;
        cin>>n>>k;
        ll sum = 0;

        forn(i,n){
            char ch; cin>>ch;
            A[i] = ch-'0';
            if (k<0)A[i]^=1;
            if (A[i]==0)sum++;
            else sum--;
        }
        if (k<0)k*=-1;
        ll cnt = 0,res = 0;
        forn(i,n){
            if (A[i]==0)cnt++;
            else cnt--;
            if (sum==0 && cnt==k)res++;
            else if (sum<0){
                if (k<=cnt && (k-cnt)%sum==0)res++;
            }
            else if (sum>0 && k-cnt>=0 && (k-cnt)%sum==0)res++;
        }
        if (0==k)res++;


        if (sum==0 && res!=0){
            cout<<"-1\n";
        }
        else cout<<res<<endl;
    }
    return 0;
}