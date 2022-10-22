#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e6;
int t[N+10];
int cnt[N+10];
priority_queue<int> l;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>t[i];
		cnt[t[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==0)
			l.push(-i);
	}
	cout<<t[1]<<"\n";
	for(int i=n-1;i>=1;i--)
	{
		int x=-l.top();
		l.pop();
		cout<<x<<" "<<t[i]<<"\n";
		cnt[t[i]]--;
		if(cnt[t[i]]==0)
			l.push(-t[i]);
	}
	return 0;
}