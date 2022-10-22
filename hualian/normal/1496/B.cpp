#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+9;
int a[N],mex,MAX;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
signed main(){
	int t=read();
	while(t--){
		int n=read(),k=read();
		MAX=0;
		mex=-1;
		for(int i=1;i<=n;i++)
			a[i]=read();
		sort(a+1,a+1+n);
		int cnt=0;
		a[0]=-1;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1])continue;
			if(a[i]!=a[i-1]+1&&mex==-1)mex=a[i-1]+1;
			cnt++;
		}
		MAX=a[n];
		if(mex==-1)mex=a[n]+1;
		if(mex==MAX+1){
			printf("%lld\n",k+cnt);
			continue;
		}
		int num=(mex+MAX+1)/2,f=1;
		for(int i=1;i<=n;i++)if(a[i]==num)f=0;
		printf("%lld\n",cnt+f*(k>=1));
			
	}
	return 0;
}