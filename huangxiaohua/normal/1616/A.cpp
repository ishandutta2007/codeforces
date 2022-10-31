#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[666],res;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		res=0;
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++){
			cin>>k;
			a[abs(k)]++;
		}
		for(i=1;i<=100;i++){
			res+=min(a[i],2);
		}
		if(a[0])res++;
		cout<<res<<'\n';
	}
}