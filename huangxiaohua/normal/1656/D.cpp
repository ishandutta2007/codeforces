#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		m=n;
		while(m){
			if(!(m%2))m/=2;
			else break;
		}
		if(m==1){
			cout<<"-1\n";continue;
		}
		for(i=2;;i*=2){
			k=(i+1)*i/2;
			k=n-k;
			if(k<0)break;
			if(!(k%i)){
				cout<<i<<'\n';goto aaa;
			}
		}
		for(i=2;;i*=2){
			if(n%i)break;
			j=n/i;
			if(j>1e9)continue;
			
			k=(j+1)*j/2;
			k=n-k;
			if(k<0)continue;;
			if(!(k%j)){
				cout<<j<<'\n';goto aaa;
			}
		}
		for(i=2;;i++){
			k=(i+1)*i/2;
			k=n-k;
			if(k<0)break;
			if(!(k%i)){
				cout<<i<<'\n';goto aaa;
			}
		}
		cout<<"-1\n";
		aaa:;
	}
}