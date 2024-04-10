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

char s1[maxn],s2[maxn];
vector <int> ans1,ans2;

inline void rev(int x,int y)
{
	for(int i=0;x+i<=y-i;i++) swap(s1[x+i],s1[y-i]);
}

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),k=read(); k--; scanf("%s",s1+1);
		for(int i=1;i<=k;i++) s2[2*i-1]='(',s2[2*i]=')';
		int tmp=(n-2*k)/2;
		for(int i=1;i<=tmp;i++) s2[i+2*k]='(',s2[i+tmp+2*k]=')';
		for(int i=1;i<=n;i++)
		{
			if(s1[i]==s2[i]) continue;
			else
			{
				for(int j=i+1;j<=n;j++) if(s1[j]==s2[i])
				{
					rev(i,j);
					ans1.push_back(i); ans2.push_back(j);
					break;
				}
			}
		}
		printf("%d\n",ans1.size());
		for(int i=0;i<ans1.size();i++) printf("%d %d\n",ans1[i],ans2[i]);
		//for(int i=1;i<=n;i++) cout<<s1[i]; cout<<endl<<endl;
		ans1.clear(); ans2.clear();
	}
	return 0;
}