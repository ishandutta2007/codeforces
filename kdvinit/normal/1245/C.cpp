#include <iostream>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string a;
    cin>>a;
    int n=a.size();
    int cntrn=0,freqn[n]={0},cntru=0,frequ[n]={0};
    for(int i=0;i<n;i++)
    {
        if(a[i]=='m' or a[i]=='w') { cout<<0; return 0; }
        if(a[i]=='n')
        {
            cntrn++;
            freqn[cntrn]++;
            i++;
            while(i<n && a[i]=='n')
            {
                freqn[cntrn]++;
                i++;
            }
            i--;
        }
        if(a[i]=='u')
        {
            cntru++;
            frequ[cntru]++;
            i++;
            while(i<n && a[i]=='u')
            {
                frequ[cntru]++;
                i++;
            }
            i--;
        }
    }
    long long int fib[n+1],vin=1000000007;
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<n+1;i++) fib[i]=(fib[i-1]+fib[i-2])%vin;
    long long int ans=1;
    for(int i=1;i<=cntrn;i++)
    {
        int z=freqn[i];
        ans=(ans*fib[z])%vin;
    }
    for(int i=1;i<=cntru;i++)
    {
        int z=frequ[i];
        ans=(ans*fib[z])%vin;
    }
    cout<<ans<<endl;
    return 0;
}