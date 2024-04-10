#include<bits/stdc++.h>
using namespace std;
long long ans;
vector<int> v;
int main()
{
	int N,M,K;
	cin>>N>>M>>K;
	while(K--)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	N*=M;
	while(N--)
	{
		int x;
		cin>>x;
		int pos=find(v.begin(),v.end(),x)-v.begin();
		ans+=pos+1;
		rotate(v.begin(),v.begin()+pos,v.begin()+pos+1);
	}
	cout<<ans<<endl;
	return 0;
}