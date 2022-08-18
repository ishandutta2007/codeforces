/*
He could've tuned in, tuned in
But he tuned out
A bad time, nothing could save him
Alone in a corridor, waiting, locked out
He got up outta there, ran for hundreds of miles
He made it to the ocean, had a smoke in a tree
The wind rose up, set him down on his knee

A wave came crashing like a fist to the jaw
Delivered him wings, "Hey, look at me now"
Arms wide open with the sea as his floor
Oh, power, oh

He's.. flying
Whole
High.. wide, oh

He floated back down 'cause he wanted to share
His key to the locks on the chains he saw everywhere
But first he was stripped and then he was stabbed
By faceless men, well, fuckers
He still stands

And he still gives his love, he just gives it away
The love he receives is the love that is saved
And sometimes is seen a strange spot in the sky
A human being that was given to fly

High.. flying
Oh, oh
High.. flying
Oh, oh
He's flying
Oh, oh
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

const int N = 600031;

int n,rmost;
int ans;
set<int> S;
set<int>::iterator it;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	cout<<1;

	for (int i=1;i<=n;i++)
		S.insert(i);

	rmost=0;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		S.erase(x);
		if (i==n)
			ans=1;
		else{
			it=S.end();
			--it;
			rmost=(*it);
			ans=rmost-(n-i)+1;
		}
		cout<<" "<<ans;
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}