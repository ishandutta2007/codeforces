#include<bits/stdc++.h>
using namespace std;
vector<int> A;
int main()
{
	int N,M;
	cin>>N>>M;
	while(N--)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	sort(A.begin(),A.end());
	while(M--)
	{
		int x;
		cin>>x;
		cout<<lower_bound(A.begin(),A.end(),x+1)-A.begin()<<" ";
	}
	return 0;
}