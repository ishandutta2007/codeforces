/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int Power(int $a,int $b)
{
    int $result=1;
    while($b) {   if($b%2==1)  $result*=$a;     $a*=$a;    $b/=2; }
    return $result;
}


void solve()
{
    int n,k;
    cin>>n>>k;

    int freq[50]={0},grt=0;
    char x;
    char a[n];

    for(int i=1;i<=n-2;i++)
    {
        cin>>a[i];
    }

    int ap,an;
    cin>>x; an=x-97;
    cin>>x; ap=x-97;

    ap=Power(2,ap);
    an=Power(2,an);
    k+=an;
    k-=ap;

    if(k<0) k*=(-1);
    //cout<<k<<endl;

    int ans[50]={0};
    int temp=k,cnt=0;
    while(temp!=0)
    {
        ans[cnt++]=temp%2;
        temp/=2;
    }

    for(int i=1;i<=n-2;i++)
    {
        int y = a[i]-97;
        grt=max(grt,y);
        freq[y]++;
    }

    /*
    for(int i=0;i<49;i++) cout<<freq[i]<<" ";
    cout<<endl;
    for(int i=0;i<49;i++) cout<<ans[i]<<" ";
    cout<<endl;
    */

    int par[50]={0};
    for(int i=0;i<49;i++)
    {
        int y=freq[i];
        int p=par[i];
        if(ans[i]==0)
        {
            if(y%2==1)
            {
                if(par[i]==0) { cout<<"No"<<endl; return; }
                else y--;
            }
        }
        else
        {
            if(y%2==0)
            {
                if(par[i]==0) { cout<<"No"<<endl; return; }
                else y--;
            }
        }
        int z=y/2;
        freq[i+1]+=z;
        if( (z>0) || (ans[i]==1 && i<grt) ) par[i+1]=1;
    }

    cout<<"Yes"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}