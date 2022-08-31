/*
Life it seems will fade away
Drifting further every day
Getting lost within myself
Nothing matters, no one else

I have lost the will to live
Simply nothing more to give
There is nothing more for me
Need the end to set me free

Things not what they used to be
Missing one inside of me
Deathly lost, this can't be real
Cannot stand this hell I feel

Emptiness is filling me
To the point of agony
Growing darkness taking dawn
I was me but now he's gone

No one but me can save myself
But it's too late
Now I can't think
Think why I should even try

Yesterday seems as though
It never existed
Death greets me warm
Now I will just say goodbye
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

using namespace std;

long k,n1,n2,n3,t1,t2,t3,v1,v2,v3,start;
multiset<long> s1,s2,s3;
multiset<long>::iterator it;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;
for (int i=1;i<=n1;i++)
 s1.insert(0);
for (int i=1;i<=n2;i++)
 s2.insert(-t1);
for (int i=1;i<=n3;i++)
 s3.insert(-t1-t2);

for (int i=1;i<=k;i++)
{
 it=s1.begin();
 v1=(*it);
 it=s2.begin();
 v2=(*it);
 it=s3.begin();
 v3=(*it);
 start=max(v1,max(v2,v3));
 
 it=s1.begin();
 s1.erase(it);
 it=s2.begin();
 s2.erase(it);
 it=s3.begin();
 s3.erase(it);
 
 s1.insert(start+t1); // finishes & stp'n'go
 s2.insert(start+t1+t2-t1);// finishes in start+t1+t2, strt pre t1
 s3.insert(start+t1+t2+t3-t1-t2);// finishes in start+t1+t2+t3,strt pre t1+t2
}

cout<<start+t1+t2+t3<<endl;

cin.get();cin.get();
return 0;}