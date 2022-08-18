/*
When summer's gone flee my angel
Winter winds they might lead you far away
Beyond the pale horizon, a greavin' silence
Over dreams to my heart yet not remain

Oh, please believe
It's in her eyes
It's inside
It's in my heart, the same relation
From which I once led astray

Oh, please believe
It's in her eyes
It's inside
It's in my heart
The same delightful place
I once felt in you

Angellore revered at dusk
For thee I rose, now descend all alone
Rise for me, soothe my heart
So wide a sea, may I overcome

Into the night strays an angel
So lost and tearful all astray

Into the night strays an angel
So lost and tearful all astray
Lo where's the pale horizon
Oh, where is dyingness
You reach for me beyond so wide a sea

Oh, please believe
It's in her eyes
It's inside
It's in my heart, the same desire
I feel burning in me

Oh, please believe
It's in her eyes
It's inside
It's in my heart, the same desire
From the empty pain within

Rise for me, soothe my heart
So wide a sea, may I overcome

Deep as the sea
Wailing secrecies are burning in me
For a dream I once desired
I bequeath my sorrow and I regret to thee
Cannot cross that wide a sea

Angellore revered at dusk
For thee I rose, now descend all alone
Rise for me, soothe my heart
So wide a sea, may I overcome
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
#include <ctime>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long ar[100];

int main(){
//freopen("army.in","r",stdin);
//freopen("army.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=0;i<6;i++)
cin>>ar[i];
sort(ar,ar+6);
if (ar[0]==ar[3])
{
                 if (ar[4]!=ar[5])
                 cout<<"Bear"<<endl;
                 else cout<<"Elephant"<<endl;
}
else  if (ar[2]==ar[5])
{
      if (ar[0]!=ar[1])
      cout<<"Bear"<<endl;
      else cout<<"Elephant"<<endl;
}
else if(ar[1]==ar[4])cout<<"Bear"<<endl;
else cout<<"Alien"<<endl;

cin.get();cin.get();
return 0;}