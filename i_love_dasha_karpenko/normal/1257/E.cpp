#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll DIM = 200000+7;
const ll INF = 10e16;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)

ll k1,k2,k3,prefval[DIM],sufval[DIM],cntpure[DIM],cntfi[DIM];
vector<ll> A1,A2,A3;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>k1>>k2>>k3;
    ll n = k1+k2+k3;
    A1.resize(k1+5); A2.resize(k2+5); A3.resize(k3+5);
    forn(i,k1)cin>>A1[i];
    sort(A1.begin()+1,A1.begin()+1+k1);
    forn(i,k2)cin>>A2[i];
    sort(A2.begin()+1,A2.begin()+1+k2);
    forn(i,k3)cin>>A3[i];
    sort(A3.begin()+1,A3.begin()+1+k3);
    ll cnt = 0,p = 1;
    forn(i,n){
        if(p<=k3 && A3[p]==i){
            cnt++;
            p++;
        }
        prefval[i] = cnt;
    }
    p = k3,cnt = 0;
    cntpure[n+1] = k3;

    for(ll i = n;i>=0;i--){
        if (p>=1 && A3[p]==i){
            p--;
            cnt++;
        }
        cntpure[i] = (n-i+1)-cnt+k3-cnt;
    }
    cnt = 0; p = 1;
    forn(i,n){
        if (p<=k1 && A1[p]==i){
            cnt++;
            p++;
        }

        cntfi[i] = i-cnt+k1-cnt;
    }
    p = k1; cnt = 0;
    for(ll i = n;i>=1;i--){
        if (p>=1 && A1[p]==i){
            cnt++;
            p--;
        }
        sufval[i] = cnt;
    }
    ll mi = INF,res = INF;
    cntfi[0] = k1;
    for(ll i = n;i>=0;i--){
        ll imp = prefval[i];
        mi = min(cntpure[i+1]-sufval[i+1],mi);
        res = min(res,mi+cntfi[i]-imp);
    }
    res = min(res,k1+k3);
    cout<<res<<endl;
    return 0;
}