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
long s,fp,bd[400000];
string st1,st2;
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
cin>>st1>>st2;
if (st1.size()!=st2.size())
cout<<"NO"<<endl;
else
{
    for (int i=0;i<st1.size();i++)
    {
        if (st1[i]!=st2[i])bd[i]=1;else bd[i]=0;
    }
    fp=-1;
    s=0;
    for (int i=0;i<st1.size();i++)
    {
        if (fp==-1&&bd[i]==1)fp=i;
        s+=bd[i];
    }
    
    if (s!=2)cout<<"NO"<<endl;
    else
    {  
    long fp1;
    fp1=fp+1;
    while (bd[fp1]==0)++fp1; 
  //  cout<<st1[fp]<<" "<<st2[fp]<<" "<<st1[fp1]<<" "<<st2[fp1]<<endl;
    if (st1[fp]==st2[fp1]&&st2[fp]==st1[fp1])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

cin.get();cin.get();
return 0;}