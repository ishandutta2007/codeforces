#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,x,y,it,a[200500],b[200500],sum;
set<ll> s;
priority_queue<ll> q;
map<ll,vector<ll>> mp;
ll res;

int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	for(i=1;i<=n;i++){
		mp[a[i]].push_back(b[i]);
		s.insert(a[i]);
	}
	s.insert(114514191919ll);
	auto it=s.upper_bound(0);
	while(*it!=114514191919ll){
		for(auto i:mp[*it]){
			q.push(i);sum+=i;
		}
		sum-=q.top();q.pop();
		res+=sum;
		if(sum){
			s.insert(*it+1);
		}
		it=s.upper_bound(*it);
	}
	printf("%lld",res);
}