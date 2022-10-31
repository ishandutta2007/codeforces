#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[6666];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		cout<<n<<'\n';
		for(i=1;i<=n;i++)a[i]=i;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)cout<<a[j]<<' ';
			cout<<'\n';
			swap(a[i],a[i+1]);
		}
	}
}