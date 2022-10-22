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

struct node{int a,b;};

inline bool operator < (node a,node b)
{
	if(a.a==b.a) return a.b<b.b;
	return a.a<b.a;
}

vector <node> p[maxn];
map < vector <node>,int > mp;
ll ans;
//map < vector <node>,int >::iterator it;

inline bool jud(vector <node> a,vector <node> b)
{
	for(int i=0;i<a.size();i++)
	{
		node x=a[i],y=b[i];
		if(x.a!=y.a||x.b!=y.b) return false;
	}
	return true;
}

int main()
{
	int n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),cnt=0;
		for(int j=2;j<=sqrt(x);j++)
		{
			cnt=0;
			if(x%j==0)
			{
				while(x%j==0) x/=j,cnt++;
				cnt%=k;
				if(cnt!=0) p[i].push_back((node){j,cnt});
			}
		}
		if(x!=1) p[i].push_back((node){x,1});
		mp[p[i]]++;
		//for(int j=0;j<p[i].size();j++) cout<<p[i][j].a<<" "<<p[i][j].b<<endl;
		//cout<<endl;
	}
	//cout<<mp.size()<<endl<<endl;
	for(map < vector <node>,int >::iterator it=mp.begin();it!=mp.end();it++)
	{
		vector <node> vec=it->first;
		vector <node> tmp;
		for(int i=0;i<vec.size();i++)
		{
			int t1=vec[i].a,t2=k-vec[i].b;
			tmp.push_back((node){t1,t2});
		}
		int tmp2=mp[tmp]; ll q=(it->second);
		if(jud(tmp,vec)) ans+=(q*(q-1));
		else ans+=(tmp2)*(q);
	}
	cout<<ans/2<<endl;
	return 0;
}