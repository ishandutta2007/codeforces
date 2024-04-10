#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <stack>
using namespace std;
typedef long long ll;
const ll N=1000005;
const ll inf=0x3f3f3f3f3f3f3f3f;

char c[N];
vector<ll> g[N];
int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        ll n,p,k;
        cin>>n>>p>>k;
        for(int i=0;i<k;i++) g[i].clear();
        cin>>(c+1);
        ll xx,y;
        cin>>xx>>y;
        ll mmin=0x3f3f3f3f3f3f3f3f;
        for(ll i=p;i<p+k&&i<=n;i++){
            for(ll j=i;j<=n;j+=k){
                if(c[j]=='1') g[i-p].push_back(1);
                else g[i-p].push_back(0);
            }
        }
        for(int i=0;i<k&&p+i<=n;i++){
            ll cnt=0;
            for(auto x:g[i]) if(x==0) cnt++;
            ll now=cnt*xx+i*y;
            mmin=min(mmin,now);
            
            for(int l=0;l<g[i].size();l++){
                ll x=g[i][l];
                if(l==(int)g[i].size()-1) continue;
                now+=y*k;
                if(x==0) now-=xx;
                mmin=min(mmin,now);
            }
        }
        cout<<mmin<<endl;
    }
}