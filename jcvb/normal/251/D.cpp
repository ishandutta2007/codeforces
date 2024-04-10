#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<bitset>
typedef long long ll;
using namespace std;
int n;
ll s[100005]={0};
bitset<100000> a[64];int b[64];
int bitsum[64]={0};
int pos[100005];
void add(int i,int bi){
    for (int j=n-1;j>=0;j--){
        if(!a[i][j])continue;
        if(pos[j]==-1){
            pos[j]=i;
            b[i]=bi;
            return;
        }else{
            int t=pos[j];
            a[i]=a[i]^a[t];
            bi^=b[t];
        }
    }
}
int ans[100005]={0};
int main()
{
    int bo=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)scanf("%I64d",&s[i]);
    for (int j=0;j<64;j++)
        for (int i=0;i<n;i++){
            int t=(1ll<<j&s[i])?1:0;
            a[j][i]=t,bitsum[j]^=t;
        }
    memset(pos,-1,sizeof(pos));
    memset(b,-1,sizeof(b));
    for (int j=63;j>=0;j--)if(!bitsum[j])add(j,1);
    for (int j=63;j>=0;j--)if(bitsum[j])add(j,0);
    for (int k=n-1;k>=0;k--)if(~pos[k]){
        int i=pos[k];
        for (int j=k-1;j>=0;j--)if(a[i][j] && ~pos[j]){
            a[i]=a[i]^a[pos[j]],b[i]^=b[pos[j]];
        }
        if(b[i])ans[k]=1;
    }
    for (int i=0;i<n;i++){
        if(i)putchar(' ');
        if(ans[i])printf("1");else printf("2");
    }
    putchar('\n');
    return 0;
}