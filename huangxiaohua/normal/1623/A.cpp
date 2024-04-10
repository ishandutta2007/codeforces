#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a,b,c,d,e,f,r1,r2;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>c>>d>>e>>f;
		r1=((c<=e)?e-c:n+n-e-c);
		r2=((d<=f)?f-d:m+m-d-f);
		cout<<min(r1,r2)<<'\n';
	}
}