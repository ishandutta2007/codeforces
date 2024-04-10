#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+9;
const int p=998244353;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int sum=0;
signed main(){
	int t=read();
	while(t--){
		int n=read();int ans=0,sum=0,res=0,cnt=0;
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)if(a[i]>=0)cnt++;
		if(a[1]>0)ans+=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]>=0){
				ans+=(a[i]-a[i-1])*(i-1)*(cnt-i+1);
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++)
			if(a[i]<0)cnt++,res+=a[i];
		for(int i=1;i<=n;i++){
			if(a[i]>0&&res){
				ans+=cnt*(res-a[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}