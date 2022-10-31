#include<bits/stdc++.h>
using namespace std;

string s;
int i,j,k,t,mx;
queue<pair<string,int> >q;
map<string,int> mp,mp2;
set<string>st;
int main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>s>>k;
    	mp[s]+=k;
    	q.push({s,k});st.insert(s);
	}
	for(auto i:st){
		mx=max(mx,mp[i]);
	}
	while(1){
		auto [u,v]=q.front();q.pop();
		mp2[u]+=v;
		if(mp2[u]>=mx&&mp[u]==mx){cout<<u;return 0;}
	}
}