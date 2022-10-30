#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m;
ll sum,res;
map<ll,int> mp;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(!k){j=i;continue;}
		sum+=k;
		if(!sum){
			j=max(j,1);
		}
		if(mp[sum]){j=max(j,mp[sum]+1);}
		mp[sum]=i;
		res+=i-j;
	}
	printf("%lld",res);
}