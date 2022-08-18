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


#define  INF 100000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long n,x0,fl,a[100000],b[100000],ans;

int main(){
//freopen("arithm.in","r",stdin);
//freopen("arithm.out","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>x0;
ans=-1000000;

for (int i=1;i<=n;i++)
{
    cin>>a[i]>>b[i];
    if (a[i]>b[i])swap(a[i],b[i]);
}

for (int i=0;i<=1000;i++)
{
    fl=0;
    for (int j=1;j<=n;j++)
    if (i<a[j]||i>b[j])
    fl=1;
    if (fl==0&&abs(i-x0)<abs(ans-x0))ans=i;
}
if (ans==-1000000)cout<<-1<<endl;
else cout<<abs(x0-ans)<<endl;
cin.get();cin.get();

return 0;}