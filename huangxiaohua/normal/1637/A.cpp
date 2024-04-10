#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,a[100500],b[100500];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];b[i]=a[i];
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
			if(a[i]!=b[i]){
				cout<<"Yes\n";goto aaa;
			}
		}
		cout<<"No\n";
		aaa:;
	}
}