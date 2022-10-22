/*********************************************************************
 * SourceQingyu-math
 * ProblemCF1368D
 * Authorhydd
 * Date2020/10/23
*********************************************************************/
#include<cstdio>
using namespace std;
typedef long long ll;
int n,x,cnt[25]; ll ans;
const int bufsize=1<<20;
char Getchar(){
	static char now[bufsize],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,bufsize,stdin);
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
	n=read();
	for (int i=1;i<=n;i++){
		x=read();
		for (int j=0;j<20;j++)
			if (x&(1<<j)) cnt[j]++;
	}
	for (int i=1;i<=n;i++){
		x=0;
		for (int j=0;j<20;j++)
			if (cnt[j]){
				cnt[j]--;
				x|=(1<<j);
			}
		ans+=1ll*x*x;
	}
	printf("%lld\n",ans);
	return 0;
}