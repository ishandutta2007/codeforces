

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
long n,s,ans,ans1,ar[200000];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>ar[i];
    sort(ar,ar+n);

    s=10;ans=0;
    for (int i=0;i<n;i++)
    {if (ar[i]<=720-s){s+=ar[i];ans++;if (s>360)ans1+=s-360;}}
    cout<<ans<<" "<<ans1<<endl;
    return 0;
}