#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;;
string s;
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		ll n,k;cin>>n>>k;
		ll klft=k;
		cin>>s;
		ll st=-1,en=-1;
		for(int i=0;i<n;++i){
			if(s[i]=='W'&&st==-1)st=i;
			if(s[i]=='W')en=i;
		}
		if(st==-1){
			cout<<min(2ll*n-1,max(0ll,2ll*k-1))<<endl;
			continue;
		}
		vector<int>gaps;
		int cur=0;
		for(int i=st;i<=en;++i){
			if(s[i]=='W'&&cur){
				gaps.push_back(cur);cur=0;
			}
			if(s[i]=='L')++cur;
		}
		sort(gaps.begin(),gaps.end());
		ll res=0,idx=0;
		for(int i=0;i<n;++i){
			if(i&&s[i-1]=='W'&&s[i]=='W')++res;
			if(s[i]=='W')++res;
		}
//		cerr<<res<<endl;
		while(klft>0&&idx<gaps.size()){
			if(klft>=gaps[idx]){
				res+=2*gaps[idx]+1;
				klft-=gaps[idx];
			}else{
				res+=2*klft;
				klft-=klft;
			}
			++idx;
		}
		if(klft){
			ll add=min(klft,st);
			res+=2*add;
			klft-=add;
		}
		if(klft){
			ll add=min(klft,n-en-1);
			res+=2*add;
			klft-=add;
		}
		cout<<res<<endl;
	}
}