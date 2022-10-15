/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

int tot;
int n;

bool check(int x)       //true if number is <x;
{
    int ext = n - (tot)%n;
    int mn = (tot+ext)/n;

    int ad = (n-x);
    int qq = ext+ad;

    if(qq>n) { qq-=n; mn--; }

    cout<<"+ "<<qq<<endl;
    tot+=qq;

    int res; cin>>res;
    return (res==mn);
}

void solve()
{
    cin>>n;
    tot=0;

    int l=1, r=n;
    while(l+1!=r)
    {
        int mid = (l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }

    cout<<"! " <<l+tot<<endl;
}

int32_t main()
{
    solve();
    return 0;
}