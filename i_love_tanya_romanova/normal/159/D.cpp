/*
Strive, strive - surmount the obstacles
Become the essence of your goals - hereditary dream
Pray that you may attain that destiny
Fall into the coveted line where life is but a theme of pretense in
Lustrous guise
Claims and values, charts of means and status, plaques to show your strife
Do your neighbor clones approve?
Picture perfect illustration, imitation of life where the path is evened
Out
All obstructions removed
Great viable citizen, are you happy now?
Then praise your god and bow
Shimmering surface - the gleam of blinding lies
Become the product, the thing you so desire
To what length would you go to reach your goals?
What mantra will you use to justify your means?
Who will you betray to secure your dream?
What sins will you commit to avoid your sins be seen?
Do not look down Do not look down, or the abysmal beast of nonconformity might stare some
Unpleasant truth into your desensitized mind
Shimmering surface - the gleam of blinding lies
Become the product, the thing you so desire
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
long pal[2050][2050],l,r,ppal[2050],spal[2050];
long long ans;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;

for (int i=0;i<st.size();i++)
 pal[i][i]=1;
 for (int i=1;i<st.size();i++)
  if (st[i-1]==st[i])
   pal[i-1][i]=1;

for (int span=2;span<st.size();span++)
{
 for (int i=0;i+span<st.size();i++)
 {
  l=i;
  r=i+span;
  pal[l][r]=(pal[l+1][r-1]&(st[l]==st[r]));
 }
}

for (int i=0;i<st.size();i++)
 for (int j=i;j<st.size();j++) 
  ppal[j]+=pal[i][j],
  spal[i]+=pal[i][j];

for (int i=0;i<st.size();i++)
 for(int j=i+1;j<st.size();j++)
  ans+=ppal[i]*spal[j];

cout<<ans<<endl;

cin.get();cin.get();
return 0;}