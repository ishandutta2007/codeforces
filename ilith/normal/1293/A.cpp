#include<bits/stdc++.h>
using namespace std;
int t;
int n,s,k;
int a[1010];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>s>>k;
		a[0]=a[k+1]=0;
		for(int i=1;i<=k;i++){
			cin>>a[i];
		}
		sort(a+1,a+k+1);
		int pla;
		for(int i=1;i<=k;i++){
			if(a[i]==s){
				pla=i;
				goto tag;
			}
		}
		cout<<0<<'\n';
		continue;
		tag:
			int mi=1e9;
			for(int i=pla+1;i<=k+1;i++){
				if(a[i]!=a[i-1]+1&&a[i-1]!=n){
					mi=min(mi,a[i-1]+1-s);
				}
			}
			for(int i=pla-1;i>=0;i--){
				if(a[i]!=a[i+1]-1&&a[i+1]!=1){
					mi=min(mi,s-a[i+1]+1);
				}
			}
			cout<<mi<<'\n';
	}
	return 0;
}