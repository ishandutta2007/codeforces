/*
Memory is fiction, so the past is your invention
Catch yourself, self-dissect, how youth outlives age
How beauty shames skill
Prayer is for dependents and wish is for the will
A struggle for independence, a harmless stage
Art gaining post-mortem fame

Oh Creatice!
Your vibrant portfolio has never shown as brightly
As your latest masterpiece
All efforts' fruition in such a wondrous offspring
How did you manage a piece so perfect?

Entrancing passers-by to lock eyes and gaze, hypnotized
Overcome with a need to outdo the last
A child born so dependent rebels so quickly once he has his footing
Forgets who and where raised him and how he came to be

But a growing pain cannot explain behavior of the like
A perfect child deserves the best
But at the cost of what else did you instill this need
To over-consume without regret?

Broken pencils, charred marble drafts
He leaves destruction in his path
Your one mistake, oh great Creatice
Was giving too large a brain

(This organ, like disease, can disseminate beyond your reach
You didn't predict this, a carnal rebellion in its wake)

Strike back with forces beyond his reach
That even six billion can't defeat
Go lock up the aggressor, quarantine before it's too late
Bred to lose sense of consequence
In his greed he exhausts your milk, your blood, your shelter...
Don't let him escape!

Memory is fiction, so the past is your invention
Catch yourself, self-dissect, how youth outlives age
How beauty shames skill
Prayer is for dependents and wish is for the will
A struggle for independence, a harmless stage
Art gaining post-mortem fame

Throw your blood upon his lands, your skin cracked and depleted
Suck the air out from his lungs, expose him fully, let him burn
Show him to appreciate, discipline the cruel ingrate
You still have theh power to reshape - do not let this escalate

Vapors vanish in the night, statuesque guards seconds too late
What rebellion possessed thee?
A dangerous subterfuge, a lonely rampage, anxious fleet
Like limbs tumbling horizontally

Now it's too late - the child has escaped!
Indignant ties, parental constraints
A child protected sets self free
And the ingrate will lie in the bed he has made
As a self-imposed apocalypse finally sets You free
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

long ww,bb;
long was[1050][1050];
double ans[1050][1050];

double solve(long w,long b)
{
if (w==0)return 0;
if (b==0)return 1;

if (was[w][b])return ans[w][b];
was[w][b]=1;

double win=1.0*w/(w+b);
if (b>1)win+=1.0*b/(w+b)*(b-1)/(w+b-1)*solve(w-1,b-2)*w/(w+b-2);
if (b>2)win+=1.0*b/(w+b)*(b-1)/(w+b-1)*solve(w,b-3)*b/(w+b-2);

ans[w][b]=win;
return win;
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>ww>>bb;
cout.precision(10);
for (int i=0;i<=1000;i++)
 ans[0][i]=0;
for (int i=1;i<=1000;i++)
 ans[i][0]=1;

for (int w=1;w<=1000;w++)
 for (int b=1;b<=1000;b++)
 {
  double win=w*1.0/(w+b);
if (b>1)win+=1.0*b/(w+b)*(b-1)/(w+b-1)*ans[w-1][b-2]*w/(w+b-2);
if (b>2)win+=1.0*b/(w+b)*(b-1)/(w+b-1)*ans[w][b-3]*(b-2)/(w+b-2);
ans[w][b]=win;
 }
 
//cout<<solve(w,b)<<endl;
cout<<ans[ww][bb]<<endl;

cin.get();cin.get();
return 0;}