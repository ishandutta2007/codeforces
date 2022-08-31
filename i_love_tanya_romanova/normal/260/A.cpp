/*
The wind 
The war 
I'm burning out 
Is this the end 
The bombs are raining hell 
I see 
the real me 
Floating out to space 
Blown to bits 
Where's the human race 

Slave 
Well it's immortal right 
But I'll give it a try 
As they fly through the air 
Doubters beware 

My home 
Below 
A blissful place 
Stuck in this silo 
I live alone 
Make the best of what i own 

Trusty 
Gold key 
Ready to kindle the globe 
Please lay these arms to rest 
My will is running low 

Slave 
Well it's immortal right 
But I gave it a try 
While the faces stare 
At the hideous glare 

Better turn and run 
I've unleashed the sun 
You say you wanted it done 
I'm the man to count on 

I'm in the hole for life 
These subtle words fit right 
Lord knows man needs a vice 
On my knees in pain
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
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long n,b,r;

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
cin>>b>>n;
for (int i=0;i<st.size();i++)
{
    r=r*10+st[i]-48;
    r%=b;
}
r*=10;
r%=b;
if (r==0)r=b;
if (b-r<10){cout<<st;cout<<b-r;
for (int i=2;i<=n;i++)
cout<<0;}
else cout<<-1;
cout<<endl;

cin.get();cin.get();
return 0;}