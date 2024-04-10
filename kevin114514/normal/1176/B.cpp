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
int A[110];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>A[i];
		int cnt[3]={};
		for(int i=0;i<N;i++)
			cnt[A[i]%3]++;
		int x=min(cnt[1],cnt[2]);
		cnt[1]-=x;
		cnt[2]-=x;
		cout<<cnt[0]+x+cnt[1]/3+cnt[2]/3<<endl;
	}
	return 0;
}