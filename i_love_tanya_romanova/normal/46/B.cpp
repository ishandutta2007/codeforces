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
#define INF 1000000000
#define eps 1e-9
//#define M_PI 3.141592653589793
#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
using namespace std;
string st;
long fl,t,qq,s[200];
long gett(string st)
{
     if (st=="S")return 1;
     if (st=="M")return 2;
     if (st=="L")return 3;
     return st.size()+2;
}
void showw(long a)
{if (a==1)cout<<"S";
if (a==2)cout<<"M";
if (a==3)cout<<"L";
if (a==4)cout<<"XL";
if (a==5)cout<<"XXL";
cout<<endl;}

void tryy(long a)
{if (fl)return;
 if (s[a]>0){--s[a];showw(a);fl=1;return;}
 }
 
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
for (int i=1;i<=5;i++)cin>>s[i];
cin>>t;
for (;t;--t)
{cin>>st; qq=gett(st);
 fl=0;
tryy(qq);tryy(qq+1);tryy(qq-1);tryy(qq+2);tryy(qq-2);tryy(qq+3);tryy(qq-3);tryy(qq+4);tryy(qq-4);}

cin.get();cin.get();
return 0;}