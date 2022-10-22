#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct nod
{
    int a[3][3];
    nod()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)a[i][j]=0;
    }

};
nod mrg(nod x,nod y)
{
    nod res=nod();

        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)res.a[i][j]=1000000000;
      for(int i=0;i<3;i++)
                for(int j=i;j<3;j++)
                for(int k=j;k<3;k++)
                res.a[i][k]=min(res.a[i][k],x.a[i][j]+y.a[j][k]);
return res;
}
nod ff[4];
nod sg[400009];
int n;
string s;
void build(int st=0,int en=n-1,int u=0)
{
    if(st==en)
    {
        sg[u]=ff[s[st]-'a'];
        return ;
    }
   int mid=(st+en)/2;
   build(st,mid,2*u+1);
   build(mid+1,en,2*u+2);
   sg[u]=mrg(sg[2*u+1],sg[2*u+2]);

}
void ch(int pos,int st=0,int en=n-1,int u=0)
{
    if(pos<st||pos>en)return ;
    if(st==en)
    {
        sg[u]=ff[s[st]-'a'];
        return ;
    }
    int mid=(st+en)/2;
   ch(pos,st,mid,2*u+1);
   ch(pos,mid+1,en,2*u+2);
   sg[u]=mrg(sg[2*u+1],sg[2*u+2]);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>n>>q;
    cin>>s;
    for(int i=0;i<3;i++)
    {
        ff[i]=nod();
        ff[i].a[i][i]=1;
    }
    build();
   // cout<<sg[0].a[0][0]<<" "<<sg[0].a[0][1]<<" "<<sg[0].a[0][2]<<endl;
    while(q--)
    {
          int pos;
        char c;
        cin>>pos>>c;
        pos--;
        s[pos]=c;
      ch(pos);
      cout<<min(sg[0].a[0][2],min(sg[0].a[0][1],sg[0].a[0][0]))<<endl;
    }
    return 0;
}