#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,res,t,a[1005];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		res=0;
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++){
			cin>>k;a[k]++;
		}
		for(i=1;i<=100;i++){
			res+=min(a[i],m);
		}
		cout<<res<<endl;
	}
}