#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int dp[200010];
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N],s[N];
int main(){
	int t=read();
	while(t--){
		int n=read();
		for(int i=1;i<=n;i++)a[i]=read(),s[i]=s[i-1]^a[i];
		if(s[n]==0){
			int f=0;
			for(int i=1;i<n;i++)
				if(s[i]==(s[n]^s[i])){f=1;break;}
			puts(f?"YES":"NO");
			continue;
		}else{
			int f=0;
			for(int i=1;i<n;i++)for(int j=i+1;j<n;j++){
				int A=s[i],B=s[j]^s[i],C=s[n]^s[j];
				if(A==B&&B==C){
					f=1;break;
				}
			}
			puts(f?"YES":"NO");
			continue;
		}
	}
	return 0;
}