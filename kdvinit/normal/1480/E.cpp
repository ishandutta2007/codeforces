/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int ans[500][3],cnt=0;
int mxn=1e6;

void connect(int x,int y,int z)
{
    if(z>mxn) return;
    if(x>y) swap(x,y);
    cnt++;
    ans[cnt][0]=x;
    ans[cnt][1]=y;
    ans[cnt][2]=z;
}
void show(int i)
{
    cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
}


void solve()
{
    int l,r;
    cin>>l>>r;

    int x=l-1;
    l-=x;
    r-=x;

    int y=r-1, bin[23]={0};
    for(int i=1;i<23;i++)
    {
        bin[i]=y%2;
        y/=2;
    }

    for(int i=2;i<=23;i++)
    {
        connect(1,i,1);
        for(int j=2;j<i;j++)
        {
            int z=pow(2,j-2);
            connect(i,j,z);
        }
    }

    connect(1,24,1);
    int lst=1;
    for(int i=2;i<=23;i++)
    {
        if(bin[i-1]==0) continue;
        int z=pow(2,i-2);
        connect(i,24,lst);
        lst+=z;
    }

    int n=24;
    if(x!=0)
    {
        n++;
        connect(24,25,x);
    }

    cout<<"YES"<<endl;
    cout<<n<<" "<<cnt<<endl;
    for(int i=1;i<=cnt;i++) show(i);

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}