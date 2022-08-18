/*
In your eyes I see you're desperate and in hunger
Reclaim your future, your past uncertain
See this child is raised in hate and in anger
His eyes wide open, his rage so focused

Torn asunder, our destiny is in sight
This is the anthem to celebrate your life
Torn asunder, our destiny is in sight
This is the anthem to celebrate your life

A single mother she is strained and she suffers
She slaves away her life in turmoil
A homeless man had it all and now has nothing
His spirit broken, plagued from injustice

Torn asunder, our destiny is in sight
This is the anthem to celebrate your life
Torn asunder, our destiny is in sight
This is the anthem to celebrate your life

We have the power make our lives what they are to be
Reconnect with our humanity
Transcend to a higher place, accepting reality
You are the key to the life you seek

Torn asunder, our destiny is in sight
This is the anthem to celebrate your life
Torn asunder, our destiny is in sight
This is the anthem to celebrate your life
*/

//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long long n,r;
long long pw(long long a,long long b)
{
     long long q;
  //   cout<<a<<" "<<b<<endl;
     if (b==0)return 1%bs;
     if (b%2==0)return pw(a*a%bs,b/2);
     else return a*pw(a,b-1)%bs;
}

int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
if (n==0)cout<<1<<endl;
else{
//++n;
r=pw(2,n-1);
r=r%bs;
r*=(1+pw(2,n));
r%=bs;
cout<<r<<endl;
}
cin.get();cin.get();
return 0;}