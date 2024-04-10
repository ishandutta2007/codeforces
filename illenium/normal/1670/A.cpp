#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,a[N];
void Solve(){
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]<0)++cnt;
	}
	for(int i=1;i<=n;++i){
		a[i]=abs(a[i]);
		if(i<=cnt)a[i]=-a[i];
	}
	for(int i=1;i<n;++i){
		if(a[i]>a[i+1]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}