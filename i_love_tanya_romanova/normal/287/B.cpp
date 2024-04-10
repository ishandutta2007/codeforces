/*
All around me are familiar faces
Worn out places
Worn out faces
Bright and early for their daily races
Going nowhere
Going nowhere
Their tears are filling up their glasses
No expression
No expression
Hide my head I wanna drown my sorrow
No tomorrow
No tomorrow
And I find it kind of funny
I find it kind of sad
The dreams in which I'm dying are the best I've ever had
I find it hard to tell you
I find it hard to take
When people run in circles it's a very very
Mad world
Mad world
Mad world
Mad world
Children waiting for the day they feel good
Happy birthday
Happy birthday
And to feel the way that every child should
Sit and listen
Sit and listen
Went to school and I was very nervous
No one knew me
No one knew me
Hello teacher tell me what's my lesson
Look right through me
Look right through me
And I find it kind of funny
I find it kind of sad
The dreams in which I'm dying are the best I've ever had
I find it hard to tell you
'Cos I find it hard to take
When people run in circles it's a very very
Mad world
Mad world
Mad World
Mad world
And I find it kind of funny
I find it kind of sad
The dreams in which I'm dying are the best I've ever had
I find it hard to tell you
'Cos I find it hard to take
When people run in circles it's a very very
Mad world
Mad world
Halargian world
Mad world
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long long l,r,s1,s2,n,k;

long long solve(long long n,long long k)
{
 if (n==1)return 0;
 --n;
 if (k*(k-1)/2<n)return -1;
 l=0;
 r=k-1;
 while (l<r)
 {
       long long m=l+r+1;m/=2;
       s1=k*(k-1)/2;
       s2=m*(m+1)/2;
       if (s1-s2>=n)l=m;else r=m-1;
      // cout<<s1<<" "<<s2<<" "<<l<<" "<<r<<endl;
 }
// cout<<l<<endl;
return k-l-1;
}

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
cout<<solve(n,k)<<endl;

cin.get();cin.get();
return 0;}