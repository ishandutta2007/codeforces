#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,t,n,m;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		multiset<ll> s1,s2;
		ll su=0;
		for(i=1;i<=n;i++){
			cin>>k;
			s1.insert(k);
			su+=k;
		}
		s2.insert(su);
		while(!s1.empty()){
			ll x,y;
			x=*--s1.end();
			y=*--s2.end();
			if(y<x){
				cout<<"NO\n";goto aaa;
			}
			if(y==x){
				s1.erase(s1.find(x));
				s2.erase(s2.find(x));
				continue;
			}
			s2.erase(s2.find(y));
			s2.insert(y/2);
			s2.insert(y-y/2);
		}
		cout<<"YES\n";
		aaa:;
	}
}