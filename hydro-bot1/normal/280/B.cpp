// Hydro submission #63568ae9da5766df5a56d38b@1666616041984
#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
stack<int>s;
int ans=-1e9;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int i=1;i<=n;i++){
		while(!s.empty()&&s.top()<a[i])s.pop();//a[i]a[i]
		if(!s.empty())ans=max(ans,s.top()^a[i]);//
		s.push(a[i]);
	}
	while(!s.empty())s.pop();
	for(int i=n;i>=1;i--){//
		while(!s.empty()&&s.top()<a[i])s.pop();
		if(!s.empty())ans=max(ans,s.top()^a[i]);
		s.push(a[i]);
	}
	cout<<ans<<endl;
	return 0;
}