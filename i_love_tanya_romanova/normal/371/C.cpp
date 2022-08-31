/*
Don't look at me as if I didn't know
Your vanity is all you ever show
What you believe and advocate
Fanatic dogma recycled from yesterday

Got a master plan
Genocide
Can't understand
People of the lie

You are to me the waste of flesh and blood
I'd love to see you buried in the mud
And when you die no one will shed a tear
So pass me by don't need your hatred here

Got a master plan
Genocide
Can't understand
People of the lie

Prejudice, intolerance, eye for an eye

You cannot hide behind those empty claims
Your racist pride is nothing but a game
And you will lose for right is on the side
Of those who choose to fight for humankind

Got a master plan
Genocide
Can't understand
People of the lie

You can't believe
Don't be deceived
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
#define eps 1e-4
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000
#define double long double

using namespace std;

string st;
long long h1,h2,h3,n1,n2,n3,p1,p2,p3,l,r,m,money;

long long  gett(long long x)
{long long res,need;
 res=0;
 need=n1*x;
 if (h1>=need)res+=0;
 else res+=(need-h1)*p1;
 
 need=n2*x;
 if (h2>=need)res+=0;
 else res+=(need-h2)*p2;
 
 need=n3*x;
 if (h3>=need)res+=0;
 else res+=(need-h3)*p3;
 return res;
}

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
    if (st[i]=='B')n1++;
    else if (st[i]=='S')n2++;
    else if (st[i]=='C')n3++;
}

cin>>h1>>h2>>h3;
cin>>p1>>p2>>p3;

cin>>money;
l=0;
r=1e14;

while (l<r)
{
 m=l+r+1;
 m/=2;
 if (gett(m)>money)
 {
  r=m-1;
 }
 else l=m;
}
cout<<l<<endl;
cin.get();cin.get();
return 0;}