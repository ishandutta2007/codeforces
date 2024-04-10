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
int n;

int main()
{
	cin>>n; cin>>s; s.push_back('0'); s='0'+s;
	for(int i=1;i<s.length();i++) if(s[i]=='1'&&s[i-1]=='1')
	{
		puts("No");
		return 0;
	}
	if(s.length()<=2)
	{
		if(s[0]=='0'&&s.length()==1) {puts("Yes"); return 0;}
		else if(s[0]=='0'&&s[1]=='0') {puts("Yes"); return 0;}
	}
	for(int i=1;i<s.length()-1;i++)
	{
		if(s[i]=='0'&&s[i-1]=='0'&&s[i+1]=='0')
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}