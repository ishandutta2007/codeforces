#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
    long long x,y,z;
}b[10][15];
struct atom2{
    int k1,k2;
    long long w;
}a[65];
long long x[10][3],y[10][3],flag,z[10],w[10][30],f[10];
#define sqr(x) ((x)*(x)) 
long long findw(int k1,int k2){
    return sqr(y[k1][0]-y[k2][0])+sqr(y[k1][1]-y[k2][1])+sqr(y[k1][2]-y[k2][2]); 
} 
int compare(atom2 k1,atom2 k2){
    return k1.w<k2.w;
}
int pd(atom k1,atom k2){
    long long k3=k1.x*k2.x+k1.y*k2.y+k1.z*k2.z;
    if (k3==0) return 1; else return 0;
}
int check(){
    int len=0;
    long long num=1e15;
    for (int i=1;i<=8;i++)
        for (int j=i+1;j<=8;j++) num=min(findw(i,j),num);
    if (num==0) return 0;
    memset(z,0x00,sizeof z);
    for (int i=1;i<=8;i++)
        for (int j=i+1;j<=8;j++) 
            if (findw(i,j)==num){len++; z[i]++; w[i][z[i]]=j; z[j]++; w[j][z[j]]=i;} 
    if (len!=12) return 0;
    for (int i=1;i<=8;i++) if (z[i]!=3) return 0; //cout<<1<<endl;
    for (int i=1;i<=8;i++)
        for (int j=1;j<=3;j++) b[i][j]=(atom){y[i][0]-y[w[i][j]][0],y[i][1]-y[w[i][j]][1],y[i][2]-y[w[i][j]][2]};
    for (int i=1;i<=8;i++)
        for (int j=1;j<=3;j++)
            if (pd(b[i][j],b[i][j%3+1])==0) return 0;
    return 1;
}
void print(){
    cout<<"YES"<<endl;
    for (int i=1;i<=8;i++){
        for (int j=0;j<=2;j++) printf("%I64d ",y[i][j]); printf("\n");}
    }
void dfs(int k){
    if (k==9){if (check()) {flag=1; print();} return;}
    y[k][0]=x[k][0]; y[k][1]=x[k][1]; y[k][2]=x[k][2];
    dfs(k+1); if (flag) return;
    y[k][0]=x[k][0]; y[k][1]=x[k][2]; y[k][2]=x[k][1];
    dfs(k+1); if (flag) return;
    y[k][0]=x[k][1]; y[k][1]=x[k][0]; y[k][2]=x[k][2];
    dfs(k+1); if (flag) return;
    y[k][0]=x[k][1]; y[k][1]=x[k][2]; y[k][2]=x[k][0];
    dfs(k+1); if (flag) return;
    y[k][0]=x[k][2]; y[k][1]=x[k][0]; y[k][2]=x[k][1];
    dfs(k+1); if (flag) return;
    y[k][0]=x[k][2]; y[k][1]=x[k][1]; y[k][2]=x[k][0];
    dfs(k+1); if (flag) return;
}
int main(){
    for (int i=1;i<=8;i++)
        for (int j=0;j<=2;j++) scanf("%I64d",&x[i][j]); flag=0;
    for (int i=0;i<=2;i++) y[1][i]=x[1][i];
    dfs(2);
    if (flag==0) cout<<"NO"<<endl; return 0;
}