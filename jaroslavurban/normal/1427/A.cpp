#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=55;
int a[N];
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int less=0,more=0;
		int n;cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<n;++i)if(a[i]>=0)more+=a[i];
		else less+=-a[i];
		if(more==less){cout<<"NO\n";continue;}
		cout<<"YES\n";
		if(more>less){
			for(int i=0;i<n;++i)if(a[i]>0)cout<<a[i]<<" ";
			for(int i=0;i<n;++i)if(a[i]<0)cout<<a[i]<<" ";
			for(int i=0;i<n;++i)if(a[i]==0)cout<<a[i]<<" ";
			cout<<endl;
		}
		if(more<=less){
			for(int i=0;i<n;++i)if(a[i]<0)cout<<a[i]<<" ";
			for(int i=0;i<n;++i)if(a[i]>0)cout<<a[i]<<" ";
			for(int i=0;i<n;++i)if(a[i]==0)cout<<a[i]<<" ";
			cout<<endl;
		}
	}
}