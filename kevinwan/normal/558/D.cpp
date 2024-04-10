#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
vector<pll>act;
int main(){
    ll h,q;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>h>>q;
    for(int i=0;i<q;i++){
        ll lev,l,r,ii;
        cin>>lev>>l>>r>>ii;
        r++;
        l-=1LL<<lev-1,r-=1LL<<lev-1;
        l<<=h-lev,r<<=h-lev;
        if(ii)act.push_back({l,1}),act.push_back({r,-1});
        else act.push_back({0,1}),act.push_back({l,-1}),act.push_back({r,1});
    }
    act.push_back({0,0});
    act.push_back({1LL<<h-1,0});
    sort(act.begin(),act.end());
    ll cum=0;
    ll ans=0,pr=-1;
    for(int i=0;i+1<act.size();i++){
        cum+=act[i].second;
        if(cum==q){
            ans+=act[i+1].first-act[i].first;
            if(act[i+1].first!=act[i].first)pr=(1LL<<h-1)+act[i].first;
        }
    }
    if(ans==0)printf("Game cheated!");
    else if(ans>1)printf("Data not sufficient!");
    else printf("%lld",pr);
}