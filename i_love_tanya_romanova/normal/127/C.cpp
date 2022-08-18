/*
Rot beneath below
Killing the chance to die
The rising of the dead
The pain denies the soul

Even after the killing gently
Dissection of the light
The rotting of the soul
The pain realize the wounds, lives

You light the soul
Killing ones they save
The rotting of the soul
Dying of the pain

Killing the soul
Killing send you to your grave
Dying soon the one they save
Tearing rid you of your limbs

Infection soon sets in
Peeling rid you of your skin infection
Coming soon the end of life
Die, cure you of infliction
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
double tt,anstt;
long long ansp,answ,tod[2000000],x1,x2,t1,t2,t0,ps;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>t1>>t2>>x1>>x2>>t0;
if (t1==t2&&t1==t0)cout<<x1<<" "<<x2<<endl;
else
{
tod[0]=x2;
ps=0;
for (int i=1;i<=x1;i++)
{
 long    fl=0;while ((i*t1+ps*t2)<(i+ps)*t0)
    {++ps;fl=1;if (ps>x2)break;
    }
    //if (fl)
    //++ps;
    
    tod[i]=ps;
}

//cout<<tod[1]<<endl;

anstt=10000000;
for (int i=0;i<=x1;i++)
{if (tod[i]<=x2)
{tt=i*t1+tod[i]*t2;
 tt=tt*1.0/(i+tod[i]);
 anstt=min(anstt,tt);
}}
//cout<<tod[0]<<" "<<tod[1]<<endl;

anstt+=eps;
answ=-1;
for (int i=0;i<=x1;i++)
{if (tod[i]<=x2){
    tt=i*t1+tod[i]*t2;
     tt=tt*1.0/(i+tod[i]);
     if (tt<anstt)
     {if (answ<i+tod[i])
     {answ=i+tod[i];ansp=i;}
     }
}}

//cout<<tod[1]<<endl;
cout<<ansp<<" "<<tod[ansp]<<endl;
}
cin.get();cin.get();
return 0;}