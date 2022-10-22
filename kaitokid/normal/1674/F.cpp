#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
string s[1009];
int pr[1009][1009];
int bit[1000009];
void add(int x,int v)
{
    while(x<=n*m)
    {
        bit[x]+=v;
        x+=(x&(-x));
    }
}
int cal(int x)
{
    int res=0;
    while(x>0)
    {
        res+=bit[x];
        x-=(x&(-x));
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>q;
    for(int i=0;i<n;i++)cin>>s[i];
    int sum=0,num=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
    {
        if(s[j][i]=='.'){sum++;add(i*n+j+1,1);}else num++;

    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(s[x][y]=='.'){num++;add(y*n+x+1,-1);s[x][y]='*';}else {num--;add(y*n+x+1,1);s[x][y]='.';}
        if(num==0){cout<<0<<endl;continue;}
        //cout<<num<<endl;
        cout<<cal(num)<<endl;
    }


    return 0;
}