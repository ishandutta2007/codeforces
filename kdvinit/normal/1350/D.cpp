#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long int k;
        cin>>n>>k;
        int a[n+1]={0},cntr=0,cntr2=0,pos[n+1]={0};
        for(int i=1;i<=n;i++)
        {
            long long int x;
            cin>>x;
            if(x==k) { a[i]=1; cntr++; }
            if(x>k) a[i]=2;
            if(x>=k) pos[++cntr2]=i;
        }
        if(cntr==0) { cout<<"NO"<<endl; continue; }
        if(n==1) { cout<<"YES"<<endl; continue; }
        int i;
        for(i=1;i<cntr2;i++)
        {
            if(pos[i+1]-pos[i]<=2) break;
        }
        if(i==cntr2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}