/*
There's an open door 
Callin' to me 
I just can't ignore 
Wakin' up 
I realize 
Bars of steel to keep me inside 
Justice has done me wrong 
Guilty for crime 
Will age me so long 
Understand that it's more than too late 
Where's the lucky dog 
Who used me for the bait 

I'm falling over the edge 

Yeah, I guess he was pretty smart 
Left me in the street with my gun in the dark 
Murder, well I tried to prevent 
Instead up the river is how my time is spent 

I think I'm over the edge 
I've been doin' time 
Tired of doin' time 
Over the edge 

I can't take more of this cell 
So don't be alarmed 
When you hear this prisoner yell 

Far away 
Far away 
Never too far away 
From the truth 

But where's the fairness 
What's a harmless man to do 
But see it through 
Though I'm trapped in this death bringing doom 
Words of hope 
There ain't no place 
For this forgotten face 
I take my chances 

Now I know I'm over the edge 
Over the edge 
Get me out 
Get me out 
Over the edge 
I'm tired 
Over the edge
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

string st;
string temp;
long sz[1000];
string tst;
map<string, long> calc;
string ast;
vector<string> av;

int main(){
//freopen("triangle.in","r",stdin);
//freopen("triangle.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=1;i<=12;i++)sz[i]=30;
sz[1]=sz[3]=sz[5]=sz[7]=sz[8]=sz[10]=sz[12]=31;
sz[2]=28;

cin>>st;
for (int i=2013;i<=2015;i++)
 for (int j=1;j<=12;j++)
  for (int q=1;q<=sz[j];q++)// tq G
  {
   temp="11-11-1111";
   temp[0]=q/10+48;
   temp[1]=q%10+48;
   temp[3]=j/10+48;
   temp[4]=j%10+48;
   temp[6]=i/1000+48;
   temp[7]=i%1000/100+48;
   temp[8]=i%100/10+48;
   temp[9]=i%10+48;
   av.push_back(temp);
  }

for (int i=0;i+9<st.size();i++)
{
 tst="";
 for (int j=i;j<i+10;j++)
 tst+=st[j];
 calc[tst]++;
}  

ast="";
for (int i=0;i<av.size();i++)
if(calc[av[i]]>calc[ast])ast=av[i];
cout<<ast<<endl;

cin.get();cin.get();
return 0;}