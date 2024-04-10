#include <bits/stdc++.h>

using namespace std;
long long prime[1000005];
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    prime[0]=1;
    prime[1]=1;
    long long i,j;
    for(i=2;i<=1000000;i++){
        if(prime[i]==0){
            for(j=i*2;j<=1000000;j+=i)prime[j]=1;
        }
    }
    long long n,r;
    long long x;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        r=sqrt(x);
        if((r+1)*(r+1)==x)r++;
        else if((r-1)*(r-1)==x)r--;
        else if(r*r!=x)cout<<"NO\n";
        else cout<<(prime[r]==1 ? "NO\n" : "YES\n");
    }
    return 0;
}