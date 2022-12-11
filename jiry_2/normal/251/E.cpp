#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct bian{
    int next,point;
}b[410000];
int len,p[210000],n,d[210000],root,mo=1e9+7,A[210000],B[210000],C[210000],size[210000],f[210000];
vector<int>child[210000];
const int go[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
void ade(int k1,int k2){
    b[++len]=(bian){p[k1],k2}; p[k1]=len; 
}
void add(int k1,int k2){
    ade(k1,k2); ade(k2,k1); d[k1]++; d[k2]++;
}
void dfs(int k1,int k2){
    C[k1]=C[k2]+1; size[k1]=1;
    for (int i=p[k1];i;i=b[i].next){
        int j=b[i].point;
        if (j!=k2){
            child[k1].push_back(j);
            dfs(j,k1); A[k1]=max(A[k1],max(A[j],d[j]));
            if (B[k1]==0){
                if (d[j]==3) B[k1]=j; else B[k1]=B[j];
            }
            size[k1]+=size[j];
        }
    }
}
int dowith(int k1,int k2){
    while (1){
        if (child[k1].size()==2||child[k2].size()==2) return 0;
        if (child[k1].size()==0&&child[k2].size()==0) return 1;
        if (child[k1].size()==0) return f[child[k2][0]];
        if (child[k2].size()==0) return f[child[k1][0]];
        k1=child[k1][0]; k2=child[k2][0];
    }
}
void treedp(int k1,int k2){
    for (int i=p[k1];i;i=b[i].next){
        int j=b[i].point;
        if (j!=k2) treedp(j,k1);
    }
    if (size[k1]%2){f[k1]=0; return;}
    if (B[k1]==0&&d[k1]<3){
        f[k1]=size[k1]/2; return;
    }
    if (child[k1].size()==1){
        int u=child[k1][0];
        if (d[u]==1) f[k1]=1;
        else if (d[u]==2){
            int v=child[u][0]; f[k1]=f[v];
        }
    } else if (child[k1].size()==2){
        int k3=child[k1][0],k4=child[k1][1];
        if (child[k3].size()==0) f[k1]=(f[k1]+f[k4])%mo; else if (child[k3].size()==1)f[k1]=(f[k1]+dowith(child[k3][0],k4))%mo;
        swap(k3,k4);
        if (child[k3].size()==0) f[k1]=(f[k1]+f[k4])%mo; else if (child[k3].size()==1)f[k1]=(f[k1]+dowith(child[k3][0],k4))%mo;
        return;
    }
    if (B[k1]==0||B[k1]==-1) return;
    int u=B[k1],dis=C[u]-C[k1]+1,k3=child[u][0],k4=child[u][1];
    if (size[k3]==dis&&B[k3]==0&&d[k3]!=3) f[k1]=(f[k1]+f[k4])%mo;
    if (size[k4]==dis&&B[k4]==0&&d[k4]!=3) f[k1]=(f[k1]+f[k3])%mo;
    if (size[k3]==dis-2&&B[k3]==0&&d[k3]!=3) f[k1]=(f[k1]+f[k4])%mo;
    if (size[k4]==dis-2&&B[k4]==0&&d[k4]!=3) f[k1]=(f[k1]+f[k3])%mo;
    if (d[k3]==3){
        int k5=child[k3][0],k6=child[k3][1];
        if (size[k5]==dis-1&&B[k5]==0&&d[k5]!=3) f[k1]=(f[k1]+dowith(k6,k4))%mo;
        swap(k5,k6);
        if (size[k5]==dis-1&&B[k5]==0&&d[k5]!=3) f[k1]=(f[k1]+dowith(k6,k4))%mo;
    }
    swap(k3,k4);
    if (d[k3]==3){
        int k5=child[k3][0],k6=child[k3][1];
        if (size[k5]==dis-1&&B[k5]==0&&d[k5]!=3) f[k1]=(f[k1]+dowith(k6,k4))%mo;
        swap(k5,k6);
        if (size[k5]==dis-1&&B[k5]==0&&d[k5]!=3) f[k1]=(f[k1]+dowith(k6,k4))%mo;
    }
    return;
}
int main(){
//  freopen("data.in","r",stdin);
//  freopen("data.out","w",stdout);
    scanf("%d",&n); n*=2; if (n==2){cout<<2<<endl; return 0;}
    for (int i=1;i<n;i++){
        int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
    }
    int num=0;
    for (int i=1;i<=n;i++) num=max(num,d[i]);
    if (num>3) {cout<<0<<endl; return 0;} else if (num==2) {n=n/2; cout<<((1ll*2*n*n%mo-2*n%mo+4)%mo+mo)%mo<<endl; return 0;} 
    for (int i=1;i<=n;i++) if (d[i]==3){root=i; break;} dfs(root,0);
    for (int i=p[root];i;i=b[i].next){
        int j=b[i].point; treedp(j,root);
    }
//  cout<<root<<endl; 
//  for (int i=1;i<=n;i++) cout<<i<<" "<<f[i]<<" "<<B[i]<<" "<<d[i]<<" "<<size[i]<<" "<<C[i]<<endl;
    int ans=0;
    for (int i=0;i<6;i++){
        int k1=child[root][go[i][0]],k2=child[root][go[i][1]],k3=child[root][go[i][2]];
        if (d[k1]==1) ans=(ans+1ll*f[k2]*f[k3])%mo;
        else if (d[k1]==2){
            int k4=child[k1][0];
            ans=(ans+1ll*dowith(k2,k4)*f[k3])%mo;
            ans=(ans+1ll*dowith(k3,k4)*f[k2])%mo;
        } else if (d[k1]==3){
            int k4=child[k1][0],k5=child[k1][1];
            ans=(ans+1ll*dowith(k2,k4)*dowith(k3,k5))%mo;
            ans=(ans+1ll*dowith(k3,k4)*dowith(k2,k5))%mo;
        }
    }
    cout<<ans*2%mo<<endl;
    return 0;
}