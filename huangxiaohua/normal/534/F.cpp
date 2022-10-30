#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,x[66],nmsl[66],p[10]={1,10,100,1000,10000,100000},a[66],b[66],tmp,res[66][66],hsh0;
short f[11][150500][33],f2[11][150500][33];

void get1(int x,int y){
	int i,j,k,l,m;
	for(i=0;i<y;i++){
		for(j=0;j<p[x];j++){
			for(k=0;k<b(x+1);k++){
				if(f[i][j][k]==-1)continue;
				for(l=0;l<b(x+1);l++){
					if(b[l]!=nmsl[i+1])continue;
					tmp=j;
					for(m=1;m<=x;m++){
						if(b(m)&l&&!(b(m)&k))tmp+=p[m-1];
					}
					f[i+1][tmp][l]=k;
				}
			}
		}
	}
}

void get2(int x,int y){
	int i,j,k,l,m,ii;
	for(ii=y+1;ii>11;ii--){
		i=y+1-ii;
		for(j=0;j<p[x];j++){
			for(k=0;k<b(x+1);k++){
				if(f2[i][j][k]==-1)continue;
				for(l=0;l<b(x+1);l++){
					if(b[l]!=nmsl[ii-1])continue;
					tmp=j;
					for(m=1;m<=x;m++){
						if(b(m)&l&&!(b(m)&k))tmp+=p[m-1];
					}
					f2[i+1][tmp][l]=k;
				}
			}
		}
	}
}

void solve1(int x,int y,int z){
	if(!x)return;
	if(f[x][y][z]==-1)exit(1);
	int tmp=y;
	for(int i=1;i<=n;i++){
		if(z&b(i)){
			res[i][x]=1;
			if(!(f[x][y][z]&b(i)))tmp-=p[i-1];
		}
	}
	solve1(x-1,tmp,f[x][y][z]);
}

void solve2(int x,int y,int z){
	if(x>m)return;
	if(f2[m+1-x][y][z]==-1)exit(1);
	int tmp=y;
	for(int i=1;i<=n;i++){
		if(z&b(i)){
			res[i][x]=1;
			if(!(f2[m+1-x][y][z]&b(i)))tmp-=p[i-1];
		}
	}
	solve2(x+1,tmp,f2[m+1-x][y][z]);
}

void ans(){
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%c",res[i][j]?'*':'.');
		}puts("");
	}
}

int main(){
	memset(f,-1,sizeof(f));
	memset(f2,-1,sizeof(f2));
	f[0][0][0]=0;
	f2[0][0][0]=0;
	for(i=0;i<=31;i++){
		j=i;
		while(j){if(j&1&&(!(j&2)))b[i]++;j>>=1;}
	}
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){scanf("%d",&x[i]);hsh0+=x[i]*p[i-1];}
	for(i=1;i<=m;i++){scanf("%d",&nmsl[i]);}
	get1(n,min(m,10));
	if(m<=10){
		for(i=0;i<b(n+1);i++){
			if(f[m][hsh0][i]!=-1){
				solve1(m,hsh0,i);goto aaa;
			}
		}
		return 1;
		aaa:;
		ans();
		return 0;
	}
	get2(n,m);
	for(i=0;i<=100000;i++){
		for(j=0;j<b(n+1);j++){
			if(f2[m-10][i][j]==-1)continue;
			for(k=0;k<b(n+1);k++){
				tmp=hsh0-i;
				for(int l=1;l<=n;l++){
					if(b(l)&j&&b(l)&k)tmp+=p[l-1];
				}
				if(tmp<=0||f[10][tmp][k]==-1)continue;
				solve1(10,tmp,k);
				solve2(11,i,j);
				ans();
				return 0;
			}
		}
	}
	return 1;
}