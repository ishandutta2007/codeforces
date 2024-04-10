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
#define int long long
using namespace std;
int A[100100],dp[100100][4],X[100100];
string str="hard";
signed main()
{
	int L;
	cin>>L;
	string S;
	cin>>S;
	for(int i=0;i<L;i++)
		cin>>A[i];
	for(int i=0;i<L;i++)
		if(S[i]==str[0])
			dp[i+1][0]=dp[i][0]+A[i];
		else	dp[i+1][0]=dp[i][0];
	for(int i=0;i<L;i++)
		for(int type=1;type<4;type++)
			if(S[i]==str[type])
				dp[i+1][type]=min(dp[i][type-1],dp[i][type]+A[i]);
			else	dp[i+1][type]=dp[i][type];
	cout<<dp[L][3]<<endl;
	return 0;
}