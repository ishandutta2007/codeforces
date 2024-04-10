#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1000005];
ll res;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		res=0;
		j=0;
		for(i=1;i<=n;i++){
			while(j<n&&a[j+1]+i-1>=j+1)j++;
			res+=j-i+1;
		}
		cout<<res<<'\n';
	}
}