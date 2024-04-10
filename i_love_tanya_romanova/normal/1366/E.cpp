/*
Now, I'm losing my mind
I'm losing the grip
I'm burning inside

Now, the edge of the knife
I'm walking the line
They come from behind

Now, face the demons
Fight the demons
Fight 'til I die

Now, I'm selling my soul
I'm out of control
Where will I go?

Not, not losing the edge...
Not, not losing the edge...

Forgive them father for they don't know what they do
Protect me father, but I must go to face this horror alone
This is divine I feel alive, I have a reason to fight
But on the edge do not look down, they're all around

Not, not losing the edge...
Not, not losing the edge...

They come from behind, they coming from behind
Hiding in the dark, they're hiding in the dark
They are all around, they are all around
Rising underground, rising underground
They're everywhere, they aren't prepared
Crawling on the edge, crawling on the edge
Leaning on the ledge, leaning on the ledge
C'mon motherfuckers! I ain't coming back
Never, never, never, never!

Now is the end, the end of the line, the end of all life
The age of distrust corruption is rust, spiral downward in dust
Control your feeling, control your temper, lock them down deep inside
Unleash fear, release the demon, a plague mankind

Not, not losing the edge...
Not, not losing the edge...
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 200031;

int n,m,ar[N],b[N];
map<int,int> last_entry;
vector<pair<int,int> > order;
long long ans;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n>>m;
  for (int i=1;i<=n;i++){
	  cin>>ar[i];
	  last_entry[ar[i]]=i;
	  order.push_back(make_pair(ar[i],i));
  }

  sort(order.begin(),order.end());

  for (int i=1;i<=m;i++){
	  cin>>b[i];
  }

  int must_cut=0;

  long long ans=1;

  int ptr=0;

  for (int i=1;i<=m;i++){
	 while (ptr<order.size()&&order[ptr].first<b[i]){
		 must_cut=max(must_cut,order[ptr].second);
		 ++ptr;
	 }
	 if (last_entry.find(b[i])==last_entry.end())
		 ans=0;
	 int bfr=last_entry[b[i]];
	 if (bfr<=must_cut)
		 ans=0;
	// cout<<bfr<<" "<<must_cut<<endl;

	 if (i>1)
		 ans=ans*1ll*(bfr-must_cut)%bs;
	 if (i==1&&must_cut>0)
		 ans=0;
  }

  cout<<ans<<endl;

  cin.get(); cin.get();
  return 0;
}