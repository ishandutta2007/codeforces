#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it,mx;
pair<int,int> res[305000];
int sb[300500];

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>t;
	deque<int> q;
	for(i=1;i<=n;i++){
		cin>>k;q.push_back(k);
		mx=max(mx,k);
	}
	for(i=1;i<n;i++){
		j=q.front();q.pop_front();
		k=q.front();q.pop_front();
		res[i]={j,k};
		if(j>k){
			q.push_front(j);
			q.push_back(k);
			sb[++it]=k;
		}
		else{
			q.push_front(k);
			q.push_back(j);
			sb[++it]=j;
		}
	}
	while(t--){
		ll t1;
		cin>>t1;
		if(t1<n){
			auto [x,y]=res[t1];
			cout<<x<<' '<<y<<'\n';
		}
		else{
			t1%=(n-1);
			if(!t1)t1=n-1;
			cout<<mx<<' '<<sb[t1]<<'\n';
		}
	}
}