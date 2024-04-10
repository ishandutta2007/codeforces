/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, d12, d23, d31;
    cin>>n>>d12>>d23>>d31;

    int dif = abs(d23-d31);
    int mn=min(d23, d31);

    //Cas1:
    if(dif==d12)
    {
        int l=mn+dif;
        if(l>=n) { cout<<"NO"<<endl; return; }

        int pp1=1;
        int pp2=dif+1;
        int pp3=pp2+mn;

        int po1=1;
        int po2=2;
        int po3=3;

        if(d23>d31) swap(po1, po2);

        int p[n+1]={0};
        p[pp1]=po1;
        p[pp2]=po2;
        p[pp3]=po3;

        int cur=3;
        for(int i=1; i<=n; i++)
        {
            if(p[i]!=0) continue;
            p[i]=(++cur);
        }

        cout<<"YES"<<endl;
        for(int i=1; i<n; i++)
        {
            cout<<p[i]<<" "<<p[i+1]<<endl;
        }

        return;
    }

    if(dif>d12) { cout<<"NO"<<endl; return; }
    
    if(d12>(d23+d31)) { cout<<"NO"<<endl; return; }

    int dif2=d12-dif;
    if(dif2%2==1) { cout<<"NO"<<endl; return; }

    int y = dif2/2;
    int x = d12-y;

    int l = 1 + y + x + (mn-y);

    if(l>n) { cout<<"NO"<<endl; return; }

    cout<<"YES"<<endl;

/*
1
4 2 1 1
*/

    int pp1=1+y;
    int pp2=pp1+x;
    int pp3=pp2+(mn-y);

    if(y==0) pp1=1;
    if(x==0) pp2=1;
    if((mn-y)==0) pp3=1;

    int po1=1;
    int po2=2;
    int po3=3;

    if(d23<d31) swap(po1, po2);

    int p[n+1]={0};
    p[pp1]=po1;
    p[pp2]=po2;
    p[pp3]=po3;

    int cur=3;
    for(int i=1; i<=n; i++)
    {
        if(p[i]!=0) continue;
        p[i]=(++cur);
    }

    int lst=p[1];
    for(int i=2; i<=pp1; i++)
    {
        cout<<lst<<" "<<p[i]<<endl;
        lst=p[i];
    }

    lst=p[1];
    for(int i=pp1+1; i<=pp2; i++)
    {
        cout<<lst<<" "<<p[i]<<endl;
        lst=p[i];
    }

    lst=p[1];
    for(int i=pp2+1; i<=n; i++)
    {
        cout<<lst<<" "<<p[i]<<endl;
        lst=p[i];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}