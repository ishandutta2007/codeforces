#include<iostream>
#include<cstdio>
using namespace std;
int n,x,y,d;
int read(){
	int rex=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;char ch=getchar();}
	while(ch>='0'&&ch<='9'){rex=rex*10+ch-'0';ch=getchar();}
	return rex*f;
}
void solve(){
	cin>>n>>x>>y>>d;
	int ans=2e9;
	if((y-x)%d==0){
		if(x>y)swap(x,y);
		printf("%d\n",(y-x)/d);
		return;
	}
	if((y-1)%d==0){
		ans=(y-1)/d+(x-1)/d+((x-1)%d!=0);
	}
	if((n-y)%d==0){
		ans=min(ans,(n-y)/d+(n-x)/d+((n-x)%d!=0));
	}
	if(ans!=2e9)printf("%d\n",ans);
	else printf("-1\n");
}
int main(){
	int t=read();
	for(int i=1;i<=t;++i)solve();
	return 0;
}
/*
1
5 3 1 4
*/