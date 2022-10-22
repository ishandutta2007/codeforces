#include<bits/stdc++.h>
using namespace std;
const int M=1<<18;
int k,m;
int f[M],c[M][2],val[M];
char s[M];
int main(){
	scanf("%d%s%d",&k,s+1,&m);
	for(int i=1;i<1<<k;++i){
		int fa=(1<<k)-i;
		c[fa][0]=(1<<k)-(i<<1|1);
		c[fa][1]=(1<<k)-(i<<1);
		if(c[fa][0]<0)c[fa][0]=0;
		if(c[fa][1]<0)c[fa][1]=0;
		f[c[fa][0]]=f[c[fa][1]]=fa;
	}
	val[0]=1;
	for(int i=1;i<1<<k;++i){
		if(s[i]=='0')val[i]=val[c[i][0]];
		if(s[i]=='1')val[i]=val[c[i][1]];
		if(s[i]=='?')val[i]=val[c[i][0]]+val[c[i][1]];
	}
	for(int i=1,id;i<=m;++i){
		char t[5];
		scanf("%d%s",&id,t);
		s[id]=t[0];
		while(id){
			if(s[id]=='0')val[id]=val[c[id][0]];
			if(s[id]=='1')val[id]=val[c[id][1]];
			if(s[id]=='?')val[id]=val[c[id][0]]+val[c[id][1]];
			id=f[id];
		}
		printf("%d\n",val[(1<<k)-1]);
	}
	return 0;
}