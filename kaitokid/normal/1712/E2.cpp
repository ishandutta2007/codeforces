#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dv[2000009];
ll id[200009],l[200009],r[200009];
ll bit[200009],ans[200009];
bool bl(int x,int y)
{
    return l[x]<l[y];
}
void add(int x,ll u)
{
    while(x<=200000){bit[x]+=u;x+=(x&(-x));}
}
ll cal(int x)
{
    ll res=0;
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
    memset(bit,0,sizeof bit);
    memset(dv,0,sizeof dv);

    for(int i=1;i<=200000;i++)
        for(int j=2*i;j<=200000;j+=i)dv[j]++;
    for(int i=1;i<=200000;i++)add(i,(dv[i]*(dv[i]-1))/2);

    int t;
    cin>>t;
   for(int i=0;i<t;i++)
    {
        cin>>l[i]>>r[i];
        id[i]=i;
    }
    sort(id,id+t,bl);
    int z=1;

    for(int qq=0;qq<t;qq++)
    {
        int u=id[qq];
        while(z<l[u])
        {
            for(int i=2*z;i<=200000;i+=z)
                {
                    add(i,-1*(dv[i]*(dv[i]-1))/2);dv[i]--;
            add(i,(dv[i]*(dv[i]-1))/2);}
            z++;

            }

            ans[u]=cal(r[u])-cal(l[u]-1);

    }
    for(int i=0;i<t;i++)
    {
        ll p=r[i]-l[i]+1;
        ans[i]=p*(p-1)*(p-2)/6-ans[i];
        int ff=2*l[i];
        if(ff>r[i])continue;
        ans[i]-=(r[i]/6)-((ff-1)/6);
    }
    for(int i=0;i<t;i++)
    {
        int ff=5*l[i];
        ff=(ff+1)/2;
        if(ff>r[i])continue;
        ans[i]-=(r[i]/15)-((ff-1)/15);
    }
    for(int i=0;i<t;i++)cout<<ans[i]<<endl;
    return 0;
}