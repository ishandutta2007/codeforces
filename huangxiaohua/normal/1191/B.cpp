#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m;
map<int,map<int,int> > mp;
string s,sb="spm";

int main() {
	ios::sync_with_stdio(0);
	for(t=1;t<=3;t++){cin>>s;mp[s[1]][s[0]]++;}
	for(i='1';i<='9';i++)for(auto j:sb){
		if((mp[j][i]&&mp[j][i+1]&&mp[j][i+2])||mp[j][i]>2){cout<<0;return 0;}
	}
	for(i='1';i<='9';i++)for(auto j:sb){
		if(mp[j][i]+mp[j][i+1]+mp[j][i+2]>=2){cout<<1;return 0;}
	}
	cout<<2;
}