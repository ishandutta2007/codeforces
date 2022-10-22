#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=1e6+10;
pii p[mn];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d%d",&p[i].first,&p[i].second);
        sort(p,p+n,[](pii a,pii b){if(a.first!=b.first)return a.first<b.first;return a.second>b.second;});
        ll ans=0,b=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=n-1;i>=0;i--){
            pq.push(p[i].second);
            if(i+b<p[i].first)ans+=pq.top(),pq.pop(),b++;
        }
        printf("%lld\n",ans);
    }
}