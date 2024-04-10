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

int cnt,k,i=18;

inline bool jud(int x)
{
	int tmp=0;
	while(x)
	{
		tmp+=(x%10);
		x/=10;
	}
	return tmp==10?1:0;
}

int main()
{
	cin>>k;
	while(1)
	{
		i++;
		if(jud(i)) cnt++;
		if(cnt==k) {cout<<i; return 0;}
	}
	return 0;
}