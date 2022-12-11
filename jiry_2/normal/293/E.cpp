#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct bian{
    int next,point,w;
}b[201000];
struct atom{
    int l,w;
}x[101000],y[101000];
int len,n,p[101000],size[101000],pd[101000],l,w,A[101000],B[101000],where,num,m,C[101000],sign,fw[101000];
long long ans;
void ade(int k1,int k2,int k3){
    b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
void add(int k1,int k2,int k3){
    ade(k1,k2,k3); ade(k2,k1,k3);
}
int compare(int k1,int k2){
    return size[k1]<size[k2];
}
int dfs(int k1,int k2){
    size[k1]=1;
    for (int i=p[k1];i;i=b[i].next){
        int j=b[i].point;
        if (pd[j]==0&&j!=k2) size[k1]+=dfs(j,k1);
    }
    return size[k1];
}
void dfs2(int k1,int k2){
    int now=0;
    for (int i=p[k1];i;i=b[i].next){
        int j=b[i].point;
        if (j!=k2&&pd[j]==0){dfs2(j,k1); now=max(now,size[j]);}
    }
    now=max(now,m-size[k1]); if (now<num){num=now; where=k1;}
}
int compare2(atom k1,atom k2){
    return k1.w<k2.w;
}
int compare3(atom k1,atom k2){
    return k1.w>k2.w;
}
int find(int k){
    if (k<0) return 0;
    int num=0; for (;k;k-=k&(-k)){if (C[k]!=sign) {B[k]=0; C[k]=sign;} num+=B[k];} return num;
}
void add(int k){
    for (;k<=l;k+=k&(-k)){if (C[k]!=sign) {B[k]=0; C[k]=sign;} B[k]++;}
}
void dfs3(int k1,int k2,int k3,int k4){
    y[++len]=(atom){k4,k3};
    for (int i=p[k1];i;i=b[i].next){
        int j=b[i].point; if (pd[j]==0&&j!=k2) dfs3(j,k1,k3+b[i].w,k4+1);
    }
}
void dowith(int k1){
    m=dfs(k1,0); num=m; dfs2(k1,0); int k=where; dfs(k,0); 
    int now=0; pd[k]=1;
    for (int i=p[k];i;i=b[i].next){
        int j=b[i].point; if (pd[j]==0){A[++now]=j; fw[j]=b[i].w;}
    }
    sort(A+1,A+now+1,compare); int lon=1; x[1]=(atom){0,0};
//  for (int i=1;i<=now;i++) cout<<A[i]<<" "; cout<<endl;
    for (int i=1;i<=now;i++){
        len=0; dfs3(A[i],k,fw[A[i]],1); sort(x+1,x+lon+1,compare2); 
        sort(y+1,y+len+1,compare3); int k2=1; sign++;
    //  for (int j=1;j<=len;j++) cout<<y[j].w<<" "; cout<<endl;
        for (int j=1;j<=lon;j++){
            while (k2<=len&&y[k2].w+x[j].w>w) {ans+=find(l-y[k2].l); k2++;}
            add(x[j].l+1);
        }
        for (int j=k2;j<=len;j++) ans+=find(l-y[j].l);
        for (int j=1;j<=len;j++) x[++lon]=y[j];
    }
//  cout<<k<<" "<<ans<<endl;
    for (int i=p[k];i;i=b[i].next){
        int j=b[i].point; if (pd[j]==0) dowith(j);
    }
}
int main(){
    scanf("%d%d%d",&n,&l,&w); l++; for (int i=1;i<n;i++){int k1,k2; scanf("%d%d",&k1,&k2); add(k1,i+1,k2);}
    ans=0; dowith(1); cout<<ans<<endl; return 0;
}