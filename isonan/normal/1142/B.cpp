#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,q,last[200001][21],p[200001],a[200001],pos[200001],lastexi[200001],st[200001][21],loga[200001];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",p+i),pos[p[i]]=i;
	for(int i=1;i<=m;i++){
		scanf("%d",a+i);
		int tem=pos[a[i]];
		if(tem>1)tem--;
		else tem=n;
		last[i][0]=lastexi[p[tem]];
		lastexi[a[i]]=i;
	}
	for(int j=1;j<=20;j++)
		for(int i=1;i<=m;i++)
			last[i][j]=last[last[i][j-1]][j-1];
	for(int i=1;i<=m;i++){
		int tem=n-1,nowpos=i;
		for(int j=20;~j;--j)
			if((1<<j)<=tem)tem-=(1<<j),nowpos=last[nowpos][j];
		st[i][0]=nowpos;
	}
	for(int j=1;(1<<j)<=m;j++)
		for(int i=1;i+(1<<j)-1<=m;i++)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	loga[0]=-1;
	for(int i=1;i<=m;i++)loga[i]=loga[i>>1]+1;
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
		int k=loga[r-l+1];
		printf("%d",(max(st[l][k],st[r-(1<<k)+1][k])>=l)?1:0);
	}
}