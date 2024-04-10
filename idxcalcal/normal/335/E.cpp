#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
typedef long long ll;
typedef pair<int,int> pii;
char s[10];
int n,H,pw[35];
double ipw[35];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	scanf("%s%d%d",s,&n,&H);
	if(s[0]=='B'){
		cout<<n;
		return 0;
	}
	pw[0]=ipw[0]=1;
	for(ri i=1;i<=H;++i)pw[i]=pw[i-1]*2,ipw[i]=1.0/pw[i];
	double res=0,mt;
	for(ri h=1;h<=H;++h){
		mt=ipw[h]*ipw[h];
		for(ri len=1;len<n;++len){
			res+=(n-len)*mt*(pw[h]-pw[h-1]*(1.0+(double)(len-1)/(double)(pw[h]-1)));
			mt*=1-ipw[h];
		}
	}
	printf("%.10lf",res+n);
	return 0;
}