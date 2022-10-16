#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
ll T,n,i,a[N],s[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i){
			s[i]=a[i]-a[i-1];
		}
		ll qwq=0;
		for(i=2;i<=n;++i)if(s[i]<0){
			s[1]+=s[i];
			qwq-=s[i];
			s[i]=0;
		}
		for(i=1;i<=n;++i)qwq+=abs(s[i]);
		cout<<qwq<<"\n\n";
	}
}