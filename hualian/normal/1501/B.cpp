#include<bits/stdc++.h>
#define reg register
#define For(i,a,b) for(reg int i=(a),i##END=(b);i<=i##END;i++)
using namespace std;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=2e5+10;
int a[N],b[N],s;
signed main(){
	int t=read();
	while(t--){
		int n=read();
		s=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			b[max(1,i-a[i]+1)]++,b[i+1]--;
		}
		for(int i=1;i<=n;i++){
			s+=b[i];
			printf("%d ",(s>0));
		}
		for(int i=1;i<=n+1;i++)b[i]=0;
		puts("");
	}
	return 0;
}