#include<bits/stdc++.h>
using namespace std;
int n,arr[1000005],cnt,ans,k,cur;
int prime[1000005],dt[1000005],mx;
bool isprime[1000005];
vector<int>cp[1000005];

int main()
{
    int i,j,lim;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        mx=max(arr[i],mx);
    }
    for(i=2;i<=mx;i++) {
        if(!isprime[i]) {
            for(j=i;j<=mx;j+=i) {
                cp[j].push_back(i);
            }
            if(i*i<=mx && i<=1000) {
                for(j=i*i;j<=mx;j+=i) {
                    isprime[j]=1;
                }
            }
        }
    }
    cp[1].push_back(1);
    for(i=1;i<=mx;i++) {
        for(;cur<n;cur++) {
            if(arr[cur]!=i)break;
            k++;
        }
        lim=cp[i].size();
        for(j=0;j<lim;j++) {
            dt[i]=max(dt[i/cp[i][j]]+k,dt[i]);
        }
        k=0;
    }
    for(i=1;i<=mx;i++) {
        ans=max(ans,dt[i]);
    }
    printf("%d",ans);
}