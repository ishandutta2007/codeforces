#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=300000;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N],len;
int _cnt[N<<1];
int *cnt=&_cnt[N];
signed main(){
	int t=read();
	while(t--){
		int n=read();
		int ans=0;
		for(int i=1;i<=n;i++)a[i]=read(),cnt[a[i]-i]++;
		for(int i=-n;i<=n;i++)ans+=cnt[i]*(cnt[i]-1)/2;
		cout<<ans<<endl; 
		for(int i=1;i<=n;i++)cnt[a[i]-i]--;
	}
	return 0;
}