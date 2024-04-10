#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 100  +7;
const ll INF = 10E10;
ll A[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    ll cnt1 = n/2+n%2,cnt2 = n/2,res = 0;
    forn(i,n){
        cin>>A[i];
        if (A[i]==0)continue;
        if (A[i]%2==0)cnt2--;
        else cnt1--;
        if(A[i-1]!=0 && (A[i]%2)!=(A[i-1]%2))res++;
    }
    vector<ll> N[2];
    vector<pp> E;
    ll cnt = 0,st = -1;
    forn(i,n){
        if (A[i]==0)cnt++;
        else {
            if (cnt>0){
                if (st==-1)E.pb({cnt,A[i]%2});
                else if (st==A[i]%2) N[st].pb(cnt);
                //res++;
                res++;
            }
            cnt = 0;
            st = A[i]%2;

        }
    }
    if (cnt>0){
        if (st==-1){
            if (n==1)cout<<"0\n";
            else cout<<"1\n";
            return 0;
        }
        E.pb({cnt,st});
        res++;
    }
    ll ans = INF;
    vector<ll> C[2];

    ll re = 0,c1 = cnt1,c2 = cnt2;
    sort(N[0].begin(),N[0].end(),greater<ll>());
    sort(N[1].begin(),N[1].end(),greater<ll>());
    C[0] = N[0];
    C[1] = N[1];
    while(!N[0].empty()){
        ll to = N[0].back();
        if (to>cnt2)break;
        cnt2-=to;
        re++;
        N[0].pop_back();
    }
    while(!N[1].empty()){
        ll to = N[1].back();
        if (to>cnt1)break;
        cnt1-=to;
        re++;
        N[1].pop_back();
    }
    ans = min(ans,res-re+N[0].size()+N[1].size());
    if (E.size()>0){
        re = 0;
        cnt1 = c1; cnt2 = c2;
        N[0] = C[0];
        N[1] = C[1];
        if (E[0].sc==1)cnt1-=E[0].fi;
        else cnt2-=E[0].fi;
        if (cnt1>=0 && cnt2>=0){
            while(!N[0].empty()){
                ll to = N[0].back();
                if (to>cnt2)break;
                cnt2-=to;
                re++;
                N[0].pop_back();
            }
            while(!N[1].empty()){
                ll to = N[1].back();
                if (to>cnt1)break;
                cnt1-=to;
                re++;
                N[1].pop_back();
            }
            ans = min(ans,res-re+N[0].size()+N[1].size()-1);
        }
    }
    if (E.size()>1){
        N[0] = C[0];
        N[1] = C[1];
        re = 0;
        cnt1 = c1; cnt2 = c2;
        if (E[1].sc==1)cnt1-=E[1].fi;
        else cnt2-=E[1].fi;
        if (cnt1>=0 && cnt2>=0){
            while(!N[0].empty()){
                ll to = N[0].back();
                if (to>cnt2)break;
                cnt2-=to;
                re++;
                N[0].pop_back();
            }
            while(!N[1].empty()){
                ll to = N[1].back();
                if (to>cnt1)break;
                cnt1-=to;
                re++;
                N[1].pop_back();
            }
            ans = min(ans,res-re+N[0].size()+N[1].size()-1);
        }
    }
    if (E.size()>1){
        N[0] = C[0];
        N[1] = C[1];
        re = 0;
        cnt1 = c1; cnt2 = c2;
        if (E[0].sc==1)cnt1-=E[0].fi;
        else cnt2-=E[0].fi;
        if (E[1].sc==1)cnt1-=E[1].fi;
        else cnt2-=E[1].fi;
        if (cnt1>=0 && cnt2>=0){
            while(!N[0].empty()){
                ll to = N[0].back();
                if (to>cnt2)break;
                cnt2-=to;
                re++;
                N[0].pop_back();
            }
            while(!N[1].empty()){
                ll to = N[1].back();
                if (to>cnt1)break;
                cnt1-=to;
                re++;
                N[1].pop_back();
            }
            ans = min(ans,res-re+N[0].size()+N[1].size()-2);
        }
    }
    cout<<ans<<endl;
    return 0;
}