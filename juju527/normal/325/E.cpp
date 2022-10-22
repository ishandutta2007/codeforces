#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int p[maxn];
int f[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*y;
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main(){
	int n;
	n=read();
	if(n&1){puts("-1");return 0;}
	for(int i=0;i<n;i++)f[i]=i;
	for(int i=0;i<n/2;i++){
		p[i]=2*i;
		p[i+n/2]=2*i+1;
		if(find(i)^find(p[i]))f[find(p[i])]=find(i);
		if(find(i+n/2)^find(p[i+n/2]))f[find(p[i+n/2])]=find(i+n/2);
	}
	for(int i=0;i<n/2;i++){
		if(find(i)^find(i+n/2)){
			swap(p[i],p[i+n/2]);
			f[find(i)]=find(i+n/2);
		}
	}
	int u=0;
	while(1){
		printf("%d ",u);
		u=p[u];
		if(u==0)break;
	}
	cout<<0<<endl;
	return 0;
}