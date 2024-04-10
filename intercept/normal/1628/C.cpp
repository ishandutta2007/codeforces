#include<bits/stdc++.h>
using namespace std;
int n,s;
int a[1009][1009],b[1009][1009];
void get(int i,int j){
	s^=a[i][j];
	b[i-1][j]=b[i+1][j]=b[i][j-1]=b[i][j+1]=1;
}
void work(){
	s=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)scanf("%d",&a[i][j]),b[i][j]=0;
	}
	if(n&2){
		for(int i=1;i<=n;i+=4)get(1,i),get(1,i+1);
	}
	else {
		for(int i=2;i<=n;i+=4)get(1,i),get(1,i+1);
	}
	for(int i=2;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(!b[i-1][j]){
				if(!b[i-1][j+1]&&j+1<=n)get(i,j),get(i,j+1),j++;
				else get(i,j),get(i+1,j);
			}
		}
	}
	printf("%d\n",s);
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}