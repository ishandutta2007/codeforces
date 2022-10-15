#include<bits/stdc++.h>
using namespace std;
long long have[3030][3030];//how many js are there in the i,...,nth element?
long long sum[3030][3030];//answer for proper pair(i,j)
int a[3030];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(have,0,sizeof(have));
        memset(sum,0,sizeof(sum));
        memset(a,0,sizeof(a));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            a[i]--;
        for(int i=n-1;i>=0;i--)
            for(int j=0;j<n;j++)
            {
            	have[i][j]=have[i+1][j]+(a[i]==j);
            	//cout<<i<<" "<<j<<" "<<have[i][j]<<endl;
			}
        for(int i=0;i<n;i++)
            for(int j=i-2;j>=0;j--)
            	sum[j][i]=sum[j+1][i]+have[i+1][a[j+1]];
        long long ans=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(a[i]==a[j])
                    ans+=sum[i][j];
        cout<<ans<<endl;
    }
    return 0;
}