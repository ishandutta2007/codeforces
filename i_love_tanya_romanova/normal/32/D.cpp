/*
One by one, they will fall
Execute, conquer all
Threat on earth, body alive
Non convert, unholy cry
Inconcievable reason to flee
Bloodline severed now you're
Free to pray
Now that you see your end
Absolution denied
Into the dark you are sent
Tingle hits your brain
Acceptance that you are done
Sever all your ties
Now your eyes are wide shut
Vacate your fears
Head first, take your pain
Sleep draws near
Final black rain
Grinding flesh into dust
Limbs are flailing with disgust
Horrified at what you now find
Staring at the end of your time
Grinding flesh into dust
Limbs are flailing with disgust
Feel the pull of the dark
Feel the pull of the light
Bloodline severed
Sickened by what
You now see
Bloodline severed
Now your life
Leaves no creed
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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

string st;
char ar[500][500];
long n,m,k;
pair<long,pair<long, long> > ans;
long tr,tx,ty;

bool nice(long a,long b)
{
 if (a<1||a>n)return false;
 if (b<1||b>m)return false;
 return (ar[a][b]=='*');
}

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=m;j++)
  ar[i][j]=st[j-1];
}

for (int r=1;r<=300;r++)
 for (int i=1;i<=n;i++)
  for (int j=1;j<=m;j++)
   if (nice(i,j)&&nice(i-r,j)&&nice(i+r,j)&&nice(i,j-r)&&nice(i,j+r))
    {--k;
     if (k==0)ans=make_pair(r,make_pair(i,j));}
 
if (k>0)cout<<-1<<endl;
else 
{
 long r=ans.first;
 tx=ans.second.first;
 ty=ans.second.second;
 cout<<tx<<" "<<ty<<endl;
 cout<<tx-r<<" "<<ty<<endl;
 cout<<tx+r<<" "<<ty<<endl;
 cout<<tx<<" "<<ty-r<<endl;
 cout<<tx<<" "<<ty+r<<endl;
}
cin.get();cin.get();
return 0;}