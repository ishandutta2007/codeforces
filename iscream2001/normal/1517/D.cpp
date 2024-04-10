#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL P=998244353;
const int INF=1e9;
const int N=1e5+10;
int read(){
int x=0,f=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
return x*f;
}
void print(LL x){
if(x>9) print(x/10);
putchar(x%10+'0');
}
int n,m,K;
int r[510][510];
int d[510][510];
int vis[510][510][15];
int f[510][510][15];
int cnt;
int L,R;
struct Node{
int x,y,z;
}Q[1000];
int ans;
void get_min(int x,int y,int z,int w){
if(vis[x][y][z]!=cnt){
vis[x][y][z]=cnt;
f[x][y][z]=INF;
Q[++R]=(Node){x,y,z};
}
f[x][y][z]=min(f[x][y][z],w);
return;
}
void MAIN(){
memset(f,61,sizeof(f));
scanf("%d%d%d",&n,&m,&K);
for(int i=1;i<=n;++i){
for(int j=1;j<m;++j){
scanf("%d",&r[i][j]);
}
}
for(int i=1;i<n;++i){
for(int j=1;j<=m;++j){
scanf("%d",&d[i][j]);
}
}
if(K&1){
for(int i=1;i<=n;++i){
for(int j=1;j<=m;++j){
printf("-1 ");
}
puts("");
}
return;
}
cnt=0;
K=K/2;
Node A;
for(int i=1;i<=n;++i){
for(int j=1;j<=m;++j){
++cnt;ans=INF;
L=1;R=0;
get_min(i,j,0,0);
while(L<=R){
A=Q[L++];
if(A.z==K){
ans=min(ans,f[A.x][A.y][A.z]);
continue;
}
if(A.x>1) get_min(A.x-1,A.y,A.z+1,f[A.x][A.y][A.z]+d[A.x-1][A.y]);
if(A.x<n) get_min(A.x+1,A.y,A.z+1,f[A.x][A.y][A.z]+d[A.x][A.y]);
if(A.y>1) get_min(A.x,A.y-1,A.z+1,f[A.x][A.y][A.z]+r[A.x][A.y-1]);
if(A.y<m) get_min(A.x,A.y+1,A.z+1,f[A.x][A.y][A.z]+r[A.x][A.y]);
}
printf("%d ",ans+ans);
}
puts("");
}
return;
}
int main(){
int ttt=1;
while(ttt--) MAIN();
return 0;
}