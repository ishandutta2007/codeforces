/*
K.D. Vinit  |,,|
Last Submission
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define mxl 1000000

int opf[mxl+1];
int is_it_prime[mxl+1];

int Make_opf()
{
    for(int i=1;i<=mxl;i++) { is_it_prime[i]=1; opf[i]=i; }

    for(int i=2;i*i<=mxl;i++)
    {
        if(is_it_prime[i]==0) continue;
        int k=i*i;
        for(int j=k;j<1000001;j+=i)
        {
            is_it_prime[j]=0;
            while(opf[j]%k==0) opf[j]/=k;
        }
    }

    return 0;
}
int impliment=Make_opf();

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) { cin>>a[i]; a[i]=opf[a[i]]; }

    unordered_map<int,int> freq;
    for(int i=1;i<=n;i++) freq[a[i]]++;

    int v0=0,v1=0;
    for(auto i: freq)
    {
        int x=i.second;
        v0=max(v0,x);
        if(x%2==0 || i.first==1) v1+=x;
    }
    v1=max(v0,v1);

    int q; cin>>q;
    
    while(q--)
    {
        int w; cin>>w;
        
        if(w==0) cout<<v0<<endl;
        else cout<<v1<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}