#include <bits\stdc++.h>

using namespace std;
    const int maxn=1e6;
    int a[maxn],c[maxn],b[maxn];
    const int inf=2e9;

    vector<int > t[4*maxn];

    #define F first
    #define S second
   // #define
   // #define mp make_pair
    #define pb push_back
    #define ll long long
int it=0;
void build (int v,int tl,int tr)
{
    if (tl==tr)
        t[v] = vector<int> (1,a[tl]);
    else
    {
        int tm=(tl+tr)>>1;
        build (v*2,tl,tm);
        build (v*2+1,tm+1,tr);
        merge(t[v*2].begin(), t[v*2].end() , t[v*2+1].begin() , t[v*2+1].end(),back_inserter(t[v]) );
    }
}


int findm(int v,int x)
{
    int l=0,r=t[v].size()-1;
    if (it==1)
    {

    }
    while (r-l>1)
    {
        int m=(l+r)>>1;
        if (t[v][m]>=x)
            r=m;
        else
            l=m;
    }

    int ans=0;
    if (t[v][r]<x)
        ans=r+1;
    else
    if (t[v][l]<x)
        ans=l+1;
    else
    if (l>0)
    if (t[v][l-1]<x)
        ans=l;
    return ans;
}

int getm(int v,int tl,int tr,int l,int r,int x)
{

        if (l>r)
            return 0;
        if (it==1)
        {

        }
        if (l==tl&&r==tr)
        {
           return findm(v,x);
        }

        int tm=(tl+tr)>>1;

        int left_segment=getm(v*2,tl,tm,l,min(r,tm),x);
        int right_segment=getm(v*2+1,tm+1,tr,max(l,tm+1),r,x);
        return left_segment+right_segment;
}

int main()
{
    int n,m;
     //   freopen("input.txt","r",stdin);
   // freopen("output2.txt","w",stdout);//freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    scanf("%d",&n);

    for (int i=0;i<n;i++)
        scanf("%d",&b[i]);


    map<int,int> mp;
    memset(a,0,sizeof(a));
    mp[b[n-1]]=1;
    a[n-1]=1;

    for (int i=n-2;i>=0;i--)
    {
        if (mp.count(b[i])>0)
           {
                mp[b[i]]++;
                a[i]=mp[b[i]];
           }
        else
        {
                mp[b[i]]=1;
                a[i]=1;
        }
    }

    build(1,0,n-1);

  //  cin>>m;

    mp.clear();
    memset(c,0,sizeof(c));
    long long ans=0;

    for (int i=0;i<n-1;i++)
    {
        if (i==7)
            it=1;
        else
            it=0;
        if (mp.count(b[i])>0)
        {
            mp[b[i]]++;
            c[i]=mp[b[i]];
        }
        else
        {
            mp[b[i]]=1;
            c[i]=1;
        }

        ans+=1LL*getm(1,0,n-1,i+1,n-1,c[i]);
    }


    printf("%I64d",ans);
    return 0;
}