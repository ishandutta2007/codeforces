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
int main()
{
	int Q;
	cin>>Q;
	while(Q--)
	{
		long long X;
		cin>>X;
		long long ans=0;
		while(X%2==0)
		{
			X/=2;
			ans++;
		}
		while(X%3==0)
		{
			X/=3;
			ans+=2;
		}
		while(X%5==0)
		{
			X/=5;
			ans+=3;
		}
		if(X>1)
			cout<<-1<<endl;
		else	cout<<ans<<endl;
	}
	return 0;
}