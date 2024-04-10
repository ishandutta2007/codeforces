#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,M;
    scanf("%d%d",&n,&M);
    int sum=0;
    vector<int> cnt(101);
    for(int i=0;i<n;++i){
        int t;
        scanf("%d",&t);
        int ans=0;
        for(int res=sum+t-M,i=100;res>0;--i){
            int x=min(cnt[i],(res+i-1)/i);
            ans+=x;
            res-=x*i;
        }
        printf("%d ",ans);
        ++cnt[t];
        sum+=t;
    }
    return 0;
}