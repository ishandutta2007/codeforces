#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,tot,NMSL;
int res,tmp,ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		NMSL=m;
		map<int,int> mp;
		priority_queue<int> q1,q2;
		ans=0;tot=0;sb=0;
		for(i=1;i<=n;i++){
			cin>>k;mp[k]++;
		}
		res=mp.size();
		for(i=0;i<n;i++){
			if(!mp.count(i))sb++;
		}
		for(auto [x,y]:mp){
			if(x>=n){
				tot+=y;
				q1.push(-y);
				ans++;
			}
		}
		while(!q1.empty()&&m+q1.top()>=0){
			q2.push(-q1.top());
			m+=q1.top();
			q1.pop();
			ans--;
		}
		//printf("nmsl%d %d %d\n",sb,tot,m);
		for(i=n;i>=0;i--){
			if(NMSL>=sb){
				while(!q2.empty()&&!q1.empty()&&q2.top()+q1.top()>0){
					int x=q2.top(),y=q1.top();
					q2.pop();q1.pop();
					m+=x+y;
					q1.push(-x);q2.push(-y);
				}
				while(!q1.empty()&&m+q1.top()>=0){
					q2.push(-q1.top());
					m+=q1.top();
					q1.pop();
					ans--;
				}
				if(i)res=min(res,ans);
				else res=min(res,ans);
				//printf("NMSL%d %d %d\n",i,ans,res);
			}
			
			if(!i)break;
			if(!mp.count(i-1))sb--;
			else{
				tot+=mp[i-1];
				q1.push(-mp[i-1]);
				ans++;
			}
		}
		cout<<res<<'\n';
	}
}