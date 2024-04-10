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
signed main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<(a+b)/c<<" ";
	int x=(a+b)%c;
	if(!a%c||!b%c)
		cout<<0<<endl;
	else if(a%c+b%c<c)
		cout<<0<<endl;
	else	cout<<(min(c-a%c,c-b%c))<<endl;
	return 0;
}