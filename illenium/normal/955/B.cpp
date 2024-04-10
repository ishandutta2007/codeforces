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

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

map <char,int> mp;
map <char,int> p;
vector <char> vec;
string s;
int cnt=0;

int main()
{
	cin>>s;
	int len=s.length();
	if(s.length()<4)
	{
		puts("No");
		return 0;
	}
	for(int i=0;i<len;i++)
	{
		if(mp[s[i]]==0)
		{
			cnt++;
			mp[s[i]]=1;
			vec.push_back(s[i]);
		}
		else
		{
			mp[s[i]]++;
		}
	}
	if(cnt>4||cnt==1)
	{
		puts("No");
		return 0;
	}
	if(cnt==2)
	{
		if(mp[vec[0]]>=2&&mp[vec[1]]>=2)
		{
			puts("Yes");
			return 0;
		}
		else
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}