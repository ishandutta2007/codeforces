#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,k;
signed main(){
	int t=read();
	while(t--){
		n=read(),k=read()-1;
		if(n<62&&k>>n-1){puts("-1");continue;}
		for(int i=1,nt=1;i<=n;nt++,i=nt){
			while(nt<n&&n-nt<=62&&(k&(1ll<<n-nt-1))&&(++nt));
			for(int j=nt;j>=i;j--)printf("%lld ",j);
		}puts("");
	}
	
	return 0;
}