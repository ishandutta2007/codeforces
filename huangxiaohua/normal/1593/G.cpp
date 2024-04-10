#include <bits/stdc++.h>
using namespace std;
#define N 1000500
int i,j,k,n,m,t,res,a[N],it,l,r,st[N];
char s[N];
main(){
	cin.tie(0);cin>>t;
	while(t--){
		cin>>s+1>>m;
		n=strlen(s+1);it=0;
		for(i=1;i<=n;i++){
			s[i]=(s[i]=='('||s[i]==')');
			if(it&&s[i]==st[it])it--;
			else st[++it]=s[i];
			a[i]=it*(st[1]?1:-1);
		}
		while(m--){
			cin>>l>>r;cout<<abs(a[r]-a[l-1])/2<<'\n';
		}
	}
}