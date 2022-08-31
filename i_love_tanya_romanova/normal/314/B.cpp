/*
Dear Mother
Dear Father
What is this hell you have put me through
Believer
Deceiver
Day in day out live my life through you
Pushed onto me what's wrong or right
Hidden from this thing that they call life

Dear Mother
Dear Father
Every thought I'd think you'd disapprove
Curator
Dictator
Always censoring my every move
Children are seen but are not heard
Tear out everything inspired

Innocence
Torn from me without your shelter
Barred reality
I'm living blindly

Dear Mother
Dear Father
Time has frozen still what's left to be
Hear nothing
Say nothing
Cannot face the fact I think for me
No guarantee, it's life as is
But damn you for not giving me my chance

Dear Mother
Dear Father
You've clipped my wings before I learned to flyUnspoiled
Unspoken
I've outgrown that fucking lullaby
Same thing I've always heard from you
Do as I say not as I do

Innocence
Torn from me without your shelter
Barred reality
I'm living blindly

I'm in hell without you
Cannot cope without you two
Shocked at the world that I see
Innocent victim please rescue me

Dear Mother
Dear Father
Hidden in your world you've made for me
I'm seething
I'm bleeding
Ripping wounds in me that never heal
Undying spite I feel for you
Living out this hell you always knew
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
#define bs 1000002013
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long b,q,n,m;
string st1,st2;
pair<long long, long long> pa;
long long full,qp;
pair<long long,long long> move[200][50];
pair<long long, long long> answ[200];
long long rem;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>b>>q;
cin>>st1;
cin>>st2;
n=st1.size();m=st2.size();

for (int stp=0;stp<m;stp++)
{
 full=0;
 qp=stp;
 for (int i=0;i<st1.size();i++)
 {
     if (st1[i]==st2[qp])
     {
      ++qp;
      if (qp==m)
      {
       ++full;qp=0;
      }
     }
 }   
 move[stp][0]=make_pair(qp,full);
}

for (int mo=0;mo<30;mo++)
for (int stp=0;stp<m;stp++)
{
    pa=move[stp][mo];
    pa.second+=move[pa.first][mo].second;
    pa.first=move[pa.first][mo].first;
    move[stp][mo+1]=pa;
   // if (mo<=3)cout<<mo<<" "<<stp<<" "<<pa.first<<" "<<pa.second<<endl;
}

for (int stp=0;stp<m;stp++)
{
   rem=b;
   pa=make_pair(stp,0);
   for (int j=30;j>=0;--j)
   if (rem&(1<<j))
   {
    pa.second+=move[pa.first][j].second;
    pa.first=move[pa.first][j].first;
   }
   answ[stp]=pa;
}
//for (int i=0;i<m;i++)
//cout<<i<<"!"<<answ[i].first<<" "<<answ[i].second<<endl;

cout<<answ[0].second/q<<endl;

cin.get();cin.get();
return 0;}