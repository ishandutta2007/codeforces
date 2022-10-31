#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005000];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		a*=d;b*=c;
		if(a==b){
			cout<<"0\n";continue;
		}
		if(!a||!b||!(a%b)||!(b%a)){
			cout<<"1\n";continue;
		}
		cout<<"2\n";continue;
	}
}