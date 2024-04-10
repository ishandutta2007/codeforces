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
#define maxn 1000005
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

int len[maxn],f[maxn];
string s[maxn];
vector <int> vec;

inline int getf(int x)
{
	if(f[x]==x) return x;
	return f[x]=getf(f[x]);
}

inline void mer(int u,int v)
{
	int fu=getf(u),fv=getf(v);
	if(fu==fv) return; f[fu]=fv;
}

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) len[i]=s[i].length();
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=0;i<26;i++)
	{
		char tmp='a'+i;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<len[j];k++)
				if(s[j][k]==tmp)
				{
					vec.push_back(j);
					break;
				}
		}
		for(int i=1;i<vec.size();i++) mer(vec[i],vec[0]);
		vec.clear();
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(f[i]==i) ans++;
	cout<<ans<<endl;
	return 0;
}