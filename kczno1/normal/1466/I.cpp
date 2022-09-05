//#pragma GCC target("avx,avx2")	
#include<bits/stdc++.h>
//#include<immintrin.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
char readc()
{
	char c;
	while(isspace(gc));
	return c;
}
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

string ans;
int b;
void print(int i,string str)
{
	cout<<i<<" "<<ans+str+string(b-ans.size()-str.size(),'1')<<endl;
	cout.flush();
}	
bool query(int i,string str)
{
	print(i,str);
	string ans;
	cin>>ans;
	return ans[0]=='y';
}


int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,b;
	cin>>n>>b;
	::b=b;
	vector<int>q;
	rep(i,1,n)q.push_back(i);
	while(b)
	{
		string now;
		vector<int>st;
		for(auto x:q)
		{
			int m;
			while((m=st.size()) && query(x,now)) 
			{
				st.pop_back();
				now.pop_back();
			}
			if(m<b)
			{
				st.push_back(x);
				now.push_back('0'+query(x,now+'0'));
			}
		}

		int m=st.size();
		per(k,m-1,1)
		{
			int x=st[k-1];
			if(query(x,now))
				now=string(now,0,k);
		}
		ans=ans+now;
		b-=now.size();
		q=vector<int>(st.begin(),st.begin()+now.size());
	}
	print(0,"");
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/