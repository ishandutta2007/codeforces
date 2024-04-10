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
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mp make_pair
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

const int N=1e3+5;
string a[N];int n;

int main()
{
//	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	string s;int mx=0;
	while(getline(cin,s))
	{
		a[++n]=s;
		chmax(mx,(int)s.size());
	}
	cout<<string(mx+2,'*')<<endl;
	bool ji=0;
	rep(i,1,n)
	{
		int d=mx-a[i].size();
		int l=d/2,r=d/2;
		if(d%2){ji^=1;if(ji)++r;else ++l;}
		cout<<'*'<<string(l,' ')<<a[i]<<string(r,' ')<<'*'<<endl;
	}
	cout<<string(mx+2,'*')<<endl;
}