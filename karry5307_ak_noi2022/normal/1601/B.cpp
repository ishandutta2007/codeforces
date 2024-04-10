#include<bits/stdc++.h>
using namespace std;
int n,a[300010],b[300010],f[300010],lst[300010];
pair<int,int> val[300010];
#define lb(x) (x&-x)
void Add(int k,pair<int,int> pr){for(;k<=n;k+=lb(k)) val[k]=min(val[k],pr);}
pair<int,int> Ask(int k){
    pair<int,int> ans=make_pair(2e9,2e9);
    for(;k;k-=lb(k)) ans=min(ans,val[k]);
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=0;i<n;i++) f[i]=2e9;
    int minn=2e9,minx=0;
    for(int i=1;i<=n;i++) val[i]=make_pair(2e9,2e9);
    for(int i=n;i>=1;i--){
        if(i<n){
            pair<int,int> pr=Ask(i);
            f[i]=pr.first;
            lst[i]=pr.second;
        }
        int t=i+b[i]-a[i+b[i]];
        if(!t){
            if(minn>f[i]+1){
                minn=f[i]+1;
                minx=i;
            }t++;
        }
        Add(t,make_pair(f[i]+1,i));
    }
    if(minn>1e9) puts("-1");
    else{
        int x=minx;
        vector<int> Ans;
        Ans.push_back(0);
        while(x!=n){
            Ans.push_back(x);
            x=lst[x];
        }
        printf("%d\n",(int)Ans.size());
        reverse(Ans.begin(),Ans.end());
        for(auto x:Ans) printf("%d ",x);
    }
    return 0;
}