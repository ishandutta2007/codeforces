#include<bits/stdc++.h>
using namespace std;
int T,n,i,a[1005],b[1005],fl; 
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i)cin>>b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		fl=1;
//		for(i=1;i<=n;++i)if(a[i]>b[i])fl=1;
		for(i=1;i<=n;++i){
			if(a[i]==b[i]||a[i]==b[i]-1)fl=1;
			else{fl=0;break;}
		}
		if(fl)cout<<"YES\n";
		else cout<<"NO\n";
	}
}