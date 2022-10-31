#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005000];
ll res;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		res=0;
		j=1;
		for(i=1;i<n;i++){
			j=max(j,i+1);
			if(j==n){
				res+=a[i];continue;
			}
			while(a[i]&&j!=n){
				while(j<n&&a[j]){
					j++;
				}
				res++;a[i]--;
				a[j]++;
			}
			res+=a[i];
		}
		cout<<res<<'\n';
	}
}