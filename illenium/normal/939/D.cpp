#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
using namespace std;

int n,ans,f[26],p1[30],p2[30];
string s1,s2;

int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

inline void merge(int x,int y)
{
	x=find(x); y=find(y);
	if(x!=y) f[x]=y;
}

int main()
{
	scanf("%d",&n);
	cin>>s1>>s2;
	for(int i=0;i<=25;i++) f[i]=i;
	for(int i=0;i<n;i++)
	{
		if(find(s1[i]-'a')==find(s2[i]-'a')) continue;
		else
		{
			p1[ans]=find(s1[i]-'a');
			p2[ans]=find(s2[i]-'a');
			merge(s1[i]-'a',s2[i]-'a'); ans++;
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<ans;i++) cout<<(char)(p1[i]+'a')<<" "<<(char)(p2[i]+'a')<<endl;
	return 0;
}