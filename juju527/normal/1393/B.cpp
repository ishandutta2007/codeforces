#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int n,q;
	n=read();
	for(int i=1;i<=n;i++)t[read()]++;
	int num2=0,num4=0;
	for(int i=1;i<=1e5;i++)
		num4+=t[i]/4,num2+=t[i]/2;
	q=read();
	for(int i=1;i<=q;i++){
		char opt;
		int x;
		cin>>opt;x=read();
		if(opt=='+'){
			t[x]++;
			if(t[x]%2==0)num2++;
			if(t[x]%4==0)num4++;
		}
		else{
			t[x]--;
			if(t[x]%4==3)num4--;
			if(t[x]%2==1)num2--;
		}
		if(num4>=2||(num2-2*num4>=2&&num4>=1))puts("YES");
		else puts("NO");
	}
	return 0;
}