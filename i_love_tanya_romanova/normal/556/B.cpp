/*
How many years have gone for making our whole world?
Something must be stronger than the stone
Everythings been perfect timetil now

How many lives weve
Cryin my head, theres a reason for my wife
All your choices are mine
In your mind they die

Tell me why youve done this my life
You dont know Im sunk away
I pray to Lord, the absolute power
And I know from Him, and you know from me
The answer

Cant you feel free?
Why have to believe
You will forget her
Its easier to breathe
Follow your dreams and youll be free

Are you ready for more?
I am sure about my magic dreams
I know from Him
You know from me
The absolute power how it feels

I will play alone
I will show my magic dreams
And we have our dreams
And we wait from you the absolute power

We make you feel dreaming
We help you to believe
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
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n,ar[1<<20],er;
int dif;

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
    cin>>ar[i];
}

int found=0;
dif=ar[0];
er=0;

for (int i=1;i<n;i++)
{
    int tval=ar[i];
    if (i%2)
        tval+=dif;
        else
        tval-=dif;
    tval=(tval+n*2)%n;
    if (tval!=i)
        er=1;
}
if (er==0)  found=1;
er=0;
dif=(n-ar[0]);

for (int i=1;i<n;i++)
{
    int tval=ar[i];
    if (i%2==0)
        tval+=dif;
        else
        tval-=dif;
    tval=(tval+n*2)%n;
    if (tval!=i)
        er=1;
}
if (er==0)
    found=1;

if (found)
    cout<<"Yes"<<endl;
else 
    cout<<"No"<<endl;
    
//cin.get();cin.get();
return 0;}