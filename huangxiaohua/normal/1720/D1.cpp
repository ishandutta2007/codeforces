#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[300500],res,a[400500];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		res=1;
		for(i=0;i<n;i++){
			f[i]=0;
			cin>>a[i];
			k=max(0,i-555);
			for(j=k;j<i;j++){
				if((a[i]^j)>(a[j]^i)){
					f[i]=max(f[i],f[j]);
				}
			}
			f[i]++;
			res=max(res,f[i]);
		}
		cout<<res<<'\n';
	}
}