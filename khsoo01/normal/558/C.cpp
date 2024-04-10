#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int bit[100005][25],len[100005];
int com[25],clen,tmp,noz[100005];
int n,arr[100005],ans;

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        for(j=0;;j++) {
            if((1<<j)>arr[i])break;
            bit[i][j]=!!((1<<j)&arr[i]);
        }
        len[i]=j;
        reverse(bit[i],bit[i]+j);
    }
    clen=len[0];
    for(i=0;i<len[0];i++) {
        com[i]=bit[0][i];
    }
    for(i=1;i<n;i++) {
        tmp=min(clen,len[i]);
        for(j=0;j<tmp;j++) {
            if(com[j]!=bit[i][j])break;
        }
        clen=j;
    }
    for(i=0;i<n;i++) {
        for(j=clen;j<len[i];j++) {
            if(bit[i][j])break;
            noz[i]++;
        }
        ans+=len[i]-clen-noz[i];
    }
    sort(noz,noz+n);
    for(i=0;i<n;i++) {
        ans+=abs(noz[i]-noz[n/2]);
    }
    printf("%d",ans);
}