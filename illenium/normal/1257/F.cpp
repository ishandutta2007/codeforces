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

int a[maxn],b[maxn],c[maxn];
vector <int> vec;
map <vector <int>,int> mp;

inline int getnum(int x)
{
	int ans=0;
	while(x)
	{
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int tmp1=(1<<15)-1,tmp2=(tmp1<<15);
	for(int i=1;i<=n;i++) b[i]=a[i]&tmp1,c[i]=a[i]&tmp2,c[i]>>=15;
	for(int i=0;i<=tmp1;i++)
	{
		vec.clear();
		for(int j=1;j<=n;j++)
		{
			int tmp=getnum(b[j]^i);
			vec.push_back(tmp);
		}
		for(int j=1;j<vec.size();j++) vec[j]-=vec[0]; vec[0]=0;
		mp[vec]=i;
	}
	for(int i=0;i<=tmp1;i++)
	{
		vec.clear();
		for(int j=1;j<=n;j++)
		{
			int tmp=getnum(c[j]^i);
			vec.push_back(tmp);
		}
		for(int j=1;j<vec.size();j++) vec[j]-=vec[0]; vec[0]=0;
		for(int j=1;j<vec.size();j++) vec[j]=-vec[j];
		if(mp[vec])
		{
			//for(int i=1;i<=n;i++) cout<<getnum(a[i]^mp[vec])<<" "; cout<<endl;
			cout<<(i<<15)+mp[vec]; return 0;
		}
	}
	puts("-1");
	return 0;
}