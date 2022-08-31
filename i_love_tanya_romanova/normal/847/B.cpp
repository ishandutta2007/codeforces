/*
In fields where nothing grew but weeds,
I found a flower at my feet,
Bending there in my direction,
I wrapped a hand around its stem,
I pulled until the roots gave in,
Finding there what I'd been missing,

But I know...
So I tell myself, I tell myself it's wrong.
There's a point we pass from which we can't return.
I felt the cold rain of the coming storm.

All because of you,
I haven't slept in so long.
When I do I dream of drowning in the ocean,
Longing for the shore where I can lay my head down,
I'll follow your voice,
All you have to do is shout it out.

Inside my hands these petals browned,
Dried up, fallen to the ground
But it was already too late now.
I pushed my fingers through the earth,
Returned this flower to the dirt,
So it could live. I walked away now.

But I know...
Not a day goes by that I don't feel this burn.
There's a point we pass from which we can't return.
I felt the cold rain of the coming storm.

All because of you,
I haven't slept in so long,
When I do I dream of drowning in the ocean,
Longing for the shore where I can lay my head down,
I'll follow your voice,
All you have to do is shout it out.

All because of you...
All because of you...

All because of you,
I haven't slept in so long.
When I do I dream of drowning in the ocean,
Longing for the shore where I can lay my head down,
Inside these arms of yours.

All because of you,
I believe in angels.
Not the kind with wings,
No, not the kind with halos,
The kind that bring you home,
When home becomes a strange place.
I'll follow your voice,
All you have to do is shout it out.
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n,ar[N];
set<pair<int,int> > S;
set<pair<int,int> > ::iterator it;
vector<int> ans[N];
int C;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}

	for (int i=1;i<=n;i++){
		it=S.lower_bound(make_pair(ar[i],0));
		if (it!=S.begin()){
			--it;
			pair<int,int> p=(*it);
//			cout<<p.first<<"@"<<p.second<<endl;
			S.erase(it);
			int id=p.second;
			ans[id].push_back(ar[i]);
			S.insert(make_pair(ar[i],id));
		}
		else
		{
			//cout<<"@"<<i<<endl;
			++C;
			ans[C].push_back(ar[i]);
			S.insert(make_pair(ar[i],C));
		}
	}

	for (int i=1;i<=C;i++)
	{
		for (int j=0;j<ans[i].size();j++)
		{
			if (j)
				cout<<" ";
			cout<<ans[i][j];
		}
		cout<<endl;
	}

	cin.get(); cin.get();
	return 0;
}