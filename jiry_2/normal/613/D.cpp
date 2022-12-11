#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct bian{
    int next,point;
}b[210000];
int p[110000],len,n,m,q,a[210000],father[110000][17],d[110000],dfs[110000],sign,pd[110000],K,s[110000],head,r[110000];
int dp[110000][2];
vector<int>go[110000];
const int inf=1e9;
void ade(int k1,int k2){
    b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
    ade(k1,k2); ade(k2,k1);
}
void dfs1(int k1,int k2){
    father[k1][0]=k2; d[k1]=d[k2]+1; dfs[k1]=++sign;
    for (int i=p[k1];i;i=b[i].next){
        int j=b[i].point;
        if (j!=k2) dfs1(j,k1);
    }
    r[k1]=sign;
}
int getlca(int k1,int k2){
    if (d[k1]<d[k2]) swap(k1,k2);
    for (int i=16;i>=0;i--) if (d[k1]-d[k2]>=(1<<i)) k1=father[k1][i];
    if (k1==k2) return k1;
    for (int i=16;i>=0;i--) if (father[k1][i]!=father[k2][i]){
        k1=father[k1][i]; k2=father[k2][i];
    }
    return father[k1][0];
}
int compare(int k1,int k2){
    return dfs[k1]<dfs[k2];
}
void treedp(int k1,int k2){
    if (pd[a[k1]]!=sign){
        dp[k1][0]=0; dp[k1][1]=0; int k3=0;
        for (int i=0;i<go[k1].size();i++){
            int j=go[k1][i];
            if (j!=k2){
                treedp(j,k1);
                k3+=min(dp[j][0],dp[j][1]); 
                dp[k1][1]=min(dp[k1][1]+dp[j][0],dp[k1][0]+dp[j][1]);
                dp[k1][0]=dp[k1][0]+dp[j][0];
                dp[k1][1]=min(dp[k1][1],inf); dp[k1][0]=min(dp[k1][0],inf);
            }
        }
        dp[k1][0]=min(dp[k1][0],k3+1);
    } else {
        dp[k1][0]=inf; dp[k1][1]=0;
        for (int i=0;i<go[k1].size();i++){
            int j=go[k1][i];
            if (j!=k2){
                treedp(j,k1);
                dp[k1][1]=dp[k1][1]+min(dp[j][0],dp[j][1]+1);
                dp[k1][1]=min(dp[k1][1],inf); dp[k1][0]=min(dp[k1][0],inf);
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int k1,k2; scanf("%d%d",&k1,&k2);
        add(k1,k2);
    }
    dfs1(1,0);
    for (int i=1;i<=16;i++)
        for (int j=1;j<=n;j++) father[j][i]=father[father[j][i-1]][i-1];
    scanf("%d",&q); sign=0;
    for (;q;q--){
        scanf("%d",&m); sign++;
        for (int i=1;i<=m;i++) scanf("%d",&a[i]);
        for (int i=1;i<=m;i++) pd[a[i]]=sign;
        sort(a+1,a+m+1,compare); int prem=m;
        for (int i=1;i<prem;i++) a[++m]=getlca(a[i],a[i+1]);
        sort(a+1,a+m+1,compare); head=1; K=1; s[1]=1; int flag=0; go[1].clear();
        for (int i=2;i<=m;i++){
            if (a[i]==a[s[head]]) continue; a[++K]=a[i]; go[K].clear();
            while (head&&dfs[a[i]]>r[a[s[head]]]) head--;
            go[s[head]].push_back(K); //cout<<"add "<<s[head]<<" "<<K<<endl;
            if (pd[a[s[head]]]==sign&&pd[a[K]]==sign&&d[a[K]]==d[a[s[head]]]+1) flag=1; 
            s[++head]=K;
        }
    //  for (int i=1;i<=K;i++) cout<<a[i]<<" "; cout<<endl;
        if (flag){
            printf("-1\n"); continue;
        }
        treedp(1,0); printf("%d\n",min(dp[1][0],dp[1][1]));
    //  for (int i=1;i<=K;i++) cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    return 0;
}