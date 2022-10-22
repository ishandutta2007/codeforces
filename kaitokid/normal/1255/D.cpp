#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,r,c,k;
char a[103][103],ans[103][103];
int main()
{

  ios::sync_with_stdio(0);
cin>>t;
while(t--)
{
    cin>>r>>c>>k;
    int u=0;

    for(int i=0;i<r;i++)for(int j=0;j<c;j++)
    {
    cin>>a[i][j];
    if(a[i][j]=='R')u++;
    }
    int d=u/k;
    int l=u%k;
    char x='a';
    int s=0;
    for(int i=0;i<r;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<c;j++)
            {
                            if(a[i][j]=='R')s++;
                if(l>0&&s>(d+1)){l--;s=1;if(x=='z'){x='A';ans[i][j]=x;continue;}if(x=='Z')x='0';else x++;ans[i][j]=x;continue;}
            if(l==0&&s>d){s=1;if(x=='z'){x='A';ans[i][j]=x;continue;}if(x=='Z')x='0';else x++;ans[i][j]=x;continue;}
                ans[i][j]=x;

            }
        }
        else
        {
            for(int j=c-1;j>=0;j--)
            {
                if(a[i][j]=='R')s++;
                if(l>0&&s>(d+1)){l--;s=1;if(x=='z'){x='A';ans[i][j]=x;continue;}if(x=='Z')x='0';else x++;ans[i][j]=x;continue;}
            if(l==0&&s>d){s=1;if(x=='z'){x='A';ans[i][j]=x;continue;}if(x=='Z')x='0';else x++;ans[i][j]=x;continue;}
                ans[i][j]=x;

            }
        }

    }
    for(int i=0;i<r;i++){for(int j=0;j<c;j++)cout<<ans[i][j]; cout<<endl;}
}
return 0;
}