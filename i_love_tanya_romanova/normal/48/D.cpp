/*
Takers of humanity, elders paranoid
The time is now
Give up this world you once destroyed
Society versus the underground
Their battles fought and lost
The time has come
To rule the world at any cost

For the past it's too late
Cause the world can't control fate
Shadows cast loud and clear
Tell the world the new order's here

Cities turn to battlefields
A deadly spell is cast
Corpses falling one by one
Until the last
The preacher speaks of prophecy
So many years before
No one escapes their punishment
The gods of war

For the past it's too late
Cause the world can't control fate
Shadows cast loud and clear
Tell the world the new order's here

Death is like an empty space
Fell no thoughts of fear
The future cries
As mother nature sheds a tear
The world becomes a prisoner
A victim of its crime
The human race is now a race
Against time

For the past it's too late
Cause the world can't control fate
Shadows cast loud and clear
Tell the world the new order's here
*/

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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long q,fl;
vector<long long> v[300000];
long long ans[300000];
long long n;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;
    v[q].push_back(i);
}
fl=0;
for (int i=2;i<=100000;i++)
if (v[i].size()>v[i-1].size())fl=1;
if (fl)cout<<-1<<endl;
else
{
    cout<<v[1].size()<<endl;
    for (int i=1;i<=100000;i++)
    for (int j=0;j<v[i].size();j++)
    ans[v[i][j]]=j+1;
for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    cout<<ans[i];
}
cout<<endl;
}

cin.get();cin.get();
return 0;}