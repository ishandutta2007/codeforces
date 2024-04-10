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
long n,ar[20000],ans,ans1,ans2;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;
for (int i=0;i<n;i++)
{cin>>ar[i];
}
ar[n]=ar[0];
ans=100000;
for (int i=0;i<n;i++)
{if (abs(ar[i]-ar[i+1])<ans)
{ans=abs(ar[i]-ar[i+1]);ans1=i;ans2=i+1;if (ans2==n)ans2=0;}}
cout<<ans1+1<<" "<<ans2+1<<endl;
cin.get();cin.get();
return 0;
}