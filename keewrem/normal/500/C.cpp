#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N,M;
bool occ[1000];

int main(){
    cin >> N >> M;
    vll w(N);
    for(auto &x: w)cin >> x;
    w.pb(0);
    vi ord;
    vi kek(M);
    for(auto &x: kek)cin  >> x;
    for(auto x: kek){
        if(!occ[x]){
            occ[x]=1;
            ord.pb(x);
        }
    }
    for(int i = 1;  i <=N;  i++){
        if(!occ[i])ord.pb(i);
    }
    reverse(ord.begin(),ord.end());
    ll ans = 0;
    for(auto x: kek){
        ll cur = 0;
        for(int i = ord.size()-1; i>=0; i--){
        //    cout << ord[i]<<" ";
            if(ord[i]!=x)cur+=w[ord[i]-1];

            else {ans+=cur;ord[i]=N+1; ord.pb(x);break;}
            //cout << cur<<" ";
        }
        cout << endl;
    }
    cout << ans << "\n";
    return 0;
}