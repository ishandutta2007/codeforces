/*
I remember it as plain as day
Although it happened in the dark of the night.
I was strolling through the streets of Paris
And it was cold it was starting to rain.
And then I heard a piercing scream
And I rushed to the scene of the crime
But all I found was the butchered remains
Of two girls lay side by side.

Murders in the Rue Morgue
Someone call the Gendarmes
Murders in the Rue Morgue
Run before the killers go free

There's some people coming down the street
At last there's someone heard my call
I can't understand why they're pointing at me
I never done nothing at all.
But I must have got some blood on my hands
Because everyone's shouting at me
I can't speak French so I couldn't explain
And like a fool I started running away.

Murders in the Rue Morgue
Someone call the Gendarmes
Murders in the Rue Morgue
Am I ever gonna be free.

And now I've gotta get away from the arms of the law.
All France is looking for me.
I've gotta find my way across the border for sure
Down the south to Italy.

Murders in the Rue Morgue
Someone call the Gendarmes
Murders in the Rue Morgue
I'm never going home.

Well I made it to the border at last
But I can't erase the scene from my mind
Anytime somebody stares at me, well
I just start running blind
Well I'm moving through the shadows at night
Away from the staring eyes
Any day they'll be looking for me
'Cause I know I show the signs of...

Murders in the Rue Morgue
Running from the Gendarmes
Murders in the Rue Morgue
Running from the arms of the law

Murders in the Rue Morgue
Running from the Gendarmes
Murders in the Rue Morgue
Am I ever gonna be free

It took so long and I'm getting so tired
I'm running out of places to hide
Should I return to the scene of the crime
Where the two young victims died
If I could go to somebody for help
It'd get me out of trouble for sure
But I know that it's on my mind
That my doctor said I've done it before.

Murders in the Rue Morgue
They're never gonna find me
Murders in the Rue Morgue
I'm never going home.
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