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
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
string st,st1;
long q,nm[100];

int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
cin>>st;
cin>>st1;
for (int i=0;i<st1.size();i++)
{
    nm[st1[i]-48]++;
}
for (int i=0;i<st.size();i++)
{
    q=9;
    while (nm[q]==0)--q;
    if (q>st[i]-48){--nm[q];st[i]=q+48;}
 cout<<st[i];  
}
cin.get();cin.get();
return 0;}