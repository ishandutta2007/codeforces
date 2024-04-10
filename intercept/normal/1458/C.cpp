#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1009][1009],b[1009][1009],c[3],id[3],v[3];
char s[100009];
void work(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%s",s+1);
	id[0]=0,id[1]=1,id[2]=2;
	v[0]=v[1]=v[2]=0;
	for(int i=1;i<=m;++i){
		if(s[i]=='L')v[id[1]]--;
		if(s[i]=='R')v[id[1]]++;
		if(s[i]=='U')v[id[0]]--;
		if(s[i]=='D')v[id[0]]++;
		if(s[i]=='I')swap(id[1],id[2]);
		if(s[i]=='C')swap(id[0],id[2]);
	}
	v[0]=(v[0]%n+n)%n;
	v[1]=(v[1]%n+n)%n;
	v[2]=(v[2]%n+n)%n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			c[0]=(i+v[0]-1)%n+1,c[1]=(j+v[1]-1)%n+1,c[2]=(a[i][j]+v[2]-1)%n+1;
			b[c[id[0]]][c[id[1]]]=c[id[2]];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)printf("%d ",b[i][j]);
		puts("");
	}
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}