#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=1e6+9;
int a[M];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	ll k;
	cin>>n>>k;
	for(int i=1;i<=n;++i)a[i]=i;
	ll sum=1ll*(n+1)*n/2;
	if(sum>k){
		cout<<-1<<"\n";
		return 0;
	}
	for(int i=1;i<(n+1)/2;++i){
		int x=n-i+1,y=x-i;
		if(k>=sum+y)sum+=y,swap(a[i],a[x]);
	}
	for(int i=1;i<n;++i){
		if(a[i]==i&&a[i+1]==i+1&&k>sum){
			swap(a[i],a[i+1]);
			sum++;
		}
	}
	cout<<sum<<endl;
	for(int i=1;i<=n;++i)cout<<i<<" \n"[i==n];
	for(int i=1;i<=n;++i)cout<<a[i]<<" \n"[i==n];
	return 0;
}