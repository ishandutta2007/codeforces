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

string s,q;
map <string,int> mp;
int ans,n;

int main()
{
	cin>>n; cin>>s;
	for(int i=0;i<s.length()-1;i++)
	{
		string p; p.clear();
		p.push_back(s[i]); p.push_back(s[i+1]); mp[p]++;
		if(ans<mp[p]) ans=mp[p],q=p;
	}
	cout<<q<<endl;
	return 0;
}