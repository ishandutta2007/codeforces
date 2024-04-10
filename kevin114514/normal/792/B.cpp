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
vector<int> v;
int main()
{
	int N,K;
	cin>>N>>K;
	for(int i=1;i<=N;i++)
		v.push_back(i);
	while(K--)
	{
		int x;
		cin>>x;
		x%=v.size();
		rotate(v.begin(),v.begin()+x,v.end());
		cout<<v[0]<<" ";
		v.erase(v.begin());
	}
	return 0;
}