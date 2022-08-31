/*
How do you feel right now
How does it feel to be alone
How do you feel right now
Tell me

Hey angel - what's your situation
Hey angel - oh, oh

Where would you be right now
Waiting to taste your next tomorrow
Where would you be right now
Tell me

Was the pain too strong to take it anymore
So you turned off all the lights and shut the door

Hey angel - what's your destination
Hey angel
Hey angel - we got a complication
Hey angel - oh, oh - you're my angel, my angel

How do you feel right now
How does it feel to be alone, oh
How do you feel right now
How do you feel right now

Oh angel - you're my angel, oh my angel,...
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

string st,z;
vector<string> temp,ans;
long bd,n,tests;

string nnorm(string st)
{
 while (st.size()<4)st="0"+st;
 return st;
}

int main(){
//freopen("experimental.in","r",stdin);
//freopen("experimental.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>tests;
for (;tests;--tests)
{
    cin>>st;
    if (st[st.size()-1]!=':')
    st+=":";
    temp.clear();
    for (int i=0;i<st.size();i++)
    {
     if (st[i]==':'){if (i>0||z.size()>0)temp.push_back(z);z="";}
     else
     {z+=st[i];}
    }
    bd=8-temp.size()+1;
    ans.clear();
    
//    cout<<bd<<" "<<temp.size()<<endl;
    
    for (int i=0;i<temp.size();i++)
    {
        if (temp[i].size())
        {
         ans.push_back(nnorm(temp[i]));                   
        }
        else if (i==0||temp[i-1].size()>0)
        for (int j=0;j<bd;j++)
        ans.push_back("0000");
    }
  //  cout<<ans.size()<<endl;
    
    for (int i=0;i<ans.size();i++)
    {
        if (i)cout<<":";
        cout<<ans[i];
    }
    cout<<endl;
}

cin.get();cin.get();
return 0;}