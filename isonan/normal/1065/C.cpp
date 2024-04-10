#include <cstdio>
#include <iostream>
#define int long long
using namespace std;

int count[200010],n,k,h[200001];
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		count[1]++;
		count[h[i]+1]--;
	}
	for(int i=1;i<=200000;i++)count[i]+=count[i-1];
	for(int i=1;i<=200000;i++)count[i]+=count[i-1];
	int ans=0;
	for(int i=200000;i;i--){
		if(count[i]==n*i&&count[i]==count[200000]){
			puts("0");
			return 0;
		}
	}
	for(int i=200000;i;){
		int l=1,r=i,mid,tem=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(count[i]-count[mid-1]<=k)tem=mid,r=mid-1;
			else l=mid+1;
		}
		i=tem-1;
		ans++;
		if(count[i]==n*i)break;
	}
	cout<<ans;
}