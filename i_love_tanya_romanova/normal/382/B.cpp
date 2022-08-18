/*
I dress myself in black
In black from head to heels
I take my promise back
Cause you don't know how it feels

No, you don't take me as I am
No, you don't want to know at all
Who is the face behind the mask
I'll be the one who'll make you fall

Beware! Beware! I'll be the one
The one to take you under
Beware!

I hate the light of day
I'm happy when it rains
The stars shine on my way
But the memory remains

No, you don't take me as I am...

Beware! Beware! I'll be the one...

I am the night's revenge
I've got a soul to sell
And yet a fist to clench
So wait for me in hell

Beware! Beware! I'll be the one...

Wait for me in hell
I'll see you in hell
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

long long a,b,w,x,c,iters,q,rem,t1,t2;
long long del,l,r,mid,fc;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a>>b>>w>>x>>c;

q=b;
while (true)
{
 ++iters;
 if (q<x){++del;q=w-(x-q);}
 else q-=x;
 if (q==b)break;
}
 
 //cout<<del<<" "<<iters<<endl;
 
l=0;
r=1e15;
while (l<r)
{
 mid=l+r;
 mid/=2;
 t1=c-mid;// iE
 fc=mid/iters;
 rem=mid%iters;
 t2=a-del*fc;
 q=b;
 for (int i=1;i<=rem;i++)
 {
  if (q<x){--t2;q=w-(x-q);}
  else q-=x;
 }
 if (t2>=t1)r=mid;
 else l=mid+1;
} 
cout<<l<<endl;

cin.get();cin.get();
return 0;}