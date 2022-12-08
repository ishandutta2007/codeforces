#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 312345;
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define MOD 1000000007


int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int tam=2*abs(b-a);
		if(a>tam||b>tam||c>tam)cout<<-1<<"\n";
		else{
			c=(c+tam/2)%tam;
			if(c==0)c=tam;
			cout<<c<<"\n";
		}
	}
	
}