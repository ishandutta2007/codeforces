/*
Damage to my head, peace stays in the bed
Making love the only thing we can do
Otherwise in our lives, all we do is fight
Never stop enough to call a truce

The only time that you find satisfaction
Is in our physical play
You love me in the course of the evening
But so bitter in the day

Think you'd wipe the smudge, but just carry on the grudge
Nothing gets forgiven from you
Soon I'll lose the cure, and you'll thirst so much more
Somebody fresh I wonder who

Now I think it's time for me to walk straight out the door
And leave you here
But my pride hurts too much for that you
Wouldn't even shed a tear

Got to pack my bags, and leave behind the past
Living with you was worse than hell
Still I feel blue, and I wonder do you
With the look on your face you could never tell

Never thought I'd wish somebody death or I'd feel so much hate
Hopefully you'll get what you deserve and be stricken by fate
I hope that you, you get what you want
That's right
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
#include <ctime>
#include <memory.h>
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long long t,a,b,temp;
long long s_mult(long long a,long long b)
{
 if (a==0||b==0)return 0;
 if (2e18/b<=a)return 2e18;
 return a*b;
}

long long s_add(long long a,long long b)
{
 if (a+b>2e18)return 2e18;
 return a+b;
}

void poly(long long a,long long b,long long t)
{
 if (t>a)
 {
 if (a==b)cout<<1<<endl;
 else cout<<0<<endl;
 return;
 }
 vector<long long> v;
 long long temp=b;
 while (temp){v.push_back(temp%a);temp/=a;}
 
 long long base=1;
 long long val=0;
 for (int i=0;i<v.size();i++)
 {
  val=s_add(val,s_mult(base,v[i]));
  base=s_mult(base,t);
  //cout<<base<<"   "<<val<<" "<<t<<endl;
 }
 long long res=0;
 if (val==a)res++;

 if (a==b&&v.size()>1)++res;
 cout<<res<<endl;
}

int main(){
//freopen("knockout.in","r",stdin);
//freopen("knockout.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>t>>a>>b;

if (t==1&&a==1)
{
 if (b==1)
  cout<<"inf"<<endl;
  else cout<<0<<endl;
}
else if (t==1&&a>1)
{
     if (a==b)
     cout<<1<<endl;
     else
     {
         long av=0;
      temp=a;
      while (t<=b)
      {
       temp=s_mult(temp,a);
       if (temp>b)break;
       if (temp==b)av=1;
      }
      if(av)cout<<1<<endl;
      else poly(a,b,t);
     }
}
else // easy
poly(a,b,t);

cin.get();cin.get();
return 0;}