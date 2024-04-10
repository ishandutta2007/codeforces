/*
Mean and infectious
The evil prophets rise
Dance of the macabre
As witches streak the sky
Decadent worship of
Black magic and sorcery
In the womb of the devils dungeon
Trapped without a plea

See thing in agony
Necrosis is the fate
Pins sticking through the skin
The venom now sedates
Locked in a pillory
Nowhere to be round
Screaming for your life
But no-one hears a sound
Help me
Prepare the patients scalp
To peel away
Metal caps his ears
He'll hear not what we say
Solid steel visor
Riveted cross his eyes
Iron staples close his jaws
So no one hears his cries
The skull beneath the skin
Now your drawn and quartered
Your bones will make the x
Symbol stands for poison
And it's chained to your head
And as we fold your arms
To make the holy cross
We cross the crucifix
Religion has been lost
The skull beneath the skin
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long sz[1000];
string st;
string nm[1000];
long n1[1000],n2[1000],n3[1000];
long tests;
long bn1,bn2,bn3;
vector<string> v1,v2,v3;

string parse(string st)
{
 string st1;
 for (int i=0;i<st.size();i++)
 if (st[i]>='0'&&st[i]<='9')st1+=st[i];
 return st1;
}

bool issame(string st)
{
     for (int i=0;i<st.size();i++)
     if (st[i]!=st[0])return false;
     return true;
}

bool isdown(string st)
{
 for (int i=1;i<st.size();i++)
 if (st[i]>=st[i-1])return false;
 return true;
}

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>tests;
for (int test=1;test<=tests;++test)
{
 cin>>sz[test]>>nm[test];
 for (int i=1;i<=sz[test];i++)
 {
     cin>>st;
     st=parse(st);
     if (issame(st))n1[test]++;
     else if (isdown(st))n2[test]++;
     else n3[test]++;
 }   
}

//for (int i=1;i<=tests;i++)
//{
//    cout<<nm[i]<<" "<<n1[i]<<" "<<n2[i]<<" "<<n3[i]<<endl;
//}

for (int i=1;i<=tests;i++)
{
 if (n1[i]>bn1)bn1=n1[i];
 if (n2[i]>bn2)bn2=n2[i];
 if (n3[i]>bn3)bn3=n3[i];   
}

for (int i=1;i<=tests;i++)
{
    if (n1[i]==bn1)v1.push_back(nm[i]);
    if (n2[i]==bn2)v2.push_back(nm[i]);
    if (n3[i]==bn3)v3.push_back(nm[i]);
}
cout<<"If you want to call a taxi, you should call:";
for (int i=0;i<v1.size();i++)
{
    if (i)cout<<",";
    cout<<" ";
    cout<<v1[i];
}
cout<<"."<<endl;

cout<<"If you want to order a pizza, you should call:";
for (int i=0;i<v2.size();i++)
{
    if (i)cout<<",";
    cout<<" ";
    cout<<v2[i];
}
cout<<"."<<endl;

cout<<"If you want to go to a cafe with a wonderful girl, you should call:";
for (int i=0;i<v3.size();i++)
{
    if (i)cout<<",";
    cout<<" ";
    cout<<v3[i];
}
cout<<"."<<endl;

cin.get();cin.get();
return 0;}