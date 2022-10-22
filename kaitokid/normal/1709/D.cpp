#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int h[300009][20],lg[200009];
int cal(int x,int y)
{
    int u=lg[y-x+1];
    return max(h[x][u],h[y-(1<<u)+1][u]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    for(int i=2;i<=200003;i++)lg[i]=lg[i/2]+1;
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>h[i][0];
    for(int i=1;(1<<i)<=m;i++)
        for(int j=1;j+(1<<i)<=m+2;j++)
        h[j][i]=max(h[j][i-1],h[j+(1<<(i-1))][i-1]);
    int q;
    cin>>q;
    while(q--)
    {
        int x1,y1,x2,y2,k;
        cin>>x1>>y1>>x2>>y2>>k;
        if(y1>y2){swap(x1,x2);swap(y1,y2);}
        int g= g=max(x1,x2)-min(x1,x2);
        if(g%k){cout<<"NO"<<endl;continue;}
        g=max(y1,y2)-min(y1,y2);
        if(g%k){cout<<"NO"<<endl;continue;}
        int v=(n-x1)/k;
        int r=x1+v*k;
        int f=cal(y1,y2);
        if(f>=r)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        }

    return 0;
}