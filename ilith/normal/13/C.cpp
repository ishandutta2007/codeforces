#include<bits/stdc++.h>
using namespace std;
long long n,u,ans;
priority_queue<long long>q;
int main(){
	cin>>n;
	while(n--){
		cin>>u;
		q.push(u);
		if(!q.empty()&&u<q.top()){
			ans+=q.top()-u;
			q.pop();
			q.push(u);
		}
	}
	cout<<ans;
	return 0; 
}