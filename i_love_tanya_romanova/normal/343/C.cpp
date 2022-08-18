/*
Devin
Won't go to heaven
She's just another lost soul,
About to be mine again
Leave her
we will receive her
It is beyond your control
will you ever meet again

Devin
One of eleven
Who had been rendered unwhole
As a little child,
she was taken
and then forsaken
you will remember it all
Let it fill your mind again

[Chorus:]
Devin lies beyond this portal
take the word of one immortal
Give your soul to me
For eternity
release your life
to begin another time with her
End your grief with me
there's another way
release your life
take your place inside the fire with her

Sever
Now and forever
you're just another lost soul about to be mine again
see her, you'll never free her
you must surrender it all
If you'd like to meet again

Fire
For your desire
As she begins to turn cold for the final time
you will shiver
till you deliver
you will remember it all
Let it fill your mind again

Take it away

[Chorus]

Give your soul to me
For eternity
release your life
to begin another time with her
End your grief with me
there's another way
release your life
take your place inside the fire with her

Devin
No longer living
Who had been rendered unwhole
As a little child
she was taken,
and then forsaken
you will remember it all
Let it fill your mind again
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
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

vector<long long> v,v1;
long long n,m,q,l,r,fl,func;
long long qps,rem;

int main(){
//freopen("swimming.in","r",stdin);
//freopen("swimming.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>q;v.push_back(q);   
}
sort(v.begin(),v.end());
for (int i=1;i<=m;i++)
{
 cin>>q;v1.push_back(q);
}
sort(v1.begin(),v1.end());

l=0;
r=1e15;
while (l<r)
{
 m=l+r;m/=2;
 func=0;
 fl=0;
 for (int i=0;i<v.size();i++)
 {
  if (v[i]>v1[func]+m)fl=1;
  qps=v1[func];rem=m-abs(v[i]-qps);
  if (qps<v[i])
  {
  rem=rem/2+v[i];
  rem=max(rem,v[i]+m-(v[i]-v1[func])*2);
  }
  else rem=m+v[i];
//  if (m==2)cout<<i<<"   "<<rem<<" "<<func<<" "<<fl<<endl;
  while (func<v1.size()&&v1[func]<=rem)++func;
 // if (m==2)cout<<func<<" %%"<<rem<<" "<<v1[func]<<endl;
//  cout<<func<<"%"<<v1[func]<<" "<<rem<<endl;
//  while (func<v1.size()&&v1[func]<=qps+rem)++func;
  if (func==v1.size())break;
 }     
 //cout<<l<<"   "<<r<<" "<<m<<" "<<func<<" "<<v1.size()<<" "<<fl<<" "<<v1[func]<<endl;
 if (func<v1.size())fl=1;
 if (fl)l=m+1;
 else r=m;
}

cout<<l<<endl;

cin.get();cin.get();
return 0;}