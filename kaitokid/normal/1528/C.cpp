#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>ch[300009],v[300009];
int inn[300009],ot[300009],ti;
int rs,res,sg[1400000];
set<int>st;
int n;
int cal(int x,int st=0,int en=n-1,int u=1)
{
    if(x<st||x>en)return 0;
    if(sg[u]!=0){return sg[u];}
    if(st==en)return 0;
    int mid=(st+en)/2;
    if(x<=mid)return cal(x,st,mid,2*u);
   else  return cal(x,mid+1,en,2*u+1);
}

void chn(int l,int r,int val,int st=0,int en=n-1,int u=1)
{
    if(l<=st&&r>=en){sg[u]=val;return;}
    if(l>en||st>r)return;
    int mid=(st+en)/2;
    chn(l,r,val,st,mid,2*u);
    chn(l,r,val,mid+1,en,2*u+1);

}
void add(int x)
{
    chn(inn[x],ot[x],x);
    st.insert(inn[x]);
    rs++;
}
void rem(int x)
{
    chn(inn[x],ot[x],0);
    st.erase(inn[x]);
    rs--;
}
void go(int x)
{
    inn[x]=ti++;

    for(int i=0;i<v[x].size();i++)go(v[x][i]);
    ot[x]=ti-1;

}

void ans(int x)
{
    set<int>::iterator it=st.upper_bound(inn[x]);
    int u=-1;
    if((it==st.end())||((*it)>ot[x]))
    {
         u=cal(inn[x]);
        if(u!=0)rem(u);
        add(x);

    }
    res=max(res,rs);
    for(int i=0;i<ch[x].size();i++)ans(ch[x][i]);
    if(u==-1)return;
    if(u==0){rem(x);return;}
    rem(x);
    add(u);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 int t;
 cin>>t;
 while(t--)
 {
     st.clear();
     cin>>n;
     for(int i=0;i<4*n;i++)sg[i]=0;
     for(int i=0;i<=n;i++){ch[i].clear();v[i].clear();}
     for(int i=2;i<=n;i++)
     {
         int x;
         cin>>x;
         ch[x].push_back(i);
     }
     for(int i=2;i<=n;i++)
     {
         int x;
         cin>>x;
         v[x].push_back(i);
     }
    ti=rs=res=0;
    go(1);
    ans(1);
    cout<<res<<endl;
 }
    return 0;
}