#include<bits/stdc++.h>
#define reg register
using namespace std;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=3e5+10;
char a[N],b[N];
int c[N],ok[N];
signed main(){
	int t=read();
	ok[0]=1;
	while(t--){
		int n=read();
		scanf("%s%s",a+1,b+1);
		int c0=0,c1=0,cnt=0,ans=1;
		for(int i=1;i<=n;i++){
			if(a[i]=='0')c0++;
			else c1++;
			if(c0==c1)ok[i]=1;
			if(a[i]!=b[i])cnt++;
			else ans&=(cnt==0||(ok[i-1]&&ok[i-1-cnt])),cnt=0;
		}
		if(cnt)ans&=(ok[n]&&ok[n-cnt]);
		puts(ans?"YES":"NO");
		for(int i=1;i<=n;i++)ok[i]=0,c[i]=0;
	}
	return 0;
}