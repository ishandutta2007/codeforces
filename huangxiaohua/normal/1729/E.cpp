#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,r1,r2;

int main() {
	ios::sync_with_stdio(0);
	for(i=2;;i++){
		cout<<"? "<<1<<' '<<i<<endl; cin>>r1;
		cout<<"? "<<i<<' '<<1<<endl; cin>>r2;
		if(r1==-1){cout<<"! "<<i-1;return 0;}
		if(r1!=r2){cout<<"! "<<r1+r2;return 0;}
	}
}