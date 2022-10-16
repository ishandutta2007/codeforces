#include <bits/stdc++.h>
using namespace std; 
long long bigmod(long long a,long long b){
	if(b==0)return 1;
	if(b%2)return ((a%998244353)*bigmod(a,b-1))%998244353;
	else {
		long long c=bigmod(a,b/2);
		return ((c%998244353)*(c%998244353))%998244353;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	long long power[200005];
	long long times[200005];
//	power[0]=1;
//	for(long long i=1;i<=200001;i++)power[i]=(power[i-1]*2)%998244353;
	long long n,m,ti=0;
	long long sum=0;
	char c;
	cin>>n>>m;
	for(long long i=n-1;i>=0;i--){
		cin>>c;
		if(c=='1'){
			times[ti]=i;
			ti++;
		}
	}
	map<long long,long long>cnt;
	cnt[m]=0;
	for(long long i=m-1;i>=0;i--){
		cin>>c;
		cnt[i]=cnt[i+1];
		if(c=='1')cnt[i]++;
	}
	for(long long i=0;i<ti;i++){
		sum+=bigmod(2,times[i])*cnt[(times[i])]%998244353;
		sum%=998244353;
	}
	cout<<sum%998244353<<endl;
}