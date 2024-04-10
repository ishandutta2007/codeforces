#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,res,sb,x,y;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		sb=n;
		res=0;
		for(i=1;i<=n;i++){
			cin>>k;
			while(!(k%2)){
				sb--;k/=2;
			}
		}
		x=262144; y=18;
		while(y){
			if(sb<=0)break;
			for(i=1;(i*x)<=n;i+=2){
				sb-=y;res++;
				if(sb<=0)break;
			}if(sb<=0)break;
			x/=2;y--;if(sb<=0)break;
		}
		if(sb>0){
			cout<<-1<<'\n';
		}
		else cout<<res<<'\n';
	}
}