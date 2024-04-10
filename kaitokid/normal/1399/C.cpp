#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int w[109];
int main()
{
ios::sync_with_stdio(0);
int n,t;
cin>>t;
while(t--)
{
    cin>>n;
    int x;
    for(int i=0;i<101;i++)w[i]=0;
    for(int i=0;i<n;i++){cin>>x;w[x]++;}
    int ans=0;
    for(int i=1;i<=100;i++)
    {int res=0;
        for(int j=0;j<(i+1)/2;j++)res+=min(w[j],w[i-j]);
        if(i%2==0)res+=w[i/2]/2;
        ans=max(ans,res);
    }
    cout<<ans<<endl;

}
    return 0;
}