#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,k;
int a[M],b[M];
void work(){
	cin>>n>>k;
	for(int i=n-k+1;i<=n;++i)cin>>a[i];
	if(k==1){
		cout<<"YES\n";
		return;
	}
	for(int i=n-k+2;i<=n;++i){
		b[i]=a[i]-a[i-1];
		if(b[i]<b[i-1]&&i>n-k+2){
			cout<<"NO\n";
			return;
		}
	}
	int x=a[n-k+1],y=b[n-k+2];
	if(1ll*y*(n-k+1)<x){
		cout<<"NO\n";
	}
	else cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 1
4
*/