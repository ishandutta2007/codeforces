#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
const ll DIM = 400000+7;
const ll INF = 10e16;
ll A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n; cin>>n;
        forn(i,n)cin>>A[i];

        ll cnt1 = 1,cnt2 = 0,cnt3 = 0;
        ll i = 1;
        while(i<n && A[i]==A[i+1]){
            i++;cnt1++;
        }
        while(cnt1>=cnt2){
            i++;
            cnt2++;
            if (i>n)break;
            while(i<n && A[i]==A[i+1]){
                i++;
                cnt2++;
            }
        }
        while(cnt3>=cnt1){
            i++;
            cnt3++;
            if (i>n)break;
            while(i<n && A[i]==A[i+1]){
                i++;
                cnt3++;
            }
        }
        ll res = cnt1+cnt2+cnt3;
        while(i<=n/2){
            ll ncnt = cnt3+1;
            i++;
            while(A[i]==A[i+1]){
                ncnt++;
                i++;
            }
            if (i<=n/2){
                res-=cnt3;
                res+=ncnt;
                cnt3 = ncnt;
            }
        }
        if (cnt1<cnt2 && cnt1<cnt3 && cnt1!=0 && cnt2!=0 && cnt3!=0 && cnt1+cnt2+cnt3<=n/2)
        cout<<cnt1<<' '<<cnt2<<' '<<cnt3<<endl;
        else cout<<"0 0 0"<<endl;
    }

    return 0;

}