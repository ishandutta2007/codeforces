#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int fr[109],id[109];
int main()
{
ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    cin>>n;
    for(int i=1;i<103;i++){fr[i]=id[i]=0;}
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        fr[x]++;
        id[x]=i;
    }
    int ans;
    for(int i=1;i<=100;i++)
    if(fr[i]==1){ans=id[i];break;}
    cout<<ans<<endl;

}
    return 0;
}