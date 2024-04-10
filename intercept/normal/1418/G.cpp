#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+9;
int n,l=1,a[M],app[M],cnt[M];
ll f[M],h[M],ans;
map<ll,int>mp;
mt19937 rnd(time(NULL));
int main(){
	scanf("%d",&n);mp[0]=1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),f[i]=1ll*rnd()*rnd();
	for(int i=1;i<=n;++i){
		app[a[i]]++;cnt[a[i]]++;
		while(app[a[i]]>3)mp[h[l-1]]--,app[a[l++]]--;
		if(cnt[a[i]]%3)h[i]=h[i-1]+f[a[i]];
		else h[i]=h[i-1]-f[a[i]]-f[a[i]];
		ans+=mp[h[i]]++;
	}
	printf("%lld\n",ans);
	return 0;
}