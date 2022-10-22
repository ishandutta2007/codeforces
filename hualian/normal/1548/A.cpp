#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[N];
signed main(){//printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	int n=read(),m=read();
	for(int i=1;i<=m;i++){
		int a=read(),b=read();
		if(a>b)swap(a,b);
		to[a]++; 
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(!to[i])ans++;
	int k=read();
	while(k--){
		int op=read();
		if(op==1){
			int x=min(read(),read());
			if(!to[x])ans--;
			to[x]++;
		}if(op==2){
			int x=min(read(),read());
			if(to[x]==1)ans++;
			to[x]--;
		}if(op==3)cout<<ans<<endl;
	}
	return 0;
}