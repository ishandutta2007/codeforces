#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N=10100;
int a[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		ll sm=0;
		bool pos=true;
		for(int i=0;i<n;++i)sm+=a[i];
		if(sm%n){
			cout<<-1<<endl;continue;
		}
		cout<<3*(n-1)<<endl;
		for(int i=1;i<n;++i){
			cout<<"1 "<<i+1<<" "<<(i+1)*(a[i]/(i+1)+!!(a[i]%(i+1)))-a[i]<<endl;
			cout<<i+1<<" 1 "<<a[i]/(i+1)+!!(a[i]%(i+1))<<endl;
		}
		for(int i=1;i<n;++i)cout<<"1 "<<i+1<<" "<<sm/n<<endl;
	}	
}