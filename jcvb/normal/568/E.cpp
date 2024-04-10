#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

int n;
int a[5011111];int to;
int m;
int b[1011111];
int nu[5011111];
int st[1011111],top=0;
int pre[5011111];


void work1(int i){
    int l=1,r=top,mid;
    while(l<=r){
        mid=l+r>>1;
        if(a[st[mid]]>=a[i])r=mid-1;
        else l=mid+1;
    }
    if(l==top+1)top++;
    if(a[st[l]]==a[i])return;
    st[l]=i;
    pre[i]=st[l-1];
}
void work2(){
    int cur=top+1;
    int las=cur+1;
    for (int i=m;i>=1;i--){
        while(cur>=2 && a[st[cur-1]]>=b[i])cur--;
        if(a[st[cur]]==b[i])continue;
        if(cur!=las)to++;
        las=cur;
        st[cur]=to;
        a[to]=b[i];
        nu[to]=i;
        if(cur>top)top=cur;
        pre[to]=st[cur-1];
    }
}
int ans[1011111];
bool us[1011111];
int main()
{
    gn(n);
    for (int i=1;i<=n;i++)gn(a[i]);
    gn(m);
    for (int i=1;i<=m;i++)gn(b[i]);
    sort(b+1,b+1+m);
    to=n;
    
    for (int i=1;i<=n;i++)
        if(a[i]==-1)work2();
        else work1(i);
    
    int u=st[top];
    for (int i=top;i>=1;i--){
        ans[i]=u;
        u=pre[u];
    }
    for (int i=1;i<=top;i++)if(ans[i]>n)us[nu[ans[i]]]=1;
    int cur=1;
    for (int i=1;i<=top;i++)
        if(ans[i]<=n)cur=ans[i];
        else{
            while(a[cur]!=-1)cur++;
            a[cur]=a[ans[i]];
        }

    cur=1;
    for (int i=1;i<=n;i++)if(a[i]==-1){
        while(us[cur])cur++;
        a[i]=b[cur++];
    }
    for (int i=1;i<=n;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}