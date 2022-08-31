/*
My dream, it seems, fails to see the mornings
My one and only aim
I hear you breathe, I'm not alone in the darkness
I feel something on my lips I should not

One, too many poison kisses
And I'm drowning in your deepest see
I found my destiny, something I'm here for
I'm knocking on my heaven's door

One day we will run out of tomorrows
And yesterday's become the stuff our dreams are made of

Until today, I lived in the shadow world
Now heart is speaking, brain's defeated
Independent thought deleted...

One too many poisoned kisses...
And I'm drowning in your deepest sea
I found my destiny, something I'm here for...
I'm knockin' on my heaven's door.

And the map to find my sleeping wishes
Is hidden where I cannot see
When I'm awake, I need your poison kisses
To fall back in a living dream...

"Why do you fear to long for my love, please be strong.
If your heart can hear a song, you can't go wrong...
So repose your trust in me, save this love, live and see
If the life beyond this dream is what you seek..."

"Fill your deepest wishes,
Come take my poison kisses
Life is too short, this golden hour lasts for a lifetime..."

Give me your poison kiss,
Now, come night, I need my sleeping wish
Help me dream again, somehow kiss me now

With your poisoned lips
Oh, come night, I want my missing wish
Help me get one kiss, somehow
Hold me now

No dream can heal a broken heart...
When we're apart...

...On the sea of wishes
My dream that no one misses
Tears me apart, always, somehow
Goodbye love...
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

long n,ar[200000],op;
stack<long> st;
long t;
vector<pair<long, long> > ans;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];

for (int i=1;i<=n+1;i++)
{
    if (ar[i]>op)
    {
                 while (op<ar[i])
                 {
                  st.push(i);++op;
                 }
    }
    else
    while (ar[i]<op)
    {
          t=st.top();st.pop();--op;
          ans.push_back(make_pair(t,i-1));
    }
}
cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
cout<<ans[i].first<<" "<<ans[i].second<<endl;

cin.get();cin.get();
return 0;}