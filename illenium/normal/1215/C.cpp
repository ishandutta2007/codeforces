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

vector <int> v1,v2;
char s1[maxn],s2[maxn];

int main()
{
	int n=read();
	scanf("%s",s1+1); scanf("%s",s2+1);
	for(int i=1;i<=n;i++)
	{
		if(s1[i]!=s2[i]&&s1[i]=='a') v1.push_back(i);
		else if(s1[i]!=s2[i]&&s1[i]=='b') v2.push_back(i);
	}
	if((v1.size()+v2.size())%2==1)
	{
		puts("-1");
		return 0;
	}
	if(v1.size()%2==0)
	{
		cout<<(v1.size()+v2.size())/2<<endl;
		for(int i=0;i<v1.size()/2;i++) cout<<v1[2*i]<<" "<<v1[2*i+1]<<endl;
		for(int i=0;i<v2.size()/2;i++) cout<<v2[2*i]<<" "<<v2[2*i+1]<<endl;
		return 0;
	}
	else
	{
		cout<<(v1.size()+v2.size())/2+1<<endl;
		for(int i=0;i<v1.size()/2;i++) cout<<v1[2*i]<<" "<<v1[2*i+1]<<endl;
		for(int i=0;i<v2.size()/2;i++) cout<<v2[2*i]<<" "<<v2[2*i+1]<<endl;
		cout<<v1[v1.size()-1]<<" "<<v1[v1.size()-1]<<endl;
		cout<<v2[v2.size()-1]<<" "<<v1[v1.size()-1]<<endl;
	}
	return 0;
}