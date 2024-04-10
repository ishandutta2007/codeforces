#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
inline ll gcd(ll a,ll b){while(b)a%=b,swap(a,b);return a;}
ll x[mn],y[mn];
int main(){
    ll ax,ay,bx,by,sx,sy,t;
    cin>>x[0]>>y[0]>>ax>>ay>>bx>>by>>sx>>sy>>t;
    int n;
    for(n=0;x[n]+y[n]<=5e16;n++)x[n+1]=x[n]*ax+bx,y[n+1]=y[n]*ay+by;
    int ans=0;
    for(int i=0;i<n;i++){
        ll rt=t-abs(sx-x[i])-abs(sy-y[i]);
        if(rt<0)continue;
        int tans=1;
        int j;
        for(j=i-1;j>=0;j--){
            if(rt-abs(x[i]-x[j])-abs(y[i]-y[j])<0)break;
        }
        j++;
        tans+=i-j;
        if(j==0) {
            rt -= abs(x[i] - x[0]) + abs(y[i] - y[0]);
            for (j = i + 1; j < n; j++) {
                if (rt - abs(x[j] - x[0]) - abs(y[j] - y[0]) < 0)break;
            }
            j--;
            tans += j - i;
        }
        ans=max(ans,tans);
    }
    printf("%d",ans);
}