#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> pii;
long long n,r,k,a[200000],b[200000],sum,ans;
vector<pii>v;

int main()
{
    cin>>n>>r>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        sum+=a[i];
        a[i]=r-a[i];
        v.push_back(pii(b[i],i));
    }
    if(sum>=k*n)
    {
        cout<<0<<endl;
        return 0;
    }
    sum=k*n-sum;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        int ind=v[i].second;
        ans+=min(a[ind],sum)*b[ind];
        sum-=min(sum,a[ind]);
    }
    cout<<ans<<endl;
}