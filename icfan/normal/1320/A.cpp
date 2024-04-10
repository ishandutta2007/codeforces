#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn=200000;
typedef long long ll;
int b[Maxn+5];
int lst[Maxn+5];
ll sum[Maxn+5];
int n;
map<int,int> mp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(mp.count(i-b[i])==0){
			lst[i]=0;
		}
		else{
			lst[i]=mp[i-b[i]];
		}
		mp[i-b[i]]=i;
	}
	for(int i=n;i>0;i--){
		sum[i]+=b[i];
		sum[lst[i]]+=sum[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,sum[i]);
	}
	cout<<ans<<endl;
	return 0;
}