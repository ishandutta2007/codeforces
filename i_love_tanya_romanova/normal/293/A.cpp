/*
Honey it's getting close to midnight
And all the myths are still in town
True love and lipstick on your linen
Bite the pillow make no sound
If there's some living to be done
Before your life becomes your tomb
You'd better know that I'm the one
So unchain your back door invite me around

[Chorus]
Bring your daughter, bring your daughter to the slaughter
Let her go, let her go, let her go

Honey it's getting close to daybreak
The sun is creeping in the sky
No patent remedies for heartache
Just empty words and humble pie
So get down on your knees honey
Assume an attitude
You just pray that I'll be waiting
Cos you know I'm coming soon

So pick up your foolish pride, no going back
No where, no way, no place to hide

[Chorus]
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