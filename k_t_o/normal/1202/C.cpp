#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define N 389002
char s[N];
int f1,f2,fl1,fl2,T,u,v,miu,miv,mau,mav,n;

int main()
{
	T=read();
	while(T--){
		scanf("%s",s+1); n=strlen(s+1);
		
		u=0; v=0; miu=mau=miv=mav=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='W')++v;
			if(s[i]=='S')--v;
			if(s[i]=='D')++u;
			if(s[i]=='A')--u;
			miv=min(miv,v);
			miu=min(miu,u);
			mav=max(mav,v);
			mau=max(mau,u);
		}
		
		if(mau-miu<mav-miv){
			swap(miu,miv);
			swap(mau,mav);
			for(int i=1;i<=n;++i){
				if(s[i]=='W')s[i]='D';
				else if(s[i]=='S')s[i]='A';
				else if(s[i]=='D')s[i]='W';
				else if(s[i]=='A')s[i]='S';
			}
		}
		
		if(mav-miv<=1)goto lll;
		v=0; fl1=fl2=0; f1=f2=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='W')++v;   //     \0   // \\//   //s[0]
			if(s[i]=='S')--v;
			if(v==miv){
				if(f2)fl2=1;
				f1=1;
			}
			if(v==mav){
				if(f1)fl1=1;
				f2=1;
			}
		}
		if(!miv)fl1=1;if(!mav)fl2=1;
		if(!(fl1&fl2)){
			printf("%lld\n",(long long)(mau-miu+1)*(mav-miv));
			continue;
		}
		
		lll:;
		
		if(mau-miu<=1)goto llll;  
		u=0; fl1=fl2=0; f1=f2=0;
		for(int i=0;i<=n;++i){
			if(s[i]=='D')++u;
			if(s[i]=='A')--u;
			if(u==miu){
				if(f2)fl2=1;
				f1=1;
			}
			if(u==mau){
				if(f1)fl1=1;
				f2=1;
			}
		}
		if(!miu)fl1=1;if(!mau)fl2=1;
		if(!(fl1&fl2)){
			printf("%lld\n",(long long)(mau-miu)*(mav-miv+1));
			continue;
		}
		llll:;
		printf("%lld\n",(long long)(mau-miu+1)*(mav-miv+1));
	}
}