#include<cstdio>
using namespace std;
int n,a[210000],pos[210000],Log2[210000];
int f[210000][21];
void init(){
    for (int i=1;i<=n;i++) f[i][0]=i;
    for (int j=1;(1<<j)<=n;j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
            if (a[f[i][j-1]]>a[f[i+(1<<(j-1))][j-1]]) f[i][j]=f[i][j-1];
            else f[i][j]=f[i+(1<<(j-1))][j-1];
}

int query(int l,int r){
    int k=Log2[r-l+1];
    if (a[f[l][k]]>a[f[r-(1<<k)+1][k]]) return f[l][k];
    else return f[r-(1<<k)+1][k];
}
int dfs(int l,int r){
    if (l>=r) return 0;
    int k=query(l,r),ans=0,v;
    if (k-l<=r-k)
        for (int i=l;i<=k;i++){
            v=a[k]-a[i];
            if (pos[v]>k&&pos[v]<=r) ans++;
        }
    else
        for (int i=k+1;i<=r;i++){
            v=a[k]-a[i];
            if (pos[v]>=l&&pos[v]<=k) ans++;
        }
    return ans+dfs(l,k-1)+dfs(k+1,r);
}

int main(){
    scanf("%d",&n); Log2[0]=-1;
    for (int i=1;i<=n;i++) Log2[i]=Log2[i>>1]+1;
    for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
    init();
    printf("%d\n",dfs(1,n));
    return 0;
}