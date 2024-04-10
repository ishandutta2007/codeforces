#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

string s;
int len,cnt,k=0;
set <int> v1,v0;
vector <int> vec[maxn];

int main()
{
	cin>>s; len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='0') vec[++cnt].push_back(i+1);
		else
		{
			if(cnt<=0)
			{
				puts("-1");
				return 0;
			}
			vec[cnt--].push_back(i+1);
		}
		k=max(k,cnt);
	}
	if(cnt!=k)
	{
		puts("-1");
		return 0;
	}
	cout<<k<<endl;
	for(int i=1;i<=k;i++)
	{
		cout<<vec[i].size()<<" ";
		for(int j=0;j<vec[i].size();j++) cout<<vec[i][j]<<" "; cout<<endl;
	}
	return 0;
}