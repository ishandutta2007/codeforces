#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;
int n,m,ar[123456],x,y,p,z,ans;

int main() {

    cin>>n;
for(int i=1;i<=n;i++)
cin>>ar[i];

ans=-1;
for (int i=2;i<n;i++)
{
 if (ar[i]>ar[1]&&ar[i]>ar[i+1])ans=i;
 if (ar[i]<ar[1]&&ar[i]<ar[i+1])ans=i;
 if (ar[i]>ar[1]&&ar[i]>ar[i+1])ans=i;
 if (ar[i]<ar[1]&&ar[i]<ar[i+1])ans=i;
}

if (ans==-1)cout<<ans+1<<endl;
else
{
    cout<<3<<endl;
    cout<<1<<" "<<ans<<" "<<ans+1<<endl;    
}
return 0;
}