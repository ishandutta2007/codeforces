#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 2*10E4 +7;
const ll INF = 10E17+7;

pp A[DIM];
satan_set S;
ll cnt[DIM*4];
bool mc(pp a,pp b){
    return a.sc<b.sc;
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(q,t){
        ll n; cin>>n;
        S.clear();
        forn(i,n){
            cin>>A[i].fi>>A[i].sc;
            S.insert(A[i].fi);
            S.insert(A[i].sc);
        }
        ll mx = 0,mxb = 0,mie = INF;
        forn(i,n){
            A[i].fi = (S.order_of_key(A[i].fi)+1)*2-1;
            A[i].sc = (S.order_of_key(A[i].sc)+1)*2-1;
            mie = min(mie,A[i].sc);
            mxb = max(mxb,A[i].fi);
            mx = max(mx,A[i].sc);
        }
        S.clear();
        for(ll i = 1;i<=mx;i++)S.insert(i);
        forn(i,n){
            auto it = S.lower_bound(A[i].fi);
            vector<ll> toer;
            for(;it!=S.end();it++){
                if (*it>A[i].sc)break;
                cnt[*it]++;
                if (cnt[*it]>=2)toer.pb(*it);
                //out<<*it<<endl;
            }
            for(ll to:toer)S.erase(to);
        }
        ll res = 0,base = 0,prev = -INF;
        mx++;
        S.insert(mx);
        for(auto it = S.begin();it!=S.end();it++){
            ll p = *it;
            if (cnt[p]!=0)continue;
            if ( p!=1 && p-1!=prev){
                base++;
            }
            //if (p==mx)base--;
            prev = p;
        }
        //sort(A+1,A+1+n,mc);
        forn(i,n){
            auto it = S.lower_bound(A[i].fi);
            prev = -INF; ll ct = 0,dots = 0,flag = 0;
            for(;it!=S.end();it++){
                ll p = *it;
                if (*it>A[i].sc)break;
                if (cnt[p]!=0 && cnt[p-1]!=0 && p-1!=prev){
                    ct++;
                    flag = 1;
                }
                else if (p-1!=prev)flag = 0;
                if(flag==1 && (cnt[p]==0||cnt[p+1]==0) ){
                    flag = 0;
                    ct--;
                }
                prev = p;
                dots++;
            }
            if (dots==A[i].sc-A[i].fi+1)ct--;
            res = max(res,ct+base);
            //cout<<res<<endl;
        }

        forn(i,mx)cnt[i] = 0;
        cout<<res<<endl;
    }
    return 0;
}