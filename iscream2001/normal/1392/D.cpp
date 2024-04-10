#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int N=2e5+10;
const int inf=1e9+10;
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
int n,d,mx;
LL K;
int ans;
int a[N];
char s[N];
int f[4][4][N];
void umin(int &x,int y){
	if(x>y) x=y;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;++i) 
			if(s[i]=='L') a[i]=0;
			else a[i]=1;
		for(int i=0;i<4;++i){
			for(int j=0;j<4;++j)
				for(int k=0;k<=n;++k) f[i][j][k]=inf;
		}
		int v=a[1]*2+a[2],u;
		for(int i=0;i<4;++i){
			u=0;
			if((i&1)!=(v&1)) ++u;
			if((i>>1)!=(v>>1)) ++u;
			f[i][i][2]=u;
		}
		for(int k=2;k<n;++k){
			for(int i=0;i<4;++i){
				for(int j=0;j<4;++j){
					if(f[i][j][k]==inf) continue;
					v=(j<<1)|a[k+1];
					if(v!=0&&v!=7){
						umin(f[i][(v&3)][k+1],f[i][j][k]);
					}
					v=(j<<1)|(a[k+1]^1);
					if(v!=0&&v!=7){
						umin(f[i][(v&3)][k+1],f[i][j][k]+1);
					}
				}
			}
		}
		ans=inf;
		for(int i=0;i<4;++i){
			for(int j=0;j<4;++j){
				v=j*4+i;
				u=v/2;
				if(u==0||u==7) continue;
				u=(v&7);
				if(u==0||u==7) continue;
				umin(ans,f[i][j][n]);
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}