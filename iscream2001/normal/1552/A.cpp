#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=1e5+10;
const LL INF=1e18;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}


void init(){
	return;
}
int n;
int a[N],b[N];
char s[50];
void MAIN(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'a';
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int ans=0;
	for(int i=1;i<=n;++i){
		if(a[i]!=b[i]) ++ans;
	}
	printf("%d\n",ans);
//	cout<<cntA<<" "<<cntB<<endl;
	return;
}
int main(){
//	freopen("1.in","r",stdin);
	init();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;	
}
/*
735134400
*/