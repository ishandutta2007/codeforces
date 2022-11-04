#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=30100;
int a[N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		for(int i=0;i<n;++i)cin>>a[i];
		int mx=1e9,mn=0,pos=1;
		for(int i=0;i<n;++i){
			mx=max(0,min(a[i]-mn,mx));
			a[i]-=mx;
			if(a[i]<mn){pos=0;break;}
			mn=a[i];
		}
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";
	}
}