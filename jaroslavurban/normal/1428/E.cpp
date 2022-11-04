#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
ll a[N],cuts[N];
int n,k;

ll pr(int i,int cut){
	ll sz=a[i]/(cut+1),bg=a[i]%(cut+1);
	return (cut+1-bg)*sz*sz+bg*(sz+1)*(sz+1);
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0;i<n;++i)cin>>a[i];
	priority_queue<pair<ll,int>>q;
	for(int i=0;i<n;++i)q.push({pr(i,0)-pr(i,1),i});
	ll res=0;
	for(int i=0;i<n;++i)res+=a[i]*a[i];
	for(int i=n;i<k;++i){
		auto p=q.top();q.pop();
		res-=p.first;++cuts[p.second];
		q.push({pr(p.second,cuts[p.second])-pr(p.second,cuts[p.second]+1),p.second});
	}
	cout<<res<<endl;
}