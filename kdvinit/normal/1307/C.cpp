/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long int val(char x,char y,string a,long long int n)
{
    long long int cnt=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==y) ans+=cnt;
        if(a[i]==x) cnt++;
    }
    return ans;
}

void solve()
{
    string a;
    cin>>a;

    long long int n=a.size(),freq[27]={0},ans=0;
    for(int i=0;i<n;i++)
    {
        int x=a[i]-96;
        freq[x]++;
    }
    for(int i=1;i<=26;i++) ans=max(ans,freq[i]);

    for(char x='a';x<='z';x++)
    {
        for(char y='a';y<='z';y++) ans=max(ans,val(x,y,a,n));
    }

    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; t=1;
	while(t--) solve();
	return 0;
}