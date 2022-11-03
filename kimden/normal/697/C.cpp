#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

string toStr(ll x){
	string s="";
	if(x==0)
		return "0";
	ll y = x;
	while(y>0){
		if(y%2==1){
			s = '1'+s;
		}else{
			s = '0'+s;
		}
		y >>= 1;
	}
	return s;
}

int main()
{
	map<string,ll> mp;
	int q;
	cin >> q;
	ll t,v,u,w;
	ll ans;
	string s1,s2;
	int j;
	for(int i=0;i<q;i++){
		cin >> t;
		if(t==1){
			cin >> v >> u >> w;
			s1 = toStr(v);
			s2 = toStr(u);
			j = 0;
			while(j<s1.length() && j<s2.length() && s1[j]==s2[j]){
				j++;
			}
			while(s1.length()>j){
				mp[s1] += w;
				s1.erase(s1.end()-1);
			}
			while(s2.length()>j){
				mp[s2] += w;
				s2.erase(s2.end()-1);
			}
		}else{
			cin >> v >> u;
			ans = 0;
			s1 = toStr(v);
			s2 = toStr(u);
			j = 0;
			while(j<s1.length() && j<s2.length() && s1[j]==s2[j]){
				j++;
			}
			while(s1.length()>j){
				ans += mp[s1];
				s1.erase(s1.end()-1);
			}
			while(s2.length()>j){
				ans += mp[s2];
				s2.erase(s2.end()-1);
			}
			cout << ans << "\n";
		}
	}
}