/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int h, m;


bool check(int x, int y)
{
    int h1 = x/10;
    int h2 = x%10;

    int m1 = y/10;
    int m2 = y%10;

    int rev[10]={0,1,5,-1,-1,2,-1,-1,8,-1};

    int ch1 = rev[m2];
    int ch2 = rev[m1];

    int cm1 = rev[h2];
    int cm2 = rev[h1];

    if(ch1==-1 || ch2==-1 || cm1==-1 || cm2==-1) return false;

    int hh1 = ch1*10 + ch2;
    int mm2 = cm1*10 + cm2;

    if(hh1>=h || mm2>=m) return false;
    return true;
}

void solve()
{
    cin>>h>>m;

    char a[6];
    for(int i=1;i<=5;i++) cin>>a[i];

    int x = (a[1]-'0')*10 + (a[2]-'0');
    int y = (a[4]-'0')*10 + (a[5]-'0');

    while(1)
    {
        if(check(x, y))
        {
            cout<<x/10;
            cout<<x%10;
            cout<<":";
            cout<<y/10;
            cout<<y%10;
            cout<<endl;
            return;
        }
        y++;
        if(y==m) { y=0; x++; }
        x%=h;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}