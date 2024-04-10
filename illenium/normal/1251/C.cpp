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
#define maxn 500005
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
vector <int> v1,v2;

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int i=1;i<=len;i++)
		{
			//cout<<s[i]-'0'<<endl;
			if((s[i]-'0')%2==1) v1.push_back((s[i]-'0'));
			else v2.push_back((s[i]-'0'));
		}
		int cnt1=0,cnt2=0;
		for(int i=1;i<=len;i++)
		{
			if(cnt1==v1.size()) 
			{
				for(int j=cnt2;j<v2.size();j++) printf("%d",v2[cnt2]),cnt2++;
				break;
			}
			if(cnt2==v2.size())
			{
				for(int j=cnt1;j<v1.size();j++) printf("%d",v1[cnt1]),cnt1++;
				break;
			}
			
			if(v1[cnt1]<v2[cnt2]) printf("%d",v1[cnt1]),cnt1++;
			else printf("%d",v2[cnt2]),cnt2++;
		}
		v1.clear(); v2.clear();
		puts("");
	}
	return 0;
}