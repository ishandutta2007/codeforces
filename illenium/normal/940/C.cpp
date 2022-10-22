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
bool f[26];
int n,t,maxn,minn,last,next[26],flag;
stack <char> st;

int main()
{
	//freopen("CF940C.in","r",stdin);
	n=read(); t=read();
	cin>>s;
	for(int i=0;i<n;i++) f[s[i]-'a']=true;
	for(int i=0;i<26;i++) if(f[i])
	{
		next[last]=i;
		last=i; 
	}
	for(int i=0;i<26;i++) if(f[i]) {minn=i; break;}
	if(n==t)
	{
		for(int i=n-1;i>=0;i--)
		{
			if(!next[s[i]-'a']) st.push(char(minn+'a'));
			else
			{
				st.push(char(next[s[i]-'a']+'a'));
				flag=i;
				break;
			}
		}
		for(int i=0;i<flag;i++) cout<<s[i];
		while(!st.empty())
		{
			char c=st.top(); st.pop();
			cout<<c;
		}
	}
	else if(t>n)
	{
		cout<<s;
		for(int i=1;i<=t-n;i++) cout<<(char)(minn+'a');
	}
	else if(t<n)
	{
		n=t;
		for(int i=n-1;i>=0;i--)
		{
			if(!next[s[i]-'a']) st.push(char(minn+'a'));
			else
			{
				st.push(char(next[s[i]-'a']+'a'));
				flag=i;
				break;
			}
		}
		for(int i=0;i<flag;i++) cout<<s[i];
		while(!st.empty())
		{
			char c=st.top(); st.pop();
			cout<<c;
		}
	} 
	return 0;
}