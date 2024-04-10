/*
We all seem so meaningless within our lives
We all seem so meaningless within our truth
I wanted to be a part of me but now
We all want to be something
You all want to be something
But you're lost
We'll never take it back cause our souls are lost
Decreasing of the nation
We'll never have them back cause their souls are lost
Decreasing of the nation
Pocketful of empty promises
I know you know the way to drag us down in nothingness
Spending your time in raising the masterpiece of lies
That suits us fine
I wanted you to be part of me but now
We all want to be something
You all want to be something
We're lost
We'll never take it back cause our souls are lost
Decreasing of the nation
We'll never have them back cause their souls are lost
Decreasing of the nation
We'll never take it back
We're just a damn lost nation
It goes on and on
We are blind
Looking for an evolution
But now you're on the edge and you're about to fall down
We'll never take it back cause our souls are lost
Decreasing of the nation
We'll never have them back cause their souls are lost
Decreasing of the nation
We'll never take it back
We're just a damn lost nation
*/

#pragma comment(linker, "/STACK:16777216")
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
long k;
long sp,er,nend;
long ans;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
cin>>k;
for (int i=0;i<k;i++)
 st+='?';

for (int start=0;start<st.size();start++)
 for (int end=start;end<st.size();end++)
 {
  sp=end-start+1;
  nend=end+sp;
  if (nend>=st.size())continue;
  er=0;
  for (int i=start;i<=end;i++)
   if (st[i]!=st[end+i-start+1]&&st[end+i-start+1]!='?')er=1;
  if (er==0)ans=max(ans,sp);
 }
cout<<ans*2<<endl;

cin.get();cin.get();
return 0;}