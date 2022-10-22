#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int mn=2e5+10;
int x[mn],y[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d%d",x+i,y+i);
    while(1){
        vector<int>v;
        for(int i=0;i<n;i++)if((x[i]+y[i])&1)v.push_back(i);
        if(v.size()>0&&v.size()<n){
            printf("%d\n",v.size());
            for(int x:v)printf("%d ",x+1);
            return 0;
        }
        if((x[0]+y[0])&1)for(int i=0;i<n;i++)x[i]++;
        for(int i=0;i<n;i++){
            int a=x[i]+y[i],b=x[i]-y[i];
            x[i]=a/2,y[i]=b/2;
        }
    }
}