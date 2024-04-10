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

char s[maxn];
bool f[30];
vector <char> ans;

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		if(strlen(s+1)==1) {cout<<s[1]<<endl; continue;}
		for(int i=1;i<=strlen(s+1);i++)
		{
			int cnt=1;
			while(s[i]==s[i+1]) i++,cnt++;
			if((cnt%2==1)&&f[s[i]-'a']==0) ans.push_back(s[i]),f[s[i]-'a']=1;
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++) cout<<ans[i]; cout<<endl;
		ans.clear(); memset(f,0,sizeof(f));
	}
	return 0;
}