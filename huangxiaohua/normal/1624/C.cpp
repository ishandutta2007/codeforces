#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,a[66];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++){
			cin>>k;
			while(k>n){
				k/=2;
			}
			a[k]++;
		}
		for(i=n;i>=1;i--){
			//printf("NMSL;%d %d\n",i,a[i]);
			if(!a[i]){
				cout<<"NO\n";
				goto aaa;
			}
			a[i/2]+=(a[i]-1);
		}
		cout<<"YES\n";
		aaa:;
	}
}