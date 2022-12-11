#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=501000;
int n;
int a[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	int T=read();
	while(T--){
		n=read();
		int xsum=0;
		for(int i=1;i<=n;++i){
			a[i]=read();xsum^=a[i];
		}
		if(!xsum){puts("Yes");}
		else{
			int cnt=0,now=0;
			for(int i=1;i<=n;++i){
				now^=a[i];
				if(now==xsum)++cnt,now=0;
			}
			puts(cnt>=2?"Yes":"No");
		}
	}
	return 0;
}