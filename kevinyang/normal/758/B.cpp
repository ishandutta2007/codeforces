#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#endif

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;cin>>s;
	int n=s.size();
	string id="!!!!";
	for(int i=0;i<4;i++){
		for(int j=i;j<n;j+=4){
			if(s[j]!='!'){
				id[i]=s[j];
				break;
			}
		}
	}
	while(true){
		auto it=id.find('!');
		if(it==string::npos){
			break;
		}
		if(id.find('R')==string::npos){
			id[it]='R';
		}
		else if(id.find('B')==string::npos){
			id[it]='B';
		}
		else if(id.find('Y')==string::npos){
			id[it]='Y';
		}
		else if(id.find('G')==string::npos){
			id[it]='G';
		}
	}
	vector<int> ct(256);
	for(int i=0;i<n;i++){
		if(s[i]=='!'){
			ct[id[i%4]]++;
		}
	}
	cout<<ct['R']<<" "<<ct['B']<<" "<<ct['Y']<<" "<<ct['G']<<"\n";
}