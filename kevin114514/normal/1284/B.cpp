#include<bits/stdc++.h>
using namespace std;
vector<int> L;
vector<int> R;
long long ans;
int main()
{
	int N;
	cin>>N;
	ans=1ll*N*N;
	for(int i=0;i<N;i++)
	{
		int l;
		cin>>l;
		vector<int> X;
		for(int i=0;i<l;i++)
		{
			int Y;
			cin>>Y;
			X.push_back(Y);
		}
		vector<int> Tmp=X;
		sort(Tmp.rbegin(),Tmp.rend());
		if(Tmp==X)
			L.push_back(X[0]),
			R.push_back(X.back());
	}
	sort(L.begin(),L.end());
	for(int i=0;i<R.size();i++)
		ans-=(lower_bound(L.begin(),L.end(),R[i]+1)-L.begin());
	cout<<ans<<endl;
	return 0;
}