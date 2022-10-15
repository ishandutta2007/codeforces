/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int seq[12]={0,0,0,1,2,3,2,3,1,3,1,2};

int val(int n)
{
    if(n<4) return n;
    n-=4;
    n%=12;
    return seq[n];
}

void solve()
{
    int n;
    cin>>n;

    if(n<4) { cout<<n<<endl; return; }

    n-=3;
    int cnt=3;
    int m=(n-1)%12;
    int ans=seq[m];
    while(1)
    {
        cnt*=4;
        if(n<=cnt)
        {
            int tmp=((n-1)%3+1);
            tmp*=(cnt/3);
            ans+=tmp;
            break;
        }

        n-=cnt;
        int m=( (n-1)%(cnt*4) + 1 );
        int x =(m-1)/(cnt);
        x*=3;
        int y = (m-1)%3+1;
        int tmp=seq[x+y-1];
        tmp*=(cnt/3);
        ans+=tmp;

    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}