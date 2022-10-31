#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500],b[100500];
int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	if(m==1){
		cout<<"YES";
		return 0;
	}
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++){
		cin>>b[i];
		if(a[1]&&a[i]&&b[i]&&i>=m)k=1;
	}
	if(a[1]&&a[m]){
		cout<<"YES";return 0;
	}
	if(k&&b[m]){
		cout<<"YES";return 0;
	}
	cout<<"NO";
}