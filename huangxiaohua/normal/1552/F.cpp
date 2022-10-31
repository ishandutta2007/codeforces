#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,l[200500],r[200500],a[200500];
ll f[200500],pre[200500],res;
set<int> s;
map<int,int> mp;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&r[i],&l[i],&a[i]);
		mp[r[i]]=i;
		s.insert(r[i]);
	}
	res=r[n]+1;
	for(i=1;i<=n;i++){
		auto it=s.lower_bound(l[i]);
		f[i]=(r[i]-l[i]);
		k=mp[*it];
		f[i]=(f[i]+M+pre[i-1]-pre[k-1])%M;
		pre[i]=(pre[i-1]+f[i])%M;
		
		if(a[i]){
			res=(res+f[i])%M;
		}
	}
	printf("%lld",res%M);
}//