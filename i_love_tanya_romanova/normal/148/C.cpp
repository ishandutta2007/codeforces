/*
Keep out the intruders! Put the drawbridge up!
The enemy ransacked what we had just rebuilt!
Now the garden lies in serene symmetry
And severe color theory.
Roots slowly poisoining
Through strategic seeds planted inside.
We're much safer self-preserved.
Let the Dead Sea rise.
No, the watch dogs aren't robots.
They can't defend against their lures.
Doors that weld shut behind you and books that fly like birds.
Crushed by backpacks filled with ammo,
luggage carts distracted the defense.
And the troops sneak in undetected, charades begin, start the pretense.
Obsessive thought in royal chambers invites Trojan warriors in.
Little exceptions seem so harmless, little victories, little wins.
And now why has the plan failed? We sit here aimless once again.
With all units deployed fully, how is it we let him in?
All the corporals agreed: zero-tolerance enforced.
But as cold as doorknobs were I somehow still opened the doors.
Each battle lost is a mile gained on the terminal timeline.
We all fear the last few inches but they're so far out, we're blind.
A dysfunctional team, we are, no one following the rules.
Yes I'll do my best to protect you but your disobedience intrudes.
Skeletons escape the flesh like ants through tightly clenched fists.
This time impeach the tyrant!
What a contradictory statement -- suicidal self-preservationist.
Although logic understands, prison chambers still exist.
Chambers East and West conspiring, neighbors North and South unite.
With the four working against me I'm powerless and losing sight!
Each battle lost is a mile gained on the terminal timeline.
We all fear the last few inches but they're so far out, we're blind.
This is a forced entry. This is the algometry.
This is panophobic. Immunity gets sick.
This is a forced entry. This is the algometry.
This is panophobic. Taken down, brick by brick.
This is a forced entry. This is the algometry.
This is panophobic. This is the last conflict.
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

long n,a,b,s;
vector<long> ans;
long temp;

void add(long x)
{
 s+=x;
 ans.push_back(x);
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>a>>b;
if (b)// all b's 1st, then a
{
 add(2);
 for (int i=0;i<b;i++)
  add(s+1);
}

else if (a){add(2);add(1);}// to gett a instd b

for (int i=0;i<a;i++)// do a
 {
  temp=ans[ans.size()-1]+1;
  if (temp<3)temp=3;
  add(temp);
 }
while (ans.size()<n)add(1);// sp

if (ans.size()>n)
{
 cout<<-1<<endl;
}
else
{
 for (int i=0;i<n;i++)
 {
  if (i)cout<<" ";
  cout<<ans[i];
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}