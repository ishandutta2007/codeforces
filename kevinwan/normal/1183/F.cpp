#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=2e5+10;
int a[mn];
vector<int>f[mn];
bool s[mn];
int main(){
    for(int i=2;i*2<mn;i++)for(int j=i*2;j<mn;j+=i)f[j].push_back(i);
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",a+i),s[a[i]]=1;
        sort(a,a+n);
        int wtf=0;
        for(int i=0;i<n;i++){
            if(a[i]%30==0&&s[a[i]/2]&&s[a[i]/3]&&s[a[i]/5])wtf=max(wtf,a[i]/30*31);
        }
        for(int i=0;i<n;i++)for(int x:f[a[i]]){
            s[x]=0;
        }
        int num=0,ans=0;
        for(int i=n-1;i>=0;i--){
            if(!s[a[i]]||num==3)continue;
            num++;
            ans+=a[i];
            s[a[i]]=0;
        }
        for(int i=n-1;i>=0;i--)s[a[i]]=0;
        printf("%d\n",max(wtf,ans));
    }
}