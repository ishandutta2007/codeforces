/*
You are all that matters in my private demonology
those who fail us now
the sons of wishes
the bastard child of dream
enemies of hope
let it be gone
it's all pretend

Mind matters, matters not

Never again
in perfect clarity
see the day in childlike vision
where does it lead from here
on without that guidance
disaster role model without a part
our search is wider
cast off those wide-eyed hopes and dreams

Mind matters, matters not

No need to see you there
the path we made is clear
just stay ahead of me
this is not for me to see

This time a prayer onto nothing
project again
direct oppose to action
all across the board
shortcomings close to call
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

string st,st1;
long long a,vall;

long evv(char c)
{
 if (c>='A')return c-'A'+10;
 return c-'0';
}

long long eval(string st,long bas)
{
long long r=0;
 for (int i=0;i<st.size();i++)
 r=r*bas+evv(st[i]);
 return r;
}

void g(long x)
{
 if (x<=9)cout<<x;else
 cout<<char(x-10+'A');
}

void showw(long long x, long long bas)
{
 if (x==0){cout<<0<<endl;return;}
 vector<long long> v;
 while (x)
 {
  v.push_back(x%bas);x/=bas;
 }
 reverse(v.begin(),v.end());
 for (int i=0;i<v.size();i++)
 {
  g(v[i]);
 }
 cout<<endl;
}

void solve(long x)
{
 while (x>=1000){cout<<"M";x-=1000;}
 while (x>=900){cout<<"CM";x-=900;}
 while (x>=500){cout<<"D";x-=500;}
 while (x>=400){cout<<"CD";x-=400;}
 while (x>=100){cout<<"C";x-=100;}
 while (x>=90){cout<<"XC";x-=90;}
 while (x>=50){cout<<"L";x-=50;}
 while (x>=40){cout<<"XL";x-=40;}
 while (x>=10){cout<<"X";x-=10;}
 while (x>=9){cout<<"IX";x-=9;}
 while (x>=5){cout<<"V";x-=5;}
 while (x>=4){cout<<"IV";x-=4;}
 while (x>=1){cout<<"I";x-=1;}
 cout<<endl;
}
int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a;
cin>>st;
cin>>st1;
vall=eval(st1,a);

if (st=="R")
{
 solve(vall);
}
else
{
 a=eval(st,10);
// cout<<vall<<" "<<a<<endl;
 showw(vall,a);
}

cin.get();cin.get();
return 0;}