#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=200010;
int n,m;
int sl,sr,hl,hr;
int slfir,sllas,srfir,srlas;
int hlfir,hllas,hrfir,hrlas;
long long ans;
char op[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read();T;--T){
		scanf("%s",op+1);
		n=strlen(op+1);
		sl=sr=hl=hr=0;
		slfir=sllas=srfir=srlas=0;
		hlfir=hllas=hrfir=hrlas=0;
		for(register int i=1,x=0,y=0;i<=n;++i){
			if(op[i]=='W'){
				++x;
				if(x>hr){
					hr=x;hrfir=i;
				}
				if(x==hr)
					hrlas=i;
			}
			else if(op[i]=='A'){
				--y;
				if(y<sl){
					sl=y;slfir=i;
				}
				if(y==sl)
					sllas=i;
			}
			else if(op[i]=='S'){
				--x;
				if(x<hl){
					hl=x;hlfir=i;
				}
				if(x==hl)
					hllas=i;
			}
			else{
				++y;
				if(y>sr){
					sr=y;srfir=i;
				}
				if(y==sr)
					srlas=i;
			}
		}
		ans=1ll*(sr-sl+1)*(hr-hl+1);
		if(sr-sl>1&&(sllas<srfir||srlas<slfir))ans=min(ans,1ll*(sr-sl)*(hr-hl+1));
		if(hr-hl>1&&(hllas<hrfir||hrlas<hlfir))ans=min(ans,1ll*(sr-sl+1)*(hr-hl));
		printf("%lld\n",ans);
	}
    return 0;
}