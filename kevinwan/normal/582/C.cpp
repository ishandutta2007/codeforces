#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+9;
const int mn=2e5+10;
int a[mn*2];
int s[mn],mo[mn],sc[mn*2],fu[mn];
int gcd(int a,int b){
    while(b)a%=b,swap(a,b);
    return a;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i],a[i+n]=a[i];
    for(int i=1;i<=n;i++)fu[i]=gcd(n,i);
    ll ans=0;
    for(int d=1;d<n;d++)if(n%d==0){
        memset(s,0,sizeof(s));
        memset(mo,0,sizeof(mo));
        for(int i=0;i<n;i++)mo[i%d]=max(mo[i%d],a[i]);
        memset(sc,0,sizeof(sc));
        for(int i=0;i<d;i++){
            vector<int>v;
            for(int j=i;j<2*n;j+=d){
                if(a[j]==mo[i]){
                    if(j<n)v.push_back(j);
                }
                else{
                    for(int x:v)sc[x]=min(n,j-x)/d;
                    v.clear();
                }
            }
            for(int x:v)sc[x]=n/d;
        }
        for(int i=0;i<n;i++)sc[i+n]=sc[i];
        deque<pii>q;
        s[0]=n;
        for(int i=0;i<n+d-1;i++){
            while(q.size()&&q.front().second<=i-d)q.pop_front();
            while(q.size()&&q.back().first>=sc[i])q.pop_back();
            q.push_back({sc[i],i});
            if(i>=d-1){
                s[q.front().first+1]--;
            }
        }
        for(int i=1;i<=n/d;i++){
            s[i]+=s[i-1];
            if(fu[i*d]==d){
                ans+=s[i];
            }
        }
    }
    printf("%lld",ans);
}