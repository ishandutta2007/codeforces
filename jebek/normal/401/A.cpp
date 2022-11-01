#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>

using namespace std;

long long n,x,a,k,sum;

int main()
{
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        sum+=a;
    }
    if(sum<0)
        sum=-sum;
    if((sum%x)!=0)
        k=1;
    cout<<sum/x+k<<endl;
}