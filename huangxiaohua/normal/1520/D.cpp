#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)
int i,j,n,m,k,t;
ll res;
unordered_map<int,int> mp;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		mp.clear();res=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			res+=mp[k-i];mp[k-i]++;
		}
		printf("%lld\n",res);
	}
}