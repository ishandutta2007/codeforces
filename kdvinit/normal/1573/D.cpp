/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5+10;
int a[N];
vector<int> mov;

void query(int i)
{
    mov.push_back(i);
    int xr = (a[i]^a[i+1]^a[i+2]);
    a[i]=xr; a[i+1]=xr; a[i+2]=xr;
}

void print()
{
    cout<<"YES"<<endl;
    cout<<mov.size()<<endl;
    for(int x: mov) cout<<x<<" ";
    cout<<endl;
}

void even(int l, int r)
{
    if(l>r) return;
    if(a[l-1]==0)
    {
        int pos=l-1;
        while(1)
        {
            if(pos+2>r) break;
            query(pos);
            pos+=2;
        }

    }
    else
    {
        int pos=r+1;
        while(1)
        {
            if(pos-2<l) break;
            query(pos-2);
            pos-=2;
        }
    }
}

void solve()
{
    mov.clear();
    int n;
    cin>>n;

    int xr=0, cnt=0;
    for(int i=1; i<=n; i++) { cin>>a[i]; xr^=a[i]; cnt+=a[i]; }

    if(xr==1) { cout<<"NO"<<endl; return; }
    if(cnt==n) { cout<<"NO"<<endl; return; }

    a[0]=1; a[n+1]=1;
    int prv=-1;

    for(int i=1; i<=n; i++)
    {
        if(a[i]==0) { prv=-1; continue; }

        int j=i;
        while(j<=n && a[j]==1) j++;

        int l, r;
        if(prv!=-1) l=prv;
        else l=i;

        r=j-1;

        if(l==1 && r==n) { cout<<"NO"<<endl; return; }
        int len = r-l+1;

        if(len%2==0)
        {
            even(l, r);
            i=r;
            prv=-1;
            continue;
        }

        while(a[r+1]==0 && a[r+2]==0)
        {
            query(r);
            r+=2;
        }

        if(a[r+1]==1)
        {
            prv=l;
            i=r;
            continue;
        }
        else
        {
            query(r);
            even(l, r-1);
            i=r;
            continue;
        }
    }

    print();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}