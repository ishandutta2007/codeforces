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
int sum;
int a[N];
int main(){
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
	dp[0]=1;
	for(int i=1;i<=n;i++)for(int j=N-1;j>=a[i];j--)
		dp[j]|=(dp[j-a[i]]);
	if(sum%2){puts("0");return 0;}
	if(dp[sum/2]==0){puts("0");return 0;}
	while(1){
		for(int i=1;i<=n;i++){
			if(a[i]%2){cout<<1<<endl<<i<<endl;return 0;}
			a[i]/=2; 
		}
	}
	return 0;
}