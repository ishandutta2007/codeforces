#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-9
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
long n,q,ar[200000],ans,ans1;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=1;i<=n;i++)
{cin>>q;ar[q]++;
}
for (int i=1;i<=1000;i++)
{
    if (ar[i]>0){ans1++;}
    if (ar[i]>ans)ans=ar[i];
}
cout<<ans<<" "<<ans1<<endl;
cin.get();cin.get();
return 0;
}