#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn=500005;
const int inf=1e9;

int nm[maxn][3];
string name[maxn];
int ans[maxn];
int n;

int main()
{
	cin >> n;
	for (int i=0;i<n;i++) cin >> name[i];
	for (int i=0;i<n;i++) nm[i][0]=(char)name[i][0],nm[i][1]=(char)name[i][name[i].length()-1],nm[i][2]=name[i].length();
	int answer=0;
	for (int c='a';c<='z';c++)
	{
		for (int i='a';i<='z';i++) ans[i]=-inf;
		ans[c]=0;
		for (int i=0;i<n;i++)
		{
			ans[nm[i][1]]=max(ans[nm[i][1]],ans[nm[i][0]]+nm[i][2]);
		}
		answer=max(answer,ans[c]);
	}
	cout << answer << endl;
	return 0;
}