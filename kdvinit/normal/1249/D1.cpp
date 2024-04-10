#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k,freq[201]={0};
	cin>>n>>k;
	int l[n+1],r[n+1],cnt=0,ans[n];
	for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
        for(int j=l[i];j<=r[i];j++) freq[j]++;
    }

    for(int i=1;i<=200;i++)
    {
        if(freq[i]<=k) continue;
        cnt++;
        int mx=0,ansj;
        for(int j=1;j<=n;j++)
        {
            if(l[j]<=i && i<=r[j] && r[j]>mx)
            {
                ansj=j;
                mx=r[j];
            }
        }
        ans[cnt]=ansj;
        for(int j=i;j<=mx;j++) freq[j]--;
        l[ansj]=0;
        r[ansj]=0;
        i--;
    }

    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}