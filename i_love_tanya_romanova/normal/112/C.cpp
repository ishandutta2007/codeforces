/*
Out of the silent planet, out of the silent planet we are
Out of the silent planet, out of the silent planet we are
Out of the silent planet, out of the silent planet we are
Out of the silent planet, out of the silent planet we are

Withered hands, withered bodies begging for salvation
Deserted by the hand of gods of their own creation
Nations cry underneath decaying skies above
You are guilty, the punishment is death for all who live
The punishment is death for all who live

Out of the silent planet, dreams of desolation
Out of the silent planet, Come the demons of creation
Out of the silent planet, dreams of desolation
Out of the silent planet, Come the demons of creation

The killing fields, the grinding wheels crushed by equilibrium
Separate lives no more disguise, no more second chances
Haggard wisdom spitting out the bitter taste of hate
I accuse you before you know the crime it's all too late
Before you know the crime it's all too late

Out of the silent planet, dreams of desolation
Out of the silent planet, Come the demons of creation
Out of the silent planet, dreams of desolation
Out of the silent planet, Come the demons of creation

Out of the silent planet, out of the silent planet we are
Out of the silent planet, out of the silent planet we are

Out of the silent planet, dreams of desolation
Out of the silent planet, Come the demons of creation
Out of the silent planet, dreams of desolation
Out of the silent planet, Come the demons of creation

Out of the silent planet, out of the silent planet we are
Out of the silent planet, out of the silent planet we are
Out of the silent planet, out of the silent planet we are
Out of the silent planet, out of the silent planet we are
Out of the silent planet, out of the silent planet we are
Out of the silent planet, out of the silent planet we are
*/

#include <iostream>
//#include <fstream>
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
//#define M_PI 3.141592653589793
#define mx 1000000000000ll
//#define bs 1000000007
#define szz 400
using namespace std;
long long s,n,x,y,ar[200000];
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>x>>y;
if (y<n)cout<<-1<<endl;
else
{
    ar[1]=y-n+1;
    for (int i=2;i<=n;i++)ar[i]=1;
    s=0;
    for (int i=1;i<=n;i++)s+=ar[i]*ar[i];
    if (s<x)cout<<-1<<endl;
    else for (int i=1;i<=n;i++)cout<<ar[i]<<" ";
}
cin.get();cin.get();
return 0;}