//Time Complexity : O(N)
//Space Complexity : O(N)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6,inf=1e9;
int main(){
	int n;
	scanf("%d",&n);
	vector<int>h(n*2-1);
	pair<int,int>Max[2];
	for(int i=0;i<=n-1;++i){
		scanf("%d",&h[i]);
		if(h[i]>Max[0].first){
			Max[1]=Max[0];
			Max[0]={h[i],1};
		}else if(h[i]==Max[0].first){
			++Max[0].second;
		}else if(h[i]>Max[1].first){
			Max[1]={h[i],1};
		}else if(h[i]==Max[1].first){
			++Max[1].second;
		}
	}
	for(int i=0;i<=n-2;++i){
		h[n+i]=h[i];
	}
	deque<pair<int,int>>q;
	ll ans=0;
	for(int i=0;i<=n*2-2;++i){
		if(!q.empty()&&q.back().second<=i-n){
			q.pop_back();
		}
		if(i>=n-1){
			auto p=upper_bound(q.begin(),q.end(),make_pair(h[i],inf));
			ans=ans+(p-q.begin())+(p!=q.end());
		}
		while(!q.empty()&&h[i]>q.front().first){
			q.pop_front();
		}
		q.push_front({h[i],i});
	}
	if(Max[0].second==1){
		ans=ans-Max[1].second;
	}else{
		ans=ans-1ll*Max[0].second*(Max[0].second-1)/2;
	}
	printf("%lld",ans);
	return 0;
}