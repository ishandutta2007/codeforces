#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
using P=pair<ll,ll>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(15);
    int N,H;
    cin>>N>>H;
    vector<P> v(N);
    rep(i,N){
        cin>>v[i].first>>v[i].second;
    }
    reverse(v.begin(),v.end());
    P me=v[0],rem=P(0,-H);
    me.second+=H;
    for(auto& t:v){
        t.first-=me.first;
        t.second-=me.second;
    }

    double ans=0;
    rep(i,N-1){
        P now=v[i+1];
        ll t=now.first*rem.second-now.second*rem.first;
        if(t<0)continue;
        if(t==0){
            if(rem==v[i])ans+=sqrt((v[i].first-v[i+1].first)*(v[i].first-v[i+1].first)+(v[i].second-v[i+1].second)*(v[i].second-v[i+1].second));
//            cout<<i<<" pp"<<ans<<endl;
            rem=now;
            continue;
        }
        P sa(v[i].first-v[i+1].first,v[i].second-v[i+1].second);
        ll tmp1=now.second*sa.first-now.first*sa.second;
        ll tmp2=rem.second*sa.first-rem.first*sa.second;
        double tmp=(double)tmp1/tmp2;
        double a=tmp*rem.first-now.first,b=tmp*rem.second-now.second;
        ans+=sqrt(a*a+b*b);
        rem=now;
//        cout<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}