#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	vector<int>a(n);
	for(int&v:a)cin>>v;
	ll res=0;
	for(int i=0;i+1<n;i+=2){
		if(a[i]<a[i+1]){res+=a[i];continue;}
		ll mn=0,mx=a[i]-a[i+1];
		ll diff=a[i+1];
		for(int j=i+2;mn<=mx&&j+1<n;j+=2){
//			cerr<<i<<" "<<j<<" "<<mn<<" "<<mx<<endl;
			mn+=a[j]-a[j+1],mx+=a[j]-a[j+1];
//			cerr<<mn<<" "<<mx<<endl;
			if(mn<=0){
				diff+=min(0ll,mx)-mn+1;
				mn=0;
			}
		}
//		cerr<<diff<<endl;
		res+=diff;
	}
	cout<<res<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}