/*
I am oppressed by lack of power
Holding on until the end
Helping me tread on your life
Life is the game, strengthen my anger
Reshape the misguided times
See me then, die, fate has control of us all
Blemish the quest of all
Create the dread

Waiting in line, lost in your prayer
Lost in your insanity
It seems to be real
Soothing the pain that you feel
Can't find the key to destiny
Life is your quest, erase your quest

Your christ is failing you, like poison running through
Does god know what to do, as I tell the harboured truth
While grief lies at your door, for shreds of flesh you've torn
The pain comes back for me, too vague for you too see

Lord, smile at me
My ashes have scattered the plains
Won't return again...
Lord stare at me
Wait here for me to rise, rise again...

Finding the truth, behind lies, logic is paralysed
Feeding the flesh, consuming the rest
You'll reach your end, you'll pay the debts and silently send
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long temp;
vector<long long> reach;
long long tests;
string st;
long long n,need[2000];
long long dp[200][200];
pair<long long,long long> par[200][200];
long long ps;
long long anss[200][200];
long long gett[200][200];
long long sz[200];

int main(){
//freopen("deny.in","r",stdin);
//freopen("deny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=0;i<=6;i++)
for (int j=0;j+i<=6;j++)
{temp=i*4+j*7;reach.push_back(temp);
for (int q=1;q<=i;q++)
gett[temp][q]=4;
for (int q=i+1;q<=i+j;q++)
gett[temp][q]=7;
for (int q=i+j+1;q<=6;q++)
gett[temp][q]=0;}


/*
for (int i=0;i<10;i++)
{
    //cout<<i<<" "<<endl;
    for (int j=0;j<reach[i].size();j++)
    cout<<reach[i][j]<<" ";
    cout<<endl;
}*/

cin>>tests;

for (;tests;--tests)
{
 cin>>st;
 
 reverse(st.begin(),st.end());
 n=st.size();
 for (int i=1;i<=n;i++)need[i]=st[i-1]-48;
 
 for (int i=0;i<=n;i++)
  for (int rem=0;rem<=9;rem++)
   {dp[i][rem]=0;}
 
 dp[0][0]=1;
 
 for (int i=0;i<n;i++)
 for (int rem=0;rem<=9;rem++)
 {
     if (dp[i][rem]==0)continue;
     for (int q=0;q<reach.size();q++)
     {
         temp=rem+reach[q];
         if (temp%10!=need[i+1])continue;
         dp[i+1][temp/10]=1;
         par[i+1][temp/10]=make_pair(rem,reach[q]);
     }
 }  
 if (dp[n][0]==0)cout<<-1<<endl;
// else cout<<"OK"<<endl;
 else // t pQ
 {
  ps=0;
  for (int i=n;i;--i)
  {
   temp=par[i][ps].second;
   ps=par[i][ps].first;
 //  cout<<"%%%"<<temp<<endl;
   for (int j=1;j<=6;j++)
   anss[j][i]=gett[temp][j];
  }
 
 for (int i=1;i<=6;i++)
 {sz[i]=n;
 while (anss[i][sz[i]]==0&&sz[i]>1)--sz[i];}
 
 for (int i=1;i<=6;i++)
 {
     for (int j=sz[i];j;--j)
     cout<<anss[i][j];
     if(i==6)cout<<endl;
     else cout<<" ";
 }
}
}

cin.get();cin.get();
return 0;}