/*
You wouldn't take a taxi
You said you couldn't stay
You drink and drink and drive
Almost every day
Your life speeds through your mind
Faster than you drive
Living on a shoestring
All your fucking life
Your friends say you need help
You tell them that you're fine
As you tip the bottle
And swallow some cheap wine
You're a living time bomb
Waiting to explode
You'll just be a statistic
When you're dead and cold!

Every time you drink and drive
You always think that you'll survive
Till your car is crushed and bent
Impact is imminent
Sirens fill the streets aloud
It always draws the biggest crowd
They peel your body off cement
Impact is imminent!

The daily obituaries reveal
More and more fools climbed behind the wheel
Thinking they were sober enough to drive
They didn't know they'd never come back alive
A bad case of double vision
Led straight onto a head-on collision
Passed out and crossed the double line
How can anyone be so asinine?

Blind drunk and hauling ass
He got airborne off an overpass
He never knew he left the ground
Like a warhead target bound
You can't correct your fatal mistake
When you're the guest of honor at your own wake
Thought he could fly till he hit cement
Impact is imminent!

Drunken time bombs set to detonate
When happy hour's over they're off to celebrate
Their vision's but a blur, they barely see the road
Been drinking for so long they're starting to erode
A fucking drunken lush climbs into his car
Kills you in an instant coming from the bar
An alcoholic bum hits you from behind
A child and his mother run down in their prime!
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3

using namespace std;

long long n,q,m,a[300000],b[300000],ptr;
vector<long long> fa,fb,ans,v;
stack<pair<long long, long long> > st;
pair<long long, long long> p;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=0;i<n;i++)
{
    cin>>q;a[q]++;
}
for (int i=0;i<n;i++)
{cin>>q;b[q]++;}

/*sort(a,a+n);
sort(b,b+n);
*/
for (int i=0;i<m;i++)
{
  for (int j=0;j<a[i];j++)
  {
      st.push(make_pair(i,1));
  }
  for (int j=0;j<b[m-i-1];j++)
  {
      if (st.size()>0&&st.top().second==1)
      {
       ans.push_back((st.top().first+m-i-1+m*5)%m);
       st.pop();
      }
      else st.push(make_pair(m-i-1,2));
  }
}

while (st.size())
{
      p=st.top();st.pop();
      if (p.second==1)fa.push_back(p.first);
      else fb.push_back(p.first);
}
sort(fa.begin(),fa.end());
sort(fb.begin(),fb.end());
for (int i=0;i<fa.size();i++)
ans.push_back((fa[i]+fb[i]+m)%m);
sort(ans.begin(),ans.end());
reverse(ans.begin(),ans.end());

for(int i=0;i<ans.size();i++)
{
        if (i)cout<<" ";
        cout<<ans[i];
        }
        cout<<endl;
        
cin.get();cin.get();
return 0;}