#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[66666];


int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=2){
			cout<<0<<'\n';
			continue;
		}
		int res=114514;
		int tmp=0;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				tmp=0;
				for(k=1;k<=n;k++){
					if(k==i||k==j)continue;
					if( ((j-i)*(a[k]-a[i])) != ((a[j]-a[i])*(k-i)) )tmp++;
				}
				res=min(res,tmp);
			}
		}
		cout<<res<<'\n';
	}
}