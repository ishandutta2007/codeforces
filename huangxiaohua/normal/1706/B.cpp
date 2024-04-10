#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500][2];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			a[i][0]=a[i][1]=0;
		}
		for(i=1;i<=n;i++){
			cin>>k;
			if(i&1)a[k][1]=max(a[k][0]+1,a[k][1]);
			else a[k][0]=max(a[k][1]+1,a[k][0]);
		}
		for(i=1;i<=n;i++){
			cout<<max(a[i][0],a[i][1])<<' ';
		}
		cout<<'\n';
	}
}