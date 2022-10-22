#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
ull h1[maxn],h2[maxn],len,b[maxn];
const ll mod=1000000007;
 
inline ull gh(int p1,int l,int r)
{
	if(p1==1) return (h1[r]-h1[l-1]*b[r-l+1]%mod+mod)%mod;
	else return (h2[l]-h2[r+1]*b[r-l+1]%mod+mod)%mod;
}
 
inline bool jud(int l,int r)
{
	ull p1=gh(1,l,r),p2=gh(2,l,r);
	//cout<<p1<<" "<<p2<<endl;
	if(p1==p2) return true; return false;
}
 
int main()
{
	int T=read(); b[0]=1;
	for(int i=1;i<=maxn-5;i++) b[i]=(b[i-1]*233)%mod;
	while(T--)
	{
		scanf("%s",s1+1); int len=strlen(s1+1),f=0;
		for(int i=1;i<=len;i++) h1[i]=(h1[i-1]*233+s1[i])%mod;
		for(int i=len;i>=1;i--) h2[i]=(h2[i+1]*233+s1[i])%mod;
		for(int i=1;i<=len;i++) if(s1[i]!=s1[len-i+1]) {f=1; break;}
		if(f==0) {printf("%s",s1+1); puts(""); continue;}
		else
		{
			//cout<<jud(5,9)<<endl;
			int h=1,t=len,cnt=0,l1=0,l2=0; ans.clear();
			while(s1[h]==s1[t]&&h<t) ans.push_back(s1[h]),h++,t--;
			for(int i=t;i>=h;i--) if(jud(h,i)) {l1=i; break;}
			for(int i=h;i<=t;i++) if(jud(i,t)) {l2=i; break;}
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
	return 0;;
}