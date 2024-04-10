//#pragma comment(linker, "/STACK:16777216")
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
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

string st[1000];long n,fl,ts,ans,sss,k,q,ss,s[200][200];
int main(){
//freopen("input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>n>>k;
for (int i=0;i<n;i++)
cin>>st[i];

for (int i=0;i<n;i++)
for (int j=0;j<n;j++)
if (j!=i){q=0;while (q<st[i].size()&&q<st[j].size()&&st[i][q]==st[j][q])
{s[i][j]++;sss++;q++;}

}
sss/=2;
/*for (int i=0;i<n;i++)
{
    for (int j=0;j<n;j++)
    cout<<s[i][j]<<" ";
    cout<<endl;
}*/

//cout<<sss<<endl;

//if (k>n/2){fl=1;k=n-k;}

for (int i=0;i<(1<<n);i++)
{
    q=0;ss=i;
    while (ss){q+=ss%2;ss/=2;}
    if (q==k)
    {
             ts=0;
             
             for (int q=0;q<n;q++)
             for (int j=0;j<n;j++)
             if ((q!=j)&&(i&(1<<q))&&(i&(1<<j)))
             ts+=s[q][j];
             ts/=2;
            // cout<<i<<" "<<ts<<endl;
             ans=max(ans,ts);
             
             
             
             }
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}