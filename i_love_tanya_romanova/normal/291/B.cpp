/*
Poisoning a drink, Bleeding in a sink 
Choking with a link, Killing with a stink 
Just your mother's 
HO 
Bleeding in a sink, Poisoning a drink 
Burning up 
My sweet Clementine 

Trampling a shrink, Bleeding in a sink 
Hallelujah wink , Getting on the brink 
Just your mother's 
HO 

Hallelujah wink, Murdering a shrink 
Burning up 

On my sweet revenge 
Will be yours for the taking 
It's in the making baby, aaaaaahhh 
My sweet revenge 
Will be yours, for the taking 
It's in the making baby, aaaaaahhh 

Killing with a stink, Bleeding in a sink 
Poisoning a drink, Getting on the brink 
Just your mother's 
HO 
Bleeding in a sink, Trampling a shrink 
Burning up 
My sweet Clementine 

Poisoning a drink, Bleeding in a sink 
Choking with a link, Killing with a stink 
Just your mother's 
HO 

Poisoning a drink, Bleeding in a sink 
Burning up
On my sweet revenge 
Will be yours, for the taking 
It's in the making baby, aaaaahhh
My sweet revenge 
Will be yours, for the taking 
It's in the making baby, aaaaahhh

I saw her laugh 
Then she said, "Go Away" 
I saw her laugh 
Then she said, then she said, 
"Go away, away" 

My sweet revenge 
Will be yours for the taking 
It's in the making baby

My sweet revenge 
Will be yours it's in the making 
It's in the taking, making, baking, taking, faking 
HO 
My sweet Clementine 
HO 
Shoulda been could been 
Woulda been would been you 
Shoulda been could been 
Woulda been would been you
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
#define eps 1e-5
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
 
using namespace std;

long fl;
string st,temp;

void putcom()
{
     fl=0;
     cout<<"<";
     cout<<temp;
     cout<<">"<<endl;
     temp="";
}
int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

getline(cin,st);
for (int i=0;i<st.size();i++)
{
    if (st[i]==34)
    {
     if (fl){putcom();fl=0;}
     else{fl=1;}
    }
    else
    {
     if (fl){temp+=st[i];}
     else
     {
         if (st[i]==' ')
         {
                      if (temp.size()){putcom();}
         }
         else temp+=st[i];
     }   
    }
}
if(temp.size())putcom();

cin.get();cin.get();
return 0;}