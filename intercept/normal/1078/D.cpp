#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int M=3e5+9;
int n;
int a[M],id[2][M][19],va[2][M][19];
int add(int x,int y,int o){
	return o?(x+a[x]<y+a[y]?y:x):(x-a[x]<y-a[y]?x:y);
}
int get(int l,int r,int o){
	int k=log2(r-l+1);
	return add(id[o][l][k],id[o][r-(1<<k)+1][k],o);
}
pii ask(int l,int r,int k){
	int x=get(l,r,0),y=get(l,r,1);
	return mp(min(va[0][x][k],va[0][y][k]),max(va[1][x][k],va[1][y][k]));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[n+i]=a[n+n+i]=a[i];
	if(n==1){
		puts("0");
		return 0;
	}
	n*=3;
	for(int i=1;i<=n;++i){
		for(int o=0;o<2;++o)id[o][i][0]=i;
		va[0][i][0]=max(i-a[i],1);
		va[1][i][0]=min(i+a[i],n);
	}
	for(int j=1;j<19;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			for(int o=0;o<2;++o)id[o][i][j]=add(id[o][i][j-1],id[o][i+(1<<j-1)][j-1],o);
		}
	}
	for(int j=1;j<19;++j){
		for(int i=1;i<=n;++i){
			pii o=ask(va[0][i][j-1],va[1][i][j-1],j-1);
			va[0][i][j]=o.first;
			va[1][i][j]=o.second;
		}
	}
	for(int i=n/3+1;i<=n/3*2;++i){
		int l=i,r=i,v=1;
		for(int j=18;j>=0;--j){
			pii o=ask(l,r,j);
			if(o.second-o.first+1<n/3)l=o.first,r=o.second,v+=1<<j;
		}
		printf("%d ",v);
	}
	return 0;
}