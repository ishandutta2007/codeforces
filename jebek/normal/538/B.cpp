#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long p[20];
vector<int>v;
int MAX,n;

int main()
{
    cin>>n;
    p[0]=1;
    for(int i=1;i<10;i++)
        p[i]=p[i-1]*10;
    for(int i=0;i<7;i++)
    {
        v.push_back(n%10);
        MAX=max(MAX,n%10);
        n/=10;
    }
    cout<<MAX<<endl;
    for(int i=0;i<MAX;i++)
    {
        long long ans=0;
        for(int j=0;j<7;j++)
            if(v[j])
            {
                ans+=p[j];
                v[j]--;
            }
        cout<<ans<<" ";
    }
    cout<<endl;
}