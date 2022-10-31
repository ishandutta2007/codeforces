#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>i>>j>>k;
		if((i==j)&&i!=1){
			cout<<"YES\n";continue;
		}
		j=(j+1)/2-(i)/2;
		cout<<((k>=j)?"YES":"NO")<<'\n';
	}
}