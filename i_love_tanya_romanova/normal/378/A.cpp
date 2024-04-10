/*
Which one of them, the fallen and the frozen
Unmasks the difference, waving through the skies
Shining like the sun - or falling like the frozen one
Or in the end just waving goodbye

Out of mind

Out of mind
Out of control
The monster in my head
Fool in the back
Out of mind
Out of control
No more lies
No more tears
No more fight
No more pain

Which one of them, the frozen and the fallen
A black hole like the abyss of madness
Shining on the fallen ones, waving through the night
If time is the crime of long dead centuries

Out of mind

Out of mind
Out of control
The monster in my head
Fool in the back
Out of mind
Out of control
No more lies
No more tears
No more fight
No more pain

No more tears
No more fight
No more pain
No more fear

Out of mind

Out of mind
Out of control
The monster in my head
Fool in the back
Out of mind
Out of control
No more lies
No more tears
No more fight
No more pain
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long a,b,da,db,ans1,ans2,ans3;

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a>>b;
for (int i=1;i<=6;i++)
{
    da=abs(i-a);db=abs(i-b);
    if (da<db)ans1++;
    else if (da==db)ans2++;else ans3++;
}
cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;

cin.get();cin.get();
return 0;}