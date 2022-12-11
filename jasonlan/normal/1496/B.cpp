#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[101000],cnt;
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
		int n=read(),k=read();
		for(int i=0;i<n;++i)
			a[i]=read();
		a[n]=0;
		sort(a,a+n);
		cnt=n;
		for(int i=0,p=0;i<n&&k;++p){
			while(a[i]<p&&i<n)++i;
			if(p==a[n-1]+1){
				cnt+=k;break;
			}
			else if(a[i]==p)continue;
			else{
				if((a[n-1]+1+p)/2!=p){
					k=0;
					int pos=lower_bound(a,a+n,(a[n-1]+1+p)/2)-a;
					if(a[pos]==(a[n-1]+1+p)/2);
					else ++cnt;
					break;
				}
				else --k;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}