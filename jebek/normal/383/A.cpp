#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<map>
#include<string>
#include<cstring>

using namespace std;

long long ans,t,n,a;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a==1)
          t++;
        else
            ans+=t;
      //  cout<<ans<<endl;
    }
    cout<<ans<<endl;
}