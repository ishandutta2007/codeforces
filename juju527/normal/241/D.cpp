#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5,maxp=5e4+5;
int n,mod,B;
int a[maxn],p[maxn];
int d[25];
vector<int>pos;
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
inline int add(int x){
	if(x>=mod)x-=mod;
	return x;
}
void check(int s){
	int sum=0,x=0,num=0;
	for(int i=0;i<B;i++)if(s&(1<<i))x=x^(i+1),num++;
	if(num==0||x)return ;
	for(int i=0;i<B;i++){
		if(s&(1<<a[pos[i]]-1))
			sum=add(1ll*d[a[pos[i]]]*sum%mod+a[pos[i]]%mod);
	}
	if(sum==0&&x==0){
		puts("Yes");
		printf("%d\n",num);
		for(int i=0;i<B;i++)if(s&(1<<a[pos[i]]-1))printf("%d ",pos[i]);cout<<endl;
		exit(0);
	}
	return ;
}
void dfs(int s,int x){
	if(x==B+1){check(s);return ;}
	dfs(s,x+1);
	dfs(s^(1<<x-1),x+1);
	return ;
}
int main(){
	n=read();mod=read();
	for(int i=1;i<=n;i++)p[a[i]=read()]=i;
	B=min(n,24);
	for(int i=1;i<=B;i++)pos.push_back(p[i]);
//	for(int i=0;i<B;i++)cout<<pos[i]<<" ";cout<<endl;
	for(int i=1;i<=9;i++)d[i]=10;
	for(int i=10;i<=24;i++)d[i]=100;
	sort(pos.begin(),pos.end());
//	for(int i=0;i<pos.size();i++)cout<<pos[i]<<" ";cout<<endl;
	dfs(0,1);
	puts("No");
	return 0;
}