#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// bool xd=any_of(a.begin(),a.end(),[&](int x){return x==9;});
// all_of, none_of
// int cnt=count(a.begin(),a.end(),x);
// bool found=binary_search(a.begin(),a.end(),x); true if x in sorted array
// int xd=*max_element(a.begin(),a.end());
// min_element

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int x,y;cin>>x>>y;
		string s;cin>>s;
		int n=s.size();
		int L=0,R=0,U=0,D=0;
		for(int i=0;i<n;++i){
			if(s[i]=='R')++R;
			if(s[i]=='L')++L;
			if(s[i]=='U')++U;
			if(s[i]=='D')++D;
		}
		if(x>=0&&y>=0){
			x=abs(x);y=abs(y);
			if(R>=x&&U>=y)cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		if(x<=0&&y<=0){
			x=abs(x);y=abs(y);
			if(L>=x&&D>=y)cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		if(x<=0&&y>=0){
			x=abs(x);y=abs(y);
			if(L>=x&&U>=y)cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		if(x>=0&&y<=0){
			x=abs(x);y=abs(y);
			if(R>=x&&D>=y)cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
	}
}