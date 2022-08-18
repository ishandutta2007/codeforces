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
#define bs 201004
//#define szz 400
//#define pb push_back
using namespace std;

long n,m,e,ans,h,q,w,usd[20000];
string tp;
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>h>>m>>n;
map <long,long> s;
for (int i=0;i<n;i++)
{
    cin>>tp;
    if (tp=="+")
    {
     cin>>w>>e;
//     if (usd[e]==1)ans++;
     q=e;
     while (usd[q]==1)
     {ans++;q=q+m;q%=h;}
     s[w]=q;
     usd[q]=1;
                }
    else
    {
        cin>>w;
        usd[s[w]]=0;
    }
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}