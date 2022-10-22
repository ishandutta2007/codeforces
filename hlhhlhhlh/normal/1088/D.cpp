// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
int c,d,a,b,ans1,ans2,fla;
int cc,dd;
int ans[maxn],anss[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
//	cc=3; dd=1;
	for (i=29;i>=0;i--){
		if (fla==0){
			printf("? %d %d\n",c,d); fflush(stdout);
			ans1=read();
/*			if ((cc^c)>(dd^d)) ans1=1;
			if ((cc^c)==(dd^d)) ans1=0;
			if ((cc^c)<(dd^d)) ans1=-1;
*/			if (ans1==0) ans1=1;
		}
		c=c+(1<<i); d=d+(1<<i);
		printf("? %d %d\n",c,d); fflush(stdout);
		ans2=read();
/*			if ((cc^c)>(dd^d)) ans2=1;
			if ((cc^c)==(dd^d)) ans2=0;
			if ((cc^c)<(dd^d)) ans2=-1;
*/		if (ans2==0) ans2=1;
		if (ans1==ans2){
			fla=1;
			ans[i]=0;
		}
		else{
			fla=0; c=c-(1<<i);
			if (ans1==1) ans[i]=1;
			else ans[i]=-1; 
		}
	}
	c=0; d=0;
	for (i=29;i>=0;i--){
		if (ans[i]!=0){
			c=c+(1<<i);
		}
		if (ans[i]==0){
			c=c+(1<<i);
			printf("? %d %d\n",c,d); fflush(stdout);
			ans2=read();
/*			if ((cc^c)>(dd^d)) ans2=1;
			if ((cc^c)==(dd^d)) ans2=0;
			if ((cc^c)<(dd^d)) ans2=-1;
*/			if (ans2==0) ans2=1;
			if (ans2==1) ans[i]=2;
			else ans[i]=0;
			c=c-(1<<i);
		}
	}
	c=0; d=0;
	for (i=29;i>=0;i--){
		if ((ans[i]==0)||(ans[i]==1)) c=c+(1<<i);
		if ((ans[i]==0)||(ans[i]==-1)) d=d+(1<<i);
	}
	printf("! %d %d\n",c,d); fflush(stdout);
	return 0;
}