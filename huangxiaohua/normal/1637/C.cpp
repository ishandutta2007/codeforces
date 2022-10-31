#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,a[105000],x,y;
ll res;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==3){
			if(a[2]&1){
				cout<<"-1\n";
			}
			else{
				cout<<a[2]/2<<'\n';
			}
			continue;
		}
		x=0;y=0;res=0;
		for(i=2;i<n;i++){
			if(a[i]==1){
				x++;
			}
			if(a[i]<=1){
				y++;
			}
		}
		if(x&&(y==n-2)){
			cout<<-1<<'\n';continue;
		}
		for(i=2;i<n;i++){
			res+=(a[i]+1)/2;
		}
		cout<<res<<'\n';
	}
}