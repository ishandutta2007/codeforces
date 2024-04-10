/*
Kill for gain or shoot to maim
But we don't need a reason
The Golden Goose is on the loose
And never out of season
Blackened pride still burns inside
This shell of bloody treason
Here's my gun for a barrel of fun
For the love of living death

The killer's breed or the Demon's seed,
The glamour, the fortune, the pain,
Go to war again, blood is freedom's stain
Don't you pray for my soul anymore?

2 minutes to midnight,
The hands that threaten doom.
2 minutes to midnight,
To kill the unborn in the womb.

The blind men shout "Let the creatures out
We'll show the unbelievers."
The napalm screams of human flames
Of a prime time Belsen feast ... yeah!
As the reasons for the carnage cut their meat and lick the gravy
We oil the jaws of the war machine and feed it with our babies.

The killer's breed or the Demon's seed,
The glamour, the fortune, the pain,
Go to war again, blood is freedom's stain
Don't you pray for my soul anymore.

2 minutes to midnight,
The hands that threaten doom.
2 minutes to midnight,
To kill the unborn in the womb.

The body bags and little rags of children torn in two
And the jellied brains of those who remain to put the finger right on you
As the madmen play on words and make us all dance to their song
To the tune of starving millions to make a better kind of gun.

The killer's breed or the Demon's seed,
The glamour, the fortune, the pain,
Go to war again, blood is freedom's stain
Don't you pray for my soul anymore.

2 minutes to midnight,
The hands that threaten doom.
2 minutes to midnight,
To kill the unborn in the womb.

Midnight
Midnight
Midnight
It's all night

Midnight
Midnight
Midnight
It's all night
*/

#pragma GCC optimize("O3")
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
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600000;

int n;
int x;
vector<pair<int,int> > order;
long long ans[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x;
		order.push_back(make_pair(x,1));
	}
	for (int i=1;i<=n;i++){
		cin>>x;
		order.push_back(make_pair(x,0));
	}

	sort(order.begin(),order.end());

	reverse(order.begin(),order.end());

	for (int i=0;i<order.size();i++){
//		cout<<orer[i].first<<" "<<order[i].second<<endl;
		if (i%2!=order[i].second)
			ans[order[i].second]+=order[i].first;
	}

	cout<<ans[1]-ans[0]<<endl;

//	cin.get(); cin.get();
	return 0;
}