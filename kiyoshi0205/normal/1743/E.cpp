 #include<bits/stdc++.h>
 using namespace std;
 using ll=long long;
 void chmin(ll& x,ll y){x=min(x,y);}
 int main(){
   ll d1,d2,t1,t2,h,s;
   cin>>d1>>t1>>d2>>t2>>h>>s;
   ll c1=0,c2=0,nd=0;
   vector<pair<ll,ll>> zure,same;
   while(nd<h){
     ll nt1=t1*(c1+1),nt2=t2*(c2+1);
     if(nt1==nt2){
       ++c1;++c2;
       nd+=d1+d2-s;
       same.emplace_back(nd,nt1);
       break;
     }
     if(nt1<nt2){
       ++c1;
       nd+=d1-s;
       zure.emplace_back(nd,nt1);
       if(c2)same.emplace_back(nd+s,nt1);
     }else{
       ++c2;
       nd+=d2-s;
       zure.emplace_back(nd,nt2);
       if(c1)same.emplace_back(nd+s,nt2);
     }
   }
   vector<ll> dp(h+1,1LL<<60);
   dp[0]=0;
   for(auto[c,v]:same){
     while(c<h){
       for(ll i=0;i<h;++i)chmin(dp[min(i+c,h)],dp[i]+v);
       c+=c;v+=v;
     }
     chmin(dp[h],v);
   }
   for(ll i=h;i>0;--i)chmin(dp[i-1],dp[i]);
   ll ans=dp[h];
   for(auto[c,v]:zure)chmin(ans,dp[max(0LL,h-c)]+v);
   cout<<ans<<endl;
 }