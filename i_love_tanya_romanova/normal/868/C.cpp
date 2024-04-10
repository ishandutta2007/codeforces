/*
A thousand tears, tears in my eyes
Tears from my heart, from down deep inside
For now you are to fly, to fly far away
Fly to heaven's land, to where the angels stay

And the night will even hide, hide those ravens that fly

Angel wings, takes you ashore
Angel heart, it opens the door
On your path, all evil has fied
Don't be afraid of what lies ahead
Angel wings, takes you away
To heaven, where the other angels stay
Tired wings, but still far to fly
To heaven, to paradise...

The empty sky, is dark this night
Besides one star, that seems to shine so bright
And soon my love, my dearest friend
In heaven's land, we shall meet again...

And the night will even hide, hide those ravens that fly

Angel wings, takes you ashore
Angel heart, it opens the door
On your path, all evil has fied
Don't be afraid of what lies ahead
Angel wings, takes you away
To heaven, where the other angels stay
Tired wings, but still far to fly
To heaven, to paradise...
*/

//#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int n,k,ans,cnt[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k;
	for (int i=0;i<n;i++){
		int here=0;
		for (int j=0;j<k;j++){
			int val;
			cin>>val;
			here=here*2+val;
		}
		cnt[here]++;
	}

	if (cnt[0]>0)
		ans=1;
	for (int i=0;i<(1<<k);i++){
		for (int j=0;j<(1<<k);j++){
			if (cnt[i]==0||cnt[j]==0)
				continue;
			if (i==j&&cnt[i]<2)
				continue;
			if (i&j)
				continue;
			ans=1;
		}
	}

	if (ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	cin.get(); cin.get();
	return 0;
}