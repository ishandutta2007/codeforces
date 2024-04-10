#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>/*The header <string> and
<string.h> does not contain the useful
function 'memset' and 'memcpy'.*/
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
vector<int> b,p;
int a;
bool check(int n)
{
	long long cnt=0;
	for(int i=0;i<n;i++)
		cnt+=max(0,p[i]-b[n-1-i]);
	return cnt<=a;
}
int main()
{
	int N,M;
	cin>>N>>M>>a;
	while(N--)
	{
		int x;
		cin>>x;
		b.push_back(x);
	}
	while(M--)
	{
		int x;
		cin>>x;
		p.push_back(x);
	}
	sort(b.rbegin(),b.rend());
	sort(p.begin(),p.end());
	int L=0,H=min(b.size(),p.size());
	for(int i=0;i<1000;i++)
	{
		int mid=(L+H+1)/2;
		if(check(mid))
			L=mid;
		else	H=mid-1;
	}
	cout<<L<<" ";
	int cnt=0;
	for(int i=0;i<L;i++)
		cnt+=p[i];
	cout<<max(0,cnt-a)<<endl;
	return 0;
}