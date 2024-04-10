#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
#define mod 998244353
int a[N],b[N],t,n,cnt,i;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;cnt=0;
		for(i=1;i<=n;++i){
			cin>>a[i];
			if(a[i]==0)--i,--n,++cnt;
		}
		while(n>1){
			int q=0;
			if(cnt)--cnt;
			else q=-1;
			for(i=n;i;--i){
				a[i]-=a[i-1];
			}
			for(i=1;i<=n;++i){
				if(!a[i])++cnt;
				else b[++q]=a[i];
			}
			sort(b+1,b+q+1);
			n=q;
			for(i=1;i<=q;++i)a[i]=b[i];
		}
		if(!n)cout<<0<<"\n";
		else cout<<a[1]<<"\n";
	}
}