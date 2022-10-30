#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 100020;
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
ll n,k,vis[DIM];
vector<ll> simp;
ll M[DIM];
vector<ll> aval;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    vis[1] = 1;
    for(ll i = 2;i<DIM;i++){
        if (vis[i]==0){
            simp.pb(i);
            for(ll j = i*i;j<DIM;j+=i)vis[j] = 1;
        }
    }
    forn(i,n){
        ll x; cin>>x;
        ll r = 1;
        for(ll j = 1;j<=sqrt(x);j++){
            if (x%j!=0){
                continue;
            }
            if (vis[j]==0){
                ll y = x;
                ll num = 0;
                ll div = j;
                while(y%div==0){
                    y/=div;
                    num++;
                }
                num%=k;
                r*=pow(div,num);
            }
            if (j*j!=x && vis[x/j]==0){
                ll y = x;
                ll num = 0;
                ll div = x/j;
                while(y%div==0){
                    y/=div;
                    num++;
                }
                num%=k;
                r*=pow(div,num);
            }
        }
        M[r]++;
        if (M[r]==1)aval.pb(r);
    }
    ll res = 0;
    for(ll to:aval){
        if (to==1){
            res+=M[to]*(M[to]-1);
        }
        else{
            ll r= 1;
            ll x= to;
            ll FL = 0;
            for(ll j = 1;j<=sqrt(x);j++) {
                ll div = j;
                if (vis[div]==0){
                    ll y = x,num = 0;
                    while(y%div==0){
                        num++;
                        y/=div;
                    }
                    if (num!=0){
                        num = k-num;
                    }
                    ll mult = 1,flag = 0;
                    while(num>0){
                        mult*=div;
                        if (mult>=DIM){
                            flag = 1;
                            break;
                        }
                        num--;
                    }
                    if (flag==0 && r*mult<DIM){
                        r*=mult;
                    }
                    else{
                        FL = 1;
                        break;
                    }
                }
                div = x/j;
                if (j*j!=x && vis[div]==0){
                    ll y = x,num = 0;
                    while(y%div==0){
                        num++;
                        y/=div;
                    }
                    if (num!=0){
                        num = k-num;
                    }
                    ll mult = 1,flag = 0;
                    while(num>0){
                        mult*=div;
                        if (mult>=DIM){
                            flag = 1;
                            break;
                        }
                        num--;
                    }
                    if (flag==0 && r*mult<DIM){
                        r*=mult;
                    }
                    else{
                        FL = 1;
                        break;
                    }
                }
            }
            //cout<<r<<endl;
            if (FL==0) {
                if (to==r)res+=M[to]*(M[to]-1);
                else res += M[to] * M[r];
            }
        }
    }
    cout<<res/2<<endl;
    return 0;
}