#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int N=200100;
int n;
string s;
bool done[N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n>>s;
		for(int i=0;i<n;++i)done[i]=false;
		int idx=0;
		int pref=0;
		int spojs=true;
		int res=0;
		while(pref<n){
			idx=max(idx,pref);
			if(spojs){
				while(idx+1<n&&(done[idx]||done[idx+1]||s[idx]!=s[idx+1]))++idx;
				if(idx+1<n)done[idx]=true;
				else spojs=false;
			}
			if(!spojs){
				int left=0;
				for(int i=pref;i<n;++i)if(!done[i])++left;
				res+=(left+1)/2;
				break;
			}
			while(pref<n&&done[pref])++pref;
			if(pref==n)break;
			int col=s[pref];
			while(pref<n&&(done[pref]||s[pref]==col))++pref;
			++res;
		}
		cout<<res<<endl;
	}
}