#include<bits/stdc++.h>
using namespace std;
const int N=77;
int n,m;
char s[N][N];
bool judge1()
{
    bool f1=true,f2=true,f3=true,f4=true;
    for(int i=1;i<=m;i++)
    {
        if(s[1][i]!='A') f1=false;
        if(s[n][i]!='A') f2=false;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i][1]!='A') f3=false;
        if(s[i][m]!='A') f4=false;
    }
    return f1|f2|f3|f4;
}
bool judge2()
{
    if(s[1][1]=='A'||s[1][m]=='A'||s[n][1]=='A'||s[n][m]=='A') return true;
    for(int i=1;i<=n;i++)
    {
        bool flag=true;
        for(int j=1;j<=m;j++)
        if(s[i][j]!='A') {flag=false;break;}
        if(flag) return true;
    }
    for(int j=1;j<=m;j++)
    {
        bool flag=true;
        for(int i=1;i<=n;i++)
            if(s[i][j]!='A'){flag=false;break;}
        if(flag) return true;
    }
    return false;
}
bool judge3()
{
    for(int i=1;i<=m;i++)
    {
        if(s[1][i]=='A') return true;
        if(s[n][i]=='A') return true;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i][1]=='A') return true;
        if(s[i][m]=='A') return true;
    }
    return false;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        int tot=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            if(s[i][j]=='P') tot++;
        if(tot==n*m) printf("MORTAL\n");
        else if(tot==0) printf("0\n");
        else if(judge1()) printf("1\n");
        else if(judge2()) printf("2\n");
        else if(judge3()) printf("3\n");
        else printf("4\n");;
    }
}