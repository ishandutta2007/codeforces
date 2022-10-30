#include <iostream>
#include<algorithm>
#include<set>

using namespace std;

typedef pair<int,int> pii;
const int MAXN=200000;
int n,m,a[MAXN],b[MAXN],c[MAXN],d[MAXN],k[MAXN],f[MAXN],f1[MAXN],ans[MAXN],ind;
set<pii>s;

bool cmp1(int i,int j)
{
    if(a[i]!=a[j])
        return a[i]<a[j];
    return b[i]<b[j];
}

bool cmp2(int i,int j)
{
    if(c[i]!=c[j])
        return c[i]<c[j];
    return d[i]<d[j];
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        f[i]=i;
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>c[i]>>d[i]>>k[i];
        f1[i]=i;
    }
    sort(f,f+n,cmp1);
    sort(f1,f1+m,cmp2);
    for(int i=0;i<n;i++)
    {
        int x=f[i];
        while(ind<m && c[f1[ind]]<=a[x])
        {
            s.insert(pii(d[f1[ind]],f1[ind]));
            ind++;
        }
        if(s.size()==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        set<pii>::iterator it=s.lower_bound(pii(b[x],0));
        if(it==s.end())
        {
            cout<<"NO"<<endl;
            return 0;
        }
        int y=it->second;
        k[y]--;
        ans[x]=y+1;
        if(k[y]==0)
            s.erase(pii(d[y],y));
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}