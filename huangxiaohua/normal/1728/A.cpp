#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a,b;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		a=b=0;
		for(i=1;i<=n;i++){
			cin>>j;
			if(j>b){
				b=j;a=i;
			}
		}
		cout<<a<<'\n';
	}
}