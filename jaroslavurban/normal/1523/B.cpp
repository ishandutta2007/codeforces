#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	cout<<3*n<<"\n";
	for(int i=0;i<n;i+=2){
		cout<<"2 "<<i+1<<" "<<i+2<<"\n";
		cout<<"2 "<<i+1<<" "<<i+2<<"\n";
		cout<<"1 "<<i+1<<" "<<i+2<<"\n";
		cout<<"2 "<<i+1<<" "<<i+2<<"\n";
		cout<<"2 "<<i+1<<" "<<i+2<<"\n";
		cout<<"1 "<<i+1<<" "<<i+2<<"\n";
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}