//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned short us;
typedef unsigned int ui;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc
struct point
{
	int score,last;
};
bool operator >(const point &p1,const point &p2)
{
	return p1.score!=p2.score?p1.score>p2.score:p1.last<p2.last;
}
map<string,vector<point> >S;
point qiu(const vector<point> &a)
{
	int sum=0;
	for(auto it=a.begin();it!=a.end();++it)sum+=it->score;
	int now=0;
	for(auto it=a.begin();it!=a.end();++it)
	{
		now+=it->score;
		if(now>=sum)return (point){sum,it->last};
	}
}

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int tt=read();
	string s;
	rep(i,1,tt)
	{
		cin>>s;
		S[s].pb((point){read(),i});
	}
	auto it=S.begin();
	auto ans=it;point ansp=qiu(ans->second);
	while(++it!=S.end())
	{
		point itp=qiu(it->second);
		if(itp>ansp){ans=it;ansp=itp;}
	}
	cout<<ans->first;
}