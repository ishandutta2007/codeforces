/*
I'm out on the open sea
the wind is embracing me
I'm watching the setting sun
Far far away from you
there's not much that I could
Do you know what's the only way for me

Into the depths I fall
into the unknown darkness I go

Down, Down, Down
down, down, down
falling into the Abyss

A morning of no recall
no memory no nothing at all
the sun is blinding my eyes
The pain I feel in my head
I think I go back to bed
Or should I have just one more

Into the depths I fall
into the unknown darkness I go

Down, Down, Down
down, down, down
falling into the Abyss
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
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3

using namespace std;

string st1,st2;
long y1,y2,d1,d2,m1,m2;
long ans;

long gmlen()
{
     if (m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12)return 31;
     if (m1==4||m1==6||m1==9||m1==11)return 30;
     if (y1%400==0)return 29;
     if (y1%100==0)return 28;
     if (y1%4==0)return 29;
     return 28;
}

void incd()
{
    /* cout<<d1<<" "<<m1<<" "<<y1<<endl;
     cin.get();*/
     long p=gmlen();
     ++d1;
     if (d1>p){d1=1;++m1;}
     if (m1==13){m1=1;y1++;}
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st1;
cin>>st2;
y1=st1[0]-48;
y1*=10;
y1+=st1[1]-48;y1*=10;
y1+=st1[2]-48;y1*=10;
y1+=st1[3]-48;

m1=st1[5]-48;
m1=m1*10+st1[6]-48;

d1=st1[8]-48;
d1=d1*10+st1[9]-48;

y2=st2[0]-48;
y2*=10;
y2+=st2[1]-48;y2*=10;
y2+=st2[2]-48;y2*=10;
y2+=st2[3]-48;

m2=st2[5]-48;
m2=m2*10+st2[6]-48;

d2=st2[8]-48;
d2=d2*10+st2[9]-48;
if (y1>y2||(y1==y2&&m1>m2)||(y1==y2&&m1==m2&&d1>d2))
{swap(d1,d2);swap(m1,m2);swap(y1,y2);}

/*
cout<<y1<<" "<<m1<<" "<<d1<<endl;
cout<<y2<<" "<<m2<<" "<<d2<<endl;
*/
while (d1!=d2||m1!=m2||y1!=y2)
{
      ++ans;
      incd();
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}