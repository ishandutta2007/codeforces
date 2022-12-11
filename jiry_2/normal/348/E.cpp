#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
struct bian{
    int next,point,w;
}b[210000];
int pd[110000],n,m,d[110000],len,sign,f[110000],g[110000],p[110000],A[110000],B[110000],dis,s,t,root,father[110000],x[110000],mf[110000],num[110000],fatherw[110000];
map<pair<int,int>,int>S[110000];
void ade(int k1,int k2,int k3){
    b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
void add(int k1,int k2,int k3){
    ade(k1,k2,k3); ade(k2,k1,k3);
}
void treedp(int k1,int k2){
    f[k1]=-1e9; g[k1]=-1e9; father[k1]=k2;
    if (pd[k1]) {f[k1]=0; A[k1]=k1;}
    for (int i=p[k1];i;i=b[i].next){
        int j=b[i].point; 
        if (j!=k2){
            d[j]=d[k1]+b[i].w; treedp(j,k1);
            if (f[j]+b[i].w>f[k1]){
                g[k1]=f[k1]; B[k1]=A[k1]; f[k1]=f[j]+b[i].w; A[k1]=A[j];
            } else if (f[j]+b[i].w>g[k1]){g[k1]=f[j]+b[i].w; B[k1]=A[j];}
        }
    }
}
void dfs(int k1,int k2,int k3){
    x[k1]=k3; num[k1]=pd[k1];
    for (int i=p[k1];i;i=b[i].next){
        int j=b[i].point;
        if (j!=k2){dfs(j,k1,k3); num[k1]+=num[j];}
    }
}
void treedp2(int k1,int k2){
    f[k1]=-1e9; g[k1]=-1e9; father[k1]=k2;
    if (pd[k1]) {f[k1]=0; A[k1]=k1; B[k1]=1;}
    for (int i=p[k1];i;i=b[i].next){
        int j=b[i].point; 
        if (j!=k2){
            d[j]=d[k1]+b[i].w; fatherw[j]=b[i].w; treedp2(j,k1);
            if (f[j]+b[i].w>f[k1]){
                f[k1]=f[j]+b[i].w; A[k1]=j; B[k1]=B[j];
            } else if (f[j]+b[i].w==f[k1]) B[k1]+=B[j];
        }
    }
}   
int main(){
    scanf("%d%d",&n,&m); int flag=0;
    for (int i=1;i<=m;i++){
        int k1; scanf("%d",&k1); pd[k1]=1; if (i==1&&k1==95918) flag=1;
    }
    for (int i=1;i<n;i++){
        int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3); add(k1,k2,k3);
    }
    treedp(1,0); dis=-1;
    for (int i=1;i<=n;i++)
        if (f[i]+g[i]>dis){
            dis=f[i]+g[i]; s=A[i]; t=B[i];
        }
    root=s;
    while (father[root]&&-d[father[root]]+d[s]<=dis/2) root=father[root];
    memset(A,0x00,sizeof A); memset(B,0x00,sizeof B); 
    memset(d,0x00,sizeof d); treedp2(root,0);
    for (int i=p[root];i;i=b[i].next){
        int j=b[i].point; dfs(j,root,j);
    }
    int numg=0; if (pd[root]){numg=1; g[root]=0;} 
    for (int i=p[root];i;i=b[i].next){
        int j=b[i].point;
        if (j!=A[root]){
            if (f[j]+b[i].w>g[root]){g[root]=f[j]+b[i].w; numg=0;} if (f[j]+b[i].w==g[root]) numg+=B[j];
        }
    }
 //   cout<<root<<" "<<dis<<" "<<s<<" "<<t<<endl;
    for (int i=1;i<=n;i++) if (pd[i]){
        int k1=0;
        if (f[x[i]]+fatherw[x[i]]==f[root]){
            mf[i]=g[root]+d[i]; if (g[root]==f[root]) k1=B[root]-B[x[i]]; else k1=numg;
        }else {mf[i]=f[root]+d[i]; k1=B[root];}
        if (i==root) continue;
//		cout<<"insert "<<i<<" "<<mf[i]<<" "<<k1<<endl;
        S[root][make_pair(mf[i]-d[i],k1)]++; S[x[i]][make_pair(mf[i]-d[i],k1)]++;
    }
    int ans=0,way=0; num[root]=m;
//	for (int i=1;i<=n;i++) cout<<"number "<<i<<" "<<f[i]<<" "<<B[i]<<" "<<A[i]<<" "<<fatherw[i]<<" "<<num[i]<<endl;
    for (int i=1;i<=n;i++){
        if (pd[i]) continue; if (i==root){if (ans==m) way++; else {ans=m; way=1;} continue;}
        int k1=S[root][make_pair(f[i]+d[i],B[i])]-S[x[i]][make_pair(f[i]+d[i],B[i])]+num[i];
        if (B[i]==B[root]&&d[i]+f[i]==f[root]) k1+=pd[root];
//		cout<<i<<" "<<S[root][make_pair(f[i]+d[i],B[i])]<<" "<<S[x[i]][make_pair(f[i]+d[i],B[i])]<<" "<<num[i]<<" "<<f[i]+d[i]<<" "<<B[i]<<endl;
        if (k1>ans){ans=k1; way=1;} else if (k1==ans) way++;
    }
    cout<<ans<<" "<<way<<endl;
    return 0;
}