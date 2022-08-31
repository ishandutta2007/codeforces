//Time Complexity : O(N*log(N))
//Space Complexity : O(N)
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e4;
priority_queue<pair<int,int> >h;
int main(){
	string s;
	cin>>s;
	int n=s.length(),cnt=0;
	ll ans=0;
	for(int i=0;i<n;++i){
		int a,b;
		switch(s[i]){
			case '(':
				++cnt;
				break;
			case ')':
				--cnt;
				break;
			case '?':
				s[i]=')';
				--cnt;
				scanf("%d%d",&a,&b);
				h.push({b-a,i});
				ans=ans+b;
				break;
		}
		if(cnt<0){
			if(h.empty()){
				printf("-1");
				return 0;
			}
			auto p=h.top();
			h.pop();
			ans=ans-p.first;
			s[p.second]='(';
			cnt=cnt+2;
		}
	}
	if(cnt!=0){
		printf("-1");
		return 0;
	}
	printf("%I64d\n",ans);
	cout<<s;
	return 0;
}