/*
In the shadow of the moon,
She danced in the starlight
Whispering a haunting tune
To the night...
Velvet skirts spun 'round and 'round
Fire in her stare
In the woods without a sound
No one cared...
Through the darkened fields entranced,
Music made her poor heart dance,
Thinking of a lost romance...
Long ago...
Feeling lonely, feeling sad,
She cried in the moonlight.
Driven by a world gone mad
She took flight...
"Feel no sorrow, feel no pain,
Feel no hurt, there's nothing gained...
Only love will then remain,"
She would say.
Shadow of the Moon...
Shadow of the Moon...
Shadow of the Moon...
Shadow of the Moon...

Through the darkened fields entranced,
Music made her poor heart dance,
Thinking of a lost romance...
Long ago...

Somewhere just beyond the mist
Spirits were seen flying
As the lightning led her way
Through the dark...

In the shadow of the moon,
She danced in the starlight
Whispering a haunting tune
To the night...

Shadow of the Moon...
Shadow of the Moon...
Shadow of the Moon...
Shadow of the Moon...
Shadow of the Moon...
Shadow of the Moon...
Shadow of the Moon...
Shadow of the Moon...
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
const int N = 501031;

int n,a[N],b[N];
vector<pair<int,int> > v1,v2;
int ans[N];

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
		cin>>a[i];
		v1.push_back(make_pair(a[i],i));
	}
	for (int i=1;i<=n;i++)
	{
		cin>>b[i];
		v2.push_back(make_pair(b[i],i));
	}

	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	reverse(v1.begin(),v1.end());
	for (int i=0;i<v1.size();i++)
	{
		ans[v2[i].second]=v1[i].second;
	}

	for (int i=1;i<=n;i++)
	{
		if (i>1)
			cout<<" ";
		cout<<a[ans[i]];
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}