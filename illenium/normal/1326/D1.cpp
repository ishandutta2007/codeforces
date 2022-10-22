#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

char s1[maxn];
vector <char> ans;

inline bool jud(int l,int r)
{
	for(int i=l,j=r;i<=j;i++,j--) if(s1[i]!=s1[j]) return false;
	return true;
}

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s1+1); int len=strlen(s1+1),f=0;
		for(int i=1;i<=len;i++) if(s1[i]!=s1[len-i+1]) {f=1; break;}
		if(f==0) {printf("%s",s1+1); puts(""); continue;}
		else
		{
			int h=1,t=len,cnt=0,l1=0,l2=0; ans.clear();
			while(s1[h]==s1[t]&&h<t) ans.push_back(s1[h]),h++,t--;
			for(int i=t;i>=h;i--)
			{
				if(jud(h,i)) {l1=i; break;}
			}
			for(int i=h;i<=t;i++)
			{
				if(jud(i,t)) {l2=i; break;}
			}
			if(l1-h+1>=t-l2+1)
			{
				for(int i=0;i<ans.size();i++) printf("%c",ans[i]);
				for(int i=h;i<=l1;i++) printf("%c",s1[i]);
				for(int i=ans.size()-1;i>=0;i--) printf("%c",ans[i]); puts("");
			}
			else
			{
				for(int i=0;i<ans.size();i++) printf("%c",ans[i]);
				for(int i=l2;i<=t;i++) printf("%c",s1[i]);
				for(int i=ans.size()-1;i>=0;i--) printf("%c",ans[i]); puts("");
			}
		}
		
	}
	return 0;
}