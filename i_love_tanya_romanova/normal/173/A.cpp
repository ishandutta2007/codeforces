#pragma comment(linker, "/STACK:214777216")
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long long gcd(long long a, long long b)
{while (a&&b){a>b?a%=b:b%=a;} return a+b;
}

long long lcm(long long a,long long b)
{return a/gcd(a,b)*b;}

long long n1,n2,n,q,w,e,aa1,bb1,a1,a2,b1,b2;
string st1,st2;
char a,b;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;

cin>>st1;
cin>>st2;
n1=st1.size();n2=st2.size();

q=lcm(n1,n2);

w=n/q;

e=n%q;

for (int i=0;i<q;i++)
{
 a=st1[i%n1];
 b=st2[i%n2];
 a1=a2=0;b1=b2=0;
 if (a=='R'&&b=='S')a1=1;
 else if (a=='S'&&b=='P')a1=1;
 else if (a=='P'&&b=='R')a1=1;
 else if (a!=b)b1=1;   
 if (i<e){aa1+=a1*(w+1);bb1+=b1*(w+1);}
 else {aa1+=a1*w;bb1+=b1*w;}
}
cout<<bb1<<" "<<aa1<<endl;

cin.get();cin.get();
return 0;}