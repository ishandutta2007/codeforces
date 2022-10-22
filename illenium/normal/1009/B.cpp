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
int cnt,cnt2;

int main()
{
	cin>>s;
	for(int i=0;i<s.length();i++) if(s[i]=='1') cnt++;
	int cnt3=0,flag2=inf;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0') cnt3++;
		if(s[i]=='2') {flag2=i; break;}
	}
	for(int i=1;i<=cnt3;i++) putchar('0');
	for(int i=1;i<=cnt;i++) putchar('1');
	for(int i=flag2;i<s.length();i++)
	{
		if(s[i]=='1') continue;
		cout<<s[i];
	}
	return 0;
}