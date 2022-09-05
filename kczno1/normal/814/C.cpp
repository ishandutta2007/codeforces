#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1505;
int n;
char s[N];
int have[N][26];
char ch[5];
int solve()
{
	int m;
	scanf("%d%s",&m,&ch);
    	char c=ch[0];
    	int &ans=have[m][c-'a'];
    	if(ans)return ans;
    int l=1,r=1,cnt=0;
    do
    {
      while(r<=n&&cnt+(s[r]!=c)<=m) 
      {
      	  cnt+=s[r]!=c;
		  ++r; 
      }
      ans=max(ans,r-l);
      cnt-=s[l]!=c;++l; 
	}while(r<=n);
	return ans;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
    	printf("%d\n",solve());
    }
}