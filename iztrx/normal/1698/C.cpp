#include<bits/stdc++.h>
using namespace std;
int T,n,k,tot,fl,j,l,i,a[1000005];
int main(){
	cin>>T;
	while(T--){
		cin>>n;tot=0;
		for(i=1;i<=n;++i){
			cin>>a[i];
			if(a[i]==0){
				++tot;
				if(tot>1){
					--i;--n;
				}
			}
		}
		if(n>10){
			cout<<"NO\n";
			continue;
		}
		else{
			fl=0;tot=0;
			for(i=1;i<=n;++i){
				for(j=i+1;j<=n;++j){
					for(k=j+1;k<=n;++k){
						fl=0;
						for(l=1;l<=n;++l){
							if(a[l]==a[i]+a[j]+a[k]){
								fl=1;
							}
						}
						if(fl==0)++tot;
					}
				}
			}
			if(tot)cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
}