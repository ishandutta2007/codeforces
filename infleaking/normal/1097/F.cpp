#include<cstdio>
#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;
const int N=1e5+10,M=7010;
bitset<M> s[N],u[M],Ag;
int miu[N],n,m;
int p[M],p1,flag[M];
int main(){
	cin>>n>>m;
	miu[1]=1;
	for (int i=2;i<=7000;i++){
		if (!flag[i]){
			p[++p1]=i;
			miu[i]=-1;			
		}
		for (int j=1;j<=p1;j++){
			int x=i*p[j];
			if (x>7000)break;
			flag[x]=1;
			miu[x]=-miu[i];
			if (i%p[j]==0){
				miu[x]=0;
				break;
			}
		}
	}
	for (int i=1;i<=7000;i++)
	for (int j=i;j<=7000;j+=i){
		if (miu[j/i])u[i][j]=1;
	}
	while (m--){
		int ty,x,v,y,z;
		scanf("%d%d",&ty,&x);
		if (ty==1){
			scanf("%d",&v);
			s[x]=0;
			for (int i=1;i*i<=v;i++)
				if (v%i==0)s[x][i]=s[x][v/i]=1;
		}
		if (ty==2){
			scanf("%d%d",&y,&z);
			s[x]=s[y]^s[z];
		}
		if (ty==3){
			scanf("%d%d",&y,&z);
			s[x]=s[y]&s[z];
		}
		if (ty==4){
			scanf("%d",&v);
			Ag=u[v]&s[x];
			printf("%d",Ag.count()&1);
		}
	}
}