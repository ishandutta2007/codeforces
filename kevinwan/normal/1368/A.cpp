#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
int main(){
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#else
		cin.tie(0);
		cin.sync_with_stdio(0);
	#endif
	int tc;
	cin>>tc;
	while(tc--){
		ll a,b,n;
		cin>>a>>b>>n;
		if(a<b)swap(a,b);
		int ans=0;
		while(a<=n)b+=a,swap(a,b),ans++;
		printf("%d\n",ans);
	}
}