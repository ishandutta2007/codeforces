/*********************************************************************
 * SourceHLSC
 * ProblemCF627C/CF635E
 * Authorhydd
 * Date2020/10/29
*********************************************************************/
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int d,m,n,b[210000];
int top,s[210000];
struct node{
	int x,p;
	bool operator<(const node &a) const{ return x<a.x;}
} a[210000];
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
int main(){
	d=read(); m=read(); n=read();
	for (int i=0;i<n;i++){
		a[i].x=read(); a[i].p=read();
	}
	sort(a,a+n); a[n].x=d; a[n].p=0;
	
	top=1; s[top]=n;
	for (int i=n-1;i>=0;i--){
		while (a[s[top]].p>=a[i].p) top--;
		b[i]=s[top]; s[++top]=i;
	}
	
	int res=m-a[0].x; ll ans=0;
	for (int i=0;i<n&&res>=0;i++){
		if (a[b[i]].x-a[i].x>res){
			int d=min(a[b[i]].x-a[i].x,m)-res;
			res+=d; ans+=1ll*d*a[i].p;
		}
		res-=a[i+1].x-a[i].x;
	}
	if (res<0) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}