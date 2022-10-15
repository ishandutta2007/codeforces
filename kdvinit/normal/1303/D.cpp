/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long int whtpow2(long long int x)
{
    long long int ans=0;
    while(x!=1) { ans++; x/=2; }
    return ans;

}

long long int doit(long long int i,long long int freq[])
{
    long long int j=i;
    while(freq[i]==0) i++;
    freq[i]--;
    for(int k=j;k<=i-1;k++) freq[k]++;
    return i-j;
}

void solve()
{
    long long int n,m,freq[61]={0},arr[61]={0},sum=0;
    cin>>n>>m;
    for(long long int i=1;i<=m;i++)
    {
        long long int x;
        cin>>x;
        sum+=x;
        freq[whtpow2(x)]++;
    }

    if(sum<n) { cout<<-1<<endl; return; }

    long long int cnt=0;
    while(n!=0)
    {
        if(n%2==1) arr[cnt++]=1;
        else arr[cnt++]=0;
        n/=2;
    }

    long long int ans=0;

    for(long long int i=0;i<=60;i++)
    {
        if(arr[i]==0) freq[i+1]+=freq[i]/2;
        else if(arr[i]==1 && freq[i]>0) freq[i+1]+=(freq[i]-1)/2;
        else ans+=doit(i,freq);
    }

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}