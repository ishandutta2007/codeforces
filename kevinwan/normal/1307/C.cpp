#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
const int inf=0x3f3f3f3f;
int a[mn];
int main(){
	#ifdef LOCAL_PROJECT
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#else
	cin.tie(0);
	cin.sync_with_stdio(0);
	#endif
	ll ans=0;
	string s;
	cin>>s;
	for(char&c:s)c-='a';
	for(int i=0;i<26;i++){
		ll con=0;
		for(char c:s)con+=c==i;
		ans=max(ans,con);
	}
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			ll con=0,num=0;
			for(char c:s){
				if(c==j)con+=num;
				if(c==i)num++;
			}
			ans=max(ans,con);
		}
	}
	printf("%lld",ans);
}