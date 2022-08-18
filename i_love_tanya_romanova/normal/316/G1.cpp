/*
Razors edge
Outlines the dead
Incisions in my head
Anticipation the stimulation
To kill the exhilaration

[CHORUS]
Close your eyes
Look deep in your soul
Step outside yourself
And let your mind go
Frozen eyes stare deep in your mind as you die

[CHORUS 2]
Close your eyes
And forget your name
Step outside yourself
And let your thoughts drain
As you go insane... go insane

Innate seed
To watch you bleed
A demanding physical need
Desecrated eviscerated
Time perpetuated

[CHORUS]

[CHORUS 2]

Inert flesh
A bloody tomb
A decorated splatter brightens the room
An execution a sadist ritual
Mad intervals of mind residuals

[CHORUS]

[CHORUS 2]
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
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
#define bs 1000000000
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3

using namespace std;

string st;
long zr;
string t,temp;
map<long long, int >calc[100];
long fl,d[100],u[100];
set<string> ans;
long long pp;
long long r;
long long fl1,hhash;

long long gh(string st)
{
     r=0;
     for(int i=0;i<st.size();i++)
     r=r*173+st[i];
     return r;
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
cin>>zr;
for (int ii=1;ii<=zr;ii++)
{
    cin>>t;
    for (int i=0;i<t.size();i++)
    {
        temp="";
        hhash=0;
        for (int j=i;j<t.size();j++)
          {  hhash=hhash*173+t[j];
            calc[ii][hhash]++;}
    }
    cin>>d[ii]>>u[ii];
    
}
for (int i=0;i<st.size();i++)
{
    fl1=0;
    for (int j=i;j<st.size()&&fl1==0;j++)
    {
        temp="";
        for (int q=i;q<=j;q++)temp+=st[q];
        fl=0;
        pp=gh(temp);
        for (int q=1;q<=zr;q++)
        if (calc[q][pp]<d[q]){fl1=1;break;}
        else if (calc[q][pp]>u[q]){fl=1;break;}
       // fl=1;
        if (fl==0&&fl1==0)ans.insert(temp);
    }
}
cout<<ans.size()<<endl;

cin.get();cin.get();
return 0;}