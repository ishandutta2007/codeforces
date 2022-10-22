#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;
int n,q,sq,st,en;
int qs[300009],qe[300009],qi[300009];
int ans[300009];
int a[300009];
int fr[300009],s[300009],e[300009],wh[300009];
vector<int>v;
bool bl(int x,int y)
{
    return make_pair(qs[x]/sq,qe[x])<make_pair(qs[y]/sq,qe[y]);
}

void add(int x)
{
int f=fr[x];
int u=wh[x],z=e[fr[x]];
 e[f]--;
 if(e[f]<s[f])e[f]=s[f]=0;
 f++;
 if(s[f]==0)s[f]=e[f]=z;
 else s[f]--;

    fr[x]++;
 wh[x]=z;
 wh[v[z]]=u;
 swap(v[u],v[z]);

}
void rem(int x)
{

int f=fr[x];
int u=wh[x],z=s[fr[x]];
 s[f]++;
 if(e[f]<s[f])e[f]=s[f]=0;
 f--;
 if(s[f]==0)s[f]=e[f]=z;
 else e[f]++;

    fr[x]--;
 wh[x]=z;
 wh[v[z]]=u;
 swap(v[u],v[z]);

}
void upd(int x)
{
    while(en<=qe[x])
    add(a[en++]);
    while(st>qs[x])
    add(a[--st]);
    while(en>qe[x]+1)
    rem(a[--en]);
    while(st<qs[x])
    rem(a[st++]);

}
int main()
{
    //ios::sync_with_stdio(0);
    //cin>>n>>q;
  scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
    v.push_back(-1);
    for(int i=1;i<=n;i++)
    {
        v.push_back(i);
        wh[i]=i;
    }
    s[0]=1,e[0]=n;
    sq=sqrt(n);
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&qs[i],&qe[i]);
        qs[i]--;
        qe[i]--;

        qi[i]=i;


    }
        sort(qi,qi+q,bl);
    st=en=0;
     for(int i=0;i<q;i++)
     {
    int  u=qi[i];

    upd(u);
    int p=v.size()-1;
    int z=fr[v[p]];
    int g=qe[u]-qs[u]+1;
    int st=0,en=g;
    while(en>st)
    {
        int mid=(st+en)/2;
        if((z-mid)>(g-mid+1)/2)st=mid+1;
        else en=mid;
    }
ans[u]=st+1;

     }

    for(int i=0;i<q;i++)
        printf("%d\n",ans[i]);

    return 0;
}