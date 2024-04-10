#include<bits/stdc++.h>
#define eb emplace_back
#define ll long long
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int n;
int s[M];
vector<int>p[M];
void work(){
	cin>>n;
	for(int i=0;i<=n;++i)p[i].clear();
	for(int i=1;i<=n;++i){
		int x,y;
		cin>>x>>y;
		p[x].eb(y);
	}
	for(int i=0;i<n;++i){
		s[i]=p[i].size();
		if(i)s[i]+=s[i-1];
	}
	ll ans=0;
	priority_queue<int>q;
	for(int i=n-1,j=0;i>=0;--i){
		while(s[i]+j<i+1){
			ans+=-q.top();
			q.pop();
			j++;
		}
		for(auto o:p[i]){
			q.push(-o);
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}