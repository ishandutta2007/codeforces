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

int cnt[30];
char s1[maxn],s2[maxn];
vector <int> vec;
vector <int> ans1,ans2;

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),fl=0;
		memset(cnt,0,sizeof(cnt));
		scanf("%s",s1+1); scanf("%s",s2+1);
		int len1=strlen(s1+1),len2=strlen(s2+1);
		if(len1!=len2) {puts("No"); continue;}
		for(int i=1;i<=len1;i++) cnt[s1[i]-'a']++;
		for(int i=1;i<=len2;i++) cnt[s2[i]-'a']++;
		for(int i=1;i<=26;i++)
		{
			if(cnt[i]%2!=0)
			{
				fl=1;
				break;
			}
		}
		if(fl==1) {puts("No"); continue;}
		for(int i=1;i<=len1;i++) if(s1[i]!=s2[i]) vec.push_back(i);
		for(int i=0;i<vec.size();i++)
		{
			if(s1[vec[i]]==s2[vec[i]]) continue;
			for(int j=i+1;j<vec.size();j++)
			{
				if(s1[vec[i]]==s2[vec[j]])
				{
					ans1.push_back(vec[j]);
					ans2.push_back(vec[j]);
					swap(s1[vec[j]],s2[vec[j]]);
					ans1.push_back(vec[j]);
					ans2.push_back(vec[i]);
					swap(s1[vec[j]],s2[vec[i]]);
					break;
				}
				else if(s1[vec[i]]==s1[vec[j]])
				{
					ans1.push_back(vec[j]);
					ans2.push_back(vec[i]);
					swap(s1[vec[j]],s2[vec[i]]);
					break;
				}
				
			}
		}
		puts("Yes");
		cout<<ans1.size()<<endl;
		for(int i=0;i<ans1.size();i++) printf("%d %d\n",ans1[i],ans2[i]);
		vec.clear(); ans1.clear(); ans2.clear();
	}
	return 0;
}