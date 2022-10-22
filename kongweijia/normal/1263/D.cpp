#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define MAXN 100000
#define infty 0x3f3f3f3f

#define pb push_back
#define mp make_pair
#define xx first
#define yy second

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;

//head
int fa[30];
bool mark[30];

int getfa(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=getfa(fa[x]);
}

int main()
{
    rep(i,1,26) fa[i]=i;
	int n; scanf("%d",&n);
    rep(i,1,n)
    {
        char s[55]; scanf("%s",s+1);
        int l=strlen(s+1);
        rep(j,1,l) mark[s[j]-'a'+1]=1;
        rep(j,1,l-1)
        {
            int x=s[j]-'a'+1;
            int y=s[j+1]-'a'+1;
            int fx=getfa(x);
            int fy=getfa(y);
            if(fx!=fy) fa[fx]=fy;
        }
    }
    int ans=0;
    rep(i,1,26) if(mark[i] && getfa(i)==i) ans++;
    printf("%d\n",ans);
	return 0;
}