#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<utility>
#include<algorithm>
#include<functional>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
vector<int> A,B;
int an,bn,at,bt,K;
int main()
{
	cin>>an>>bn>>at>>bt>>K;
	while(an--)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	while(bn--)
	{
		int x;
		cin>>x;
		B.push_back(x);
	}
	an=A.size();
	bn=B.size();
	if(K>=min(an,bn))
	{
		cout<<-1<<endl;
		return 0;
	}
	int mx=0;
	for(int i=0;i<=K;i++)
	{
		int aa=A[i],x=B.end()-lower_bound(B.begin(),B.end(),aa+at);
		if(x<=(K-i))
		{
			cout<<-1<<endl;
			return 0;
		}
		int num=*(lower_bound(B.begin(),B.end(),aa+at)+(K-i));
		mx=max(num,mx);
	}
	cout<<mx+bt<<endl;
	return 0;
}