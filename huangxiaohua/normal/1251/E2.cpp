#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,t,m,a[200500];
vector<int> v[200500];
ll res;
int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;res=0;
		for(i=0;i<=n;i++)a[i]=0,v[i].clear();
		for(i=1;i<=n;i++){
			cin>>j>>k;v[j].push_back(k);
			res+=k;a[j]++;
		}
		for(i=1;i<=n;i++)a[i]+=a[i-1];
		int l,r,md,ans=0;
		l=1;r=n;
		while(l<=r){
			md=(l+r)/2;
			k=0;
			for(j=n-md;j<n;j++){
				k++;
				if(a[j]<k){
					r=md-1;goto aaa;
				}
			}
			l=md+1;ans=max(ans,md);
			aaa:;
		}
		priority_queue<int> q;
		for(j=0;j<n;j++){
			for(auto i:v[j])q.push(i);
			if(j<n-ans)continue;
			if(q.empty())return 1;
			res-=q.top();q.pop();
		}
		cout<<res<<'\n';
	}
}