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
#define eps 1e-8
//#define M_PI 3.141592653589793
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
double tt,anstt;
long long ansp,answ,tod[2000000],x1,x2,t1,t2,t0,ps;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>t1>>t2>>x1>>x2>>t0;
if (t1==t2&&t1==t0)cout<<x1<<" "<<x2<<endl;
else
{
tod[0]=x2;
ps=0;
for (int i=1;i<=x1;i++)
{
 long    fl=0;while ((i*t1+ps*t2)<(i+ps)*t0)
    {++ps;fl=1;if (ps>x2)break;
    }
    //if (fl)
    //++ps;
    
    tod[i]=ps;
}

//cout<<tod[1]<<endl;

anstt=10000000;
for (int i=0;i<=x1;i++)
{if (tod[i]<=x2)
{tt=i*t1+tod[i]*t2;
 tt=tt*1.0/(i+tod[i]);
 anstt=min(anstt,tt);
}}
//cout<<tod[0]<<" "<<tod[1]<<endl;

anstt+=eps;
answ=-1;
for (int i=0;i<=x1;i++)
{if (tod[i]<=x2){
    tt=i*t1+tod[i]*t2;
     tt=tt*1.0/(i+tod[i]);
     if (tt<anstt)
     {if (answ<i+tod[i])
     {answ=i+tod[i];ansp=i;}
     }
}}

//cout<<tod[1]<<endl;
cout<<ansp<<" "<<tod[ansp]<<endl;
}
cin.get();cin.get();
return 0;}