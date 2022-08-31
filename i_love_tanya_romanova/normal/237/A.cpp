//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
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
#include <memory.h>

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long h[1000000],m[1000000],n,ans,q;

int main(){
//freopen("broadcast.in","r",stdin);
//freopen("broadcast.out","w",stdout);
//ios_base::sync_with_stdio(0);

h[0]=-2;

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>h[i]>>m[i];
    if (h[i]!=h[i-1]||m[i]!=m[i-1])
    {ans=max(ans,q);q=1;}
    else ++q;
}
ans=max(ans,q);
cout<<ans<<endl;
cin.get();cin.get();
return 0;}