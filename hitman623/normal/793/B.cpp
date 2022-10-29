#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long visi[1003][1003]={0},f=0;
long n,m,i,j,xs,xt,ys,yt;
string s[1003];
int main()
{
    cin>>n>>m;
    for(i=0;i<n;++i)
    cin>>s[i];
    for(i=0;i<n;++i)
    for(j=0;j<m;++j)
    if(s[i][j]=='S')
    {xs=i;ys=j;}
    else if(s[i][j]=='T')
    {xt=i;yt=j;}
    if(xs>xt) {swap(xs,xt);swap(ys,yt);}
    for(j=0;j<m;++j)
    {
        f=1;
        for(i=xs;i<=xt;++i)
        if(s[i][j]=='*') f=0;
        if(f)
        {
            if(ys>j)
            {
                for(i=j;i<=ys;++i)
                if(s[xs][i]=='*') f=0;
            }
            else
            {
                for(i=ys;i<=j;++i)
                if(s[xs][i]=='*') f=0;
            }
            if(yt>j)
            {
                for(i=j;i<=yt;++i)
                if(s[xt][i]=='*') f=0;
            }
            else
            {
                for(i=yt;i<=j;++i)
                if(s[xt][i]=='*') f=0;
            }
        }
        if(f) {cout<<"YES";exit(0);}
    }
    if(ys>yt) {swap(xs,xt);swap(ys,yt);}
    for(j=0;j<n;++j)
    {
        f=1;
        for(i=ys;i<=yt;++i)
        if(s[j][i]=='*') f=0;
        if(f)
        {
            if(xs>j)
            {
                for(i=j;i<=xs;++i)
                if(s[i][ys]=='*') f=0;
            }
            else
            {
                for(i=xs;i<=j;++i)
                if(s[i][ys]=='*') f=0;
            }
            if(xt>j)
            {
                for(i=j;i<=xt;++i)
                if(s[i][yt]=='*') f=0;
            }
            else
            {
                for(i=xt;i<=j;++i)
                if(s[i][yt]=='*') f=0;
            }
        }
        if(f) {cout<<"YES";exit(0);}
    }
    cout<<"NO";
    return 0;
}