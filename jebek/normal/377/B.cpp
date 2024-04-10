#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
#define X first
#define Y second
#define MP make_pair

using namespace std;

#define ll long long
typedef pair<ll,ll> pii;
ll n,m,p,t,k,sum,ans[200000];
pii a[200000];
set<pair<ll,pii> >s;
pair<int,pii> P1,P[200000];

bool check(ll k)
{
    s.clear();
    t=0;
    p=n-1;
    for(int i=m-1;i>-1 && t<=sum;i--)
    {
        while(p>-1 && P[p].X>=a[i].X){
            s.insert(MP(P[p].Y.X,pii(P[p].Y.Y,k)));
            p--;
        }
        if(s.size()==0)
            return false;
        P1=*s.begin();
        s.erase(s.begin());
        t+=P1.X;
        ans[a[i].Y]=P1.Y.X;
    //    cout<<i<<" "<<a[i].X<<" "<<a[i].Y<<"     "<<p<<" "<<P[p].X<<" "<<P[p].Y.X<<" "<<P[p].Y.Y<<endl;
        if(P1.Y.Y>1)
        {
            P1.Y.Y--;
            P1.X=0;
            s.insert(P1);
        }
    }
    if(t<=sum)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>sum;
    for(int i=0;i<m;i++)
    {
        cin>>a[i].X;
        a[i].Y=i;
    }
    for(int i=0;i<n;i++)
        cin>>P[i].X;
    for(int i=0;i<n;i++)
    {
        cin>>P[i].Y.X;
        P[i].Y.Y=i;
    }
    sort(P,P+n);
    sort(a,a+m);
    int l=0,r=m+1;
    while(l<r)
    {
      //  cout<<l<<" "<<r<<endl;
        int mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    if(l>m)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    check(l);
    for(int i=0;i<m;i++)
        cout<<ans[i]+1<<" ";
    cout<<endl;
}