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

void write(int x)
{
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}

int n,m;
char s[505][505],ch;

int main()
{
    //freopen("CF948A.in","r",stdin);
    n=read(); m=read();
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='.') {s[i][j]='D'; continue;}
            else if(s[i][j]=='S'&&s[i-1][j]=='W')
            {
                puts("No");
                return 0;
            }
            else if(s[i][j]=='W'&&s[i-1][j]=='S')
            {
                puts("No");
                return 0;
            }
            else if(s[i][j]=='S'&&s[i][j-1]=='W')
            {
                puts("No");
                return 0;
            }
            else if(s[i][j]=='W'&&s[i][j-1]=='S')
            {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
         cout<<s[i][j];
        cout<<endl;
    }
    return 0;
}