#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005000],x,y;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>k;a[k]++;
	}
	for(i=1;i<=500000;i++){
		a[i+1]+=a[i]/(i+1);
		a[i]%=(i+1);
	}
	for(i=1;i<m;i++){
		if(a[i]){
			cout<<"No";return 0;
		}
	}
	cout<<"Yes";
}