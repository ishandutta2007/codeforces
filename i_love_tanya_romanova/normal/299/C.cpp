/*
Sound is ripping through your ears
The deafening sound of metal nears
Your bodies waiting for his whips
The taste of leather on your lips

Hear the cry of War
Louder than before
With his sword in hand
to control the land
Crushing metal strikes
on this frightening night
Fall onto your knees
For the Phantom Lord

Victims falling under chains
You hear them crying dying pains
The fists of terrors breaking through
Now there's nothing you can do

Hear the cry of War
Louder than before
With his sword in hand
to control the land
Crushing metal strikes
on this frightening night
Fall onto your knees
For the Phantom Lord

The leather armies have prevailed
The Phantom Lord has never failed
Smoke is lifting from the ground
The rising volume metal sound

Hear the cry of War
Louder than before
With his sword in hand
to control the land
Crushing metal strikes
on this frightening night
Fall onto your knees
For the Phantom Lord

Fall to your knees
and bow to the Phantom Lord
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;

string st1,st2;
long n,n1,n2,calc[10][10];

int main(){
//freopen("sumdist.in","r",stdin);
//freopen("sumdist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cin>>st1;
cin>>st2;

for (int i=0;i<n*2;i++)
{
     calc[st1[i]-48][st2[i]-48]++;
}

n1=n2=0;
for (int move=1;move<=n;++move)
{
 if (calc[1][1]>0){n1++;calc[1][1]--;}
 else if (calc[1][0]>0){n1++;calc[1][0]--;}
 else if (calc[0][1]>0){calc[0][1]--;}
 else calc[0][0]--;
 
 if (calc[1][1]>0){n2++;calc[1][1]--;}
 else if (calc[0][1]>0){n2++;calc[0][1]--;}
 else if (calc[1][0]>0){calc[1][0]--;}
 else calc[0][0]--;   
}
if (n1>n2)cout<<"First"<<endl;
else if (n1==n2)cout<<"Draw"<<endl;
else cout<<"Second"<<endl;
cin.get();cin.get();
return 0;}