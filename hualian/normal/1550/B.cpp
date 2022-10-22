#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1010;
char c[N];
int t,ans;
signed main(){
	int T;cin>>T;
	while(T--){
		int n,a,b;
		cin>>n>>a>>b;
		scanf("%s",c+1);
		ans=a*n;
		if(b>=0)ans+=n*b;
		else{
			t=1;
			for(int i=2;i<=n;i++)
				if(c[i]!=c[i-1])t+=1;
			t/=2;t++; ans+=t*b;
		}
		printf("%lld\n",ans);
	}
	return 0;
}