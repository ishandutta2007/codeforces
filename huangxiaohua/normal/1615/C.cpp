#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a1,a0,b1,b0,z,res;
char s2[200500],s1[200500];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s1+1>>s2+1;
		
		z=0;
		a1=a0=b1=b0=0;
		for(i=1;i<=n;i++){
			a0+=(s1[i]=='0');a1+=(s1[i]=='1');
			b0+=(s2[i]=='0');b1+=(s2[i]=='1');
			z+=(s1[i]!=s2[i]);
		}
		if(!z){
			cout<<0<<'\n';continue;
		}
		res=1145141919;
		if(a0==b0&&a1==b1){
			res=z;
		}
		
		z=0;
		a1=a0=b1=b0=0;
		for(i=1;i<=n;i++){
			a0+=(s1[i]=='0');a1+=(s1[i]=='1');
			b0+=(s2[i]=='0');b1+=(s2[i]=='1');
		}
		if(a1){
			swap(a1,a0);
			a1++;a0--;
		}
		else goto aaa;
		
		if(a0==b0&&a1==b1){
			for(i=1;i<=n;i++){
				if(s1[i]=='1'&&s2[i]=='1'){
					z--;break;
				}
			}
			for(i=1;i<=n;i++){
				z+=(s1[i]==s2[i]);
			}
			z++;
			res=min(res,z);
		}
		
		aaa:;
		cout<<((res>n+n)?-1:res)<<'\n';
	}
}