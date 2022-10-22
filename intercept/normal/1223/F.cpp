#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int M=300009;
int n;
int a[M],p[M],sum[M];
set<pii>s[M];
ll ans;
void work(){
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),s[i].clear(),sum[i]=0;
	for(int i=1;i<=n;++i){
		auto it=s[i-1].upper_bound(make_pair(a[i],n));
		if(it==s[i-1].begin()||(*(--it)).fi!=a[i]){
			p[i]=i;
		}
		else{
			auto o=*it;
			p[i]=o.se-1;
			swap(s[i],s[o.se-1]);
			s[i].insert(make_pair(a[o.se-1],o.se-1));
			sum[i]=sum[o.se-1]+1;
			ans+=sum[i];
		}
		s[i].insert(make_pair(a[i],i));
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
4
1 1 2 2
*/