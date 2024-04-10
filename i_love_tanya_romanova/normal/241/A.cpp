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

//#define  INF 20000000000ll
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long m,k,d[10000],s[10000],cur,ans,a,mx,diff;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>m>>k;
for (int i=1;i<=m;i++)
cin>>d[i];
for (int i=1;i<=m;i++)
cin>>s[i];


for (int i=1;i<=m;i++)
{
    cur+=s[i];
    ans+=d[i];
    mx=max(mx,s[i]);
    diff=d[i]-cur;
    if (diff>0){a=diff/mx+(diff%mx>0);ans+=a*k;
    cur+=a*mx;}
    cur-=d[i];
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}