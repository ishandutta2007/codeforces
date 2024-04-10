/*
Well I see him everyday in that blanket that he calls home
I wonder does he know that his family they're left alone
He says, Brother can you spare, can you spare a dime
I'm down to my last dollar this life of mine
Said this life of mine gets rough at times

Now I wonder does he know does he even care
That his family, they're safe at home and they wonder where
As he wanders through his life, he's ever searchin' for
A warm blanket on warm fields and he wanders on
And he wonders is he safe from the cold?

Safe out from the cold

Well I see he left the other day took his blanket that he called home
Did he go for good or did he pass away?
Well I wonder does he know see I'm down to my last dollar
And this life of mine said this life of mine, it gets rough at times

And now I wonder does he know, does he even care?
That my family is safe at home and they wonder where
As I wander through my life ever searchin' for
My warm blanket on warm fields as I wander on
And I wonder will I always be helped along?

I said I, I'll never know no, no
Because I, I'll never go and no, no
Yes, I, I said I wonder why, yeah
Because I yeah, oh no I'll never come home
I'll never come home, never come home
Won't you let me come home? Doesn't wanna come home

Oh, said, oh I got I'll never know
Yes, I, I'll never go no, no
Yes, I, I said I wonder why yeah
Because oh yeah, oh no, I'll never come home
I'll never come, never come home, home
I wanna come home, won't you let me come home?
'Cause I wanna come home, let me come home?
Come home
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
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

vector<string> zr;
string req,st;
long qi,qj;

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

zr.push_back("qwertyuiop");
zr.push_back("asdfghjkl;");
zr.push_back("zxcvbnm,./");
cin>>req;
cin>>st;
for (int i=0;i<st.size();i++)
{
 for (int j=0;j<zr.size();j++)
  for (int q=0;q<zr[j].size();q++)
   if (zr[j][q]==st[i])
    qi=j,qj=q;
  if (req=="L")
  cout<<zr[qi][qj+1];
  else cout<<zr[qi][qj-1];
}
cout<<endl;

cin.get();cin.get();
return 0;}