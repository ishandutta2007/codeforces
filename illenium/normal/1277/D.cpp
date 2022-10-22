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
#define ull unsigned long long
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ull h1[maxn],h2[maxn];
char s[maxn];
map <ull,int> mp;
vector <int> vec1,vec2,ans;

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),t1=0,t2=0,f1=0,f2=0; mp.clear();
		vec1.clear(); vec2.clear(); ans.clear();
		for(int i=1;i<=n;i++) h1[i]=0,h2[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			int len=strlen(s+1);
			if(s[1]=='0'&&s[len]=='1')
			{
				t1++;
				ull tmp1=0,tmp2=0;
				for(int j=1;j<=len;j++) tmp1=tmp1*233+s[j];
				for(int j=len;j>=1;j--) tmp2=tmp2*233+s[j];
				h1[i]=tmp1; h2[i]=tmp2; mp[tmp1]=1;
				vec1.push_back(i);
			}
			else if(s[1]=='1'&&s[len]=='0')
			{
				t2++;
				ull tmp1=0,tmp2=0;
				for(int j=1;j<=len;j++) tmp1=tmp1*233+s[j];
				for(int j=len;j>=1;j--) tmp2=tmp2*233+s[j];
				h1[i]=tmp1; h2[i]=tmp2; mp[tmp1]=1;
				vec2.push_back(i);
			}
			else if(s[1]=='0'&&s[len]=='0') f1=1;
			else if(s[1]=='1'&&s[len]=='1') f2=1;
		}
		if(t1>t2)
		{
			for(int i=0;i<vec1.size()&&(t1-t2)>1;i++)
			{
				if(mp[h2[vec1[i]]]) continue;
				else ans.push_back(vec1[i]);
				t1--; t2++;
			}
		}
		else
		{
			for(int i=0;i<vec2.size()&&(t2-t1)>1;i++)
			{
				if(mp[h2[vec2[i]]]) continue;
				else ans.push_back(vec2[i]);
				t2--; t1++;
			}
		}
		if(abs(t1-t2)>1||((t1+t2==0)&&(f1+f2==2))) puts("-1");
		else
		{
			cout<<ans.size()<<endl;
			for(int i=0;i<ans.size();i++) printf("%d ",ans[i]); puts("");
		}
	}
	return 0;
}