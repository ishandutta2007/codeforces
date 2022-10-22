#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct nod{
ll a[2][2];

};
int n;
nod mrg(nod x,nod y)
{
    nod res;
    res.a[0][0]=min(x.a[0][0]+y.a[0][0],x.a[0][1]+y.a[1][0]);
    res.a[0][1]=min(x.a[0][0]+y.a[0][1],x.a[0][1]+y.a[1][1]);
    res.a[1][1]=min(x.a[1][0]+y.a[0][1],x.a[1][1]+y.a[1][1]);
    res.a[1][0]=min(x.a[1][0]+y.a[0][0],x.a[1][1]+y.a[1][0]);
    return res;
}
nod sg[400009];
nod f[100009];
nod cal(int l,int r,int x=0,int st=0,int en=n-2)
{
    if(l>en|| st>r ||l>r)
    {
        nod res;
        res.a[0][0]=res.a[1][1]=0;
        res.a[1][0]=res.a[0][1]=100000000009;
        return res;
    }
   if(st>=l && r>=en)return sg[x];
   int mid=(st+en)/2;
   return mrg(cal(l,r,2*x+1,st,mid),cal(l,r,2*x+2,mid+1,en));

}
void build(int x=0,int st=0,int en=n-2)
{
    if(st==en){sg[x]=f[st];return;}
    int mid=(st+en)/2;
    build(2*x+1,st,mid);
    build(2*x+2,mid+1,en);
    sg[x]=mrg(sg[2*x+1],sg[2*x+2]);
}
int a[100009][2][2];
int cl(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n-1;i++)cin>>a[i][0][0]>>a[i][0][1]>>a[i][1][0]>>a[i][1][1];
    for(int i=0;i<n-2;i++)
        for(int j=0;j<2;j++)
        for(int k=0;k<2;k++)
        f[i].a[j][k]=1+cl(a[i][j][0]+(j==0),a[i][j][1]+(j==1),a[i+1][k][0],a[i+1][k][1]);


   build();
  int q;

   cin>>q;
   while(q--)
   {
       int x1,x2,y1,y2,u1,u2;
       cin>>x1>>y1>>x2>>y2;
       u1=max(x1,y1)-1;
       u2=max(x2,y2)-1;
       if(u1==u2){cout<<cl(x1,y1,x2,y2)<<endl;continue;}
       if(u1>u2)
       {
           swap(x1,x2);
           swap(y1,y2);
           swap(u1,u2);
       }
       nod g=cal(u1,u2-2);
       ll res=LLONG_MAX;
       for(int j=0;j<2;j++)
        for(int k=0;k<2;k++)
        res=min(res,1+cl(x1,y1,a[u1][j][0],a[u1][j][1])+g.a[j][k]+cl(a[u2-1][k][0]+(k==0),a[u2-1][k][1]+(k==1),x2,y2));
        cout<<res<<endl;
   }


    return 0;
}