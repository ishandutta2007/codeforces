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

string s;
map <char,int> mp;

int main()
{
	cin>>s; s=s+'b';
	mp['a']=1; mp['e']=1; mp['i']=1; mp['o']=1; mp['u']=1;
	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i]=='n'||mp[s[i]]) continue;
		else if(mp[s[i]]==0&&mp[s[i+1]]==0)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}