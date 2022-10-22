#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=5e5+9;
int n;
int a[M];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	priority_queue<int>q;
	q.push(-a[n]);
	ll ans=0;
	int l=n;
	n/=2;
	while(q.top()!=1){
		ans+=-q.top();
		q.pop();
		for(int i=l-1;i>=l-n;--i)q.push(-a[i]);
		l-=n;
		n/=2;
	}
	cout<<ans<<endl;
	return 0;
}
/*
1 2 2 4 3 6
*/