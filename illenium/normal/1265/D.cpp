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
#define p 998244353
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int a,b,c,d,f,a1,b1,c1,d1;
vector <int> ans;

inline void dfs(int nw,int dep)
{
	if(dep==a+b+c+d)
	{
		ans.push_back(nw);
		f=1; return;
	}
    if(nw==0)
    {
        a1--; ans.push_back(0);
        if(b1) dfs(1,dep+1);
        else return;
    }
    else if(nw==1)
    {
        b1--; ans.push_back(1);
        if(a1) dfs(0,dep+1);
        else if(c1) dfs(2,dep+1);
        else return;
    }
    else if(nw==2)
    {
        c1--; ans.push_back(2);
        if(d1) dfs(3,dep+1);
        else if(b1) dfs(1,dep+1);
        else return;
    }
    else if(nw==3)
    {
        d1--; ans.push_back(3);
        if(c1) dfs(2,dep+1);
        else return;
    }

}

int main()
{
	cin>>a>>b>>c>>d;
    ans.clear(); a1=a;b1=b;c1=c;d1=d; if(a1) dfs(0,1);
    if(f)
    {
        puts("YES");
        for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
        return 0;
    }
    ans.clear(); a1=a;b1=b;c1=c;d1=d; if(b1) dfs(1,1);
    if(f)
    {
        puts("YES");
        for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
        return 0;
    }
    ans.clear(); a1=a;b1=b;c1=c;d1=d; if(c1) dfs(2,1);
    if(f)
    {
        puts("YES");
        for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
        return 0;
    }
    ans.clear(); a1=a;b1=b;c1=c;d1=d; if(d1) dfs(3,1);
    if(f)
    {
        puts("YES");
        for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
        return 0;
    }
    puts("NO");
	return 0;
}