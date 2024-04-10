#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
char s[1000009][5];
int ans[1000009][10];
int n,m;
int go(int x ,int l)
{
    string y="";
    for(int i=0;i<m;i++)y+=s[l][i];
    int res=0;
    for(int i=0;i<y.size();i++)
    {
        if((x&(1<<i))==0){if(y[i]=='1')res++;continue;}
    if(y[i]=='0')res++;
    }
    return res;
}
bool fuck(int x,int y)
{
for(int i=0;i<m-1;i++)
{
    int res=0;
    if(x&(1<<i))res++;
    if(y&(1<<i))res++;
    int u=i+1;
    if(x&(1<<u))res++;
    if(y&(1<<u))res++;
if(res%2==0)return false;
}
return true;
}

int main()
{
ios::sync_with_stdio(0);

cin>>n>>m;
if((n>=4)&&(m>=4)){cout<<-1;return 0;}
for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if(n>=m)cin>>s[i][j];
        else cin>>s[j][i];
    }
if(m>n)swap(n,m);
if(n==1||m==1){cout<<0;return 0;}
for(int i=0;i<(1<<m);i++)
{
    ans[0][i]=go(i,0);
}
for(int i=0;i<n;i++)
{
    for(int j=0;j<(1<<m);j++)
    {
        ans[i][j]=go(j,i);
     int u=1e8;
     for(int q=0;q<(1<<m);q++)
            if(fuck(q,j))u=min(u,ans[i-1][q]);
     ans[i][j]+=u;
    }
}
int res=1e8;
for(int i=0;i<(1<<m);i++)res=min(res,ans[n-1][i]);
if(res>=(1e8)){cout<<-1;return 0;}
cout<<res;
    return 0;
}