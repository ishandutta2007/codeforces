#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll sp[200009][20][3];
int lg[200009];
ll a[200009][3];
int cal(int x,int y,int u)
{
    int d=lg[y-x+1];
    int ans=sp[x][d][u];
    if(a[sp[y-(1<<d)+1][d][u]][u]>a[ans][u])ans=sp[y-(1<<d)+1][d][u];
    return ans;

}
int go(int l,int r)
{
    if(l==r)return true;

    int u=cal(l,r,0);

    if(r>u)
    {
        int f=cal(u+1,r,1);
        if(a[f][1]>a[u][1])return false;
        if(!go(u+1,r))return false;
    }
    if(l<u)
    {
        int f=cal(l,u-1,2);
        if(a[f][2]>a[u][2])return false;
        if(!go(l,u-1))return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=2;i<200002;i++) lg[i]=lg[i-1]+((i&(i-1))==0);
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0];
        sp[i][0][0]=i;
    }
    for(int i=1;i<=n;i++)
    {
        a[i][1]=a[i][0];
        a[i][1]+=a[i-1][1];
        sp[i][0][1]=i;
    }
    for(int i=n;i>=0;i--)
    {
        a[i][2]=a[i][0];
        if(i<n)a[i][2]+=a[i+1][2];
        sp[i][0][2]=i;
    }
    for(int u=0;u<3;u++)
     for(int j=1;(1<<j)<=n+1;j++)
    for(int i=0;i+(1<<j)<=n+1;i++)
    {sp[i][j][u]=sp[i][j-1][u];
    if(a[sp[i+(1<<(j-1))][j-1][u]][u]>a[sp[i][j][u]][u])sp[i][j][u]=sp[i+(1<<(j-1))][j-1][u];
    }
    if(go(1,n))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }


    return 0;

}