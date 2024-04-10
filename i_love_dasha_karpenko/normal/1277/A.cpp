#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pp;
const ll DIM = 10E5+7;
const ll INF = 10E18+173;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n; cin>>n;
        ll res = 0,flag = 0;
        forn(div,n){
            forn(i,9){
                ll mult = 1;
                ll num = 0;
                forn(j,div){
                    num+=mult*i;
                    mult*=10;
                }
                if (num>n){
                    flag =1;
                    break;
                }
                res++;
            }
            if (flag==1)break;
        }
        cout<<res<<endl;
    }
    return 0;
}
// 5 4 1 2 3 4 5 2 1 3