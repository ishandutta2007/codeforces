#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int i,j,k,n,m,t,n1,n2,ty[200500];
ll a[200050],b[200050],res;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		n1=n2=res=0;
		for(i=1;i<=n;i++){
			cin>>ty[i];
		}
		for(i=1;i<=n;i++){
			cin>>k;
			res+=k;
			if(ty[i]==0){
				a[++n1]=k;
			}
			else{
				b[++n2]=k;
			}
		}
		sort(a+1,a+n1+1);
		sort(b+1,b+n2+1);
		
		if(n1>n2){
			for(i=1;i<=n2;i++){
				res+=b[n2+1-i];
				res+=a[n1+1-i];
			}
		}
		else if(n2>n1){
			for(i=1;i<=n1;i++){
				res+=a[n1+1-i];
				res+=b[n2+1-i];
			}
		}
		else{
			res*=2;
			res-=min(a[1],b[1]);
		}
		cout<<res<<'\n';
	}
}