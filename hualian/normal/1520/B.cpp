#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N],len;
signed main(){
	int t=read();
	for(int i=1;i<=9;i++){
		int res=0;
		for(int j=1;j<=9;j++){
			res=res*10+i;
			a[++len]=res;	
		}
	}
	while(t--){
		int n=read(),ans=0;
		for(int i=1;i<=len;i++){
			if(n>=a[i])ans++;
		}cout<<ans<<endl;
	}
	return 0;
}