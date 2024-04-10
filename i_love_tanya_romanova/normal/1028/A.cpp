/*
The lunatic is on the grass
The lunatic is on the grass
Remembering games and daisy chains and laughs
Got to keep the loonies on the path

The lunatic is in the hall
The lunatics are in my hall
The paper holds their folded faces to the floor
And every day the paper boy brings more

And if the dam breaks open many years too soon
And if there is no room upon the hill
And if your head explodes with dark forebodings too
I'll see you on the dark side of the moon

The lunatic is in my head
The lunatic is in my head
You raise the blade, you make the change
You re-arrange me 'til I'm sane

You lock the door and throw away the key
There's someone in my head but it's not me.

And if the cloud bursts thunder in your ear
You shout and no one seems to hear
And if the band you're in starts playing different tunes
I'll see you on the dark side of the moon

I can't think of anything to say except...
I think it's marvelous! Ha, ha, ha!
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

const int N = 600031;

int n,m,minx,maxx,miny,maxy;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	minx=1e9;
	maxx=-1e9;
	miny=1e9;
	maxy=-1e9;

	for (int i=1;i<=n;i++){
		string st;
		cin>>st;
		for (int j=1;j<=m;j++){
			if (st[j-1]=='B'){
				minx=min(minx,i);
				maxx=max(maxx,i);
				miny=min(miny,j);
				maxy=max(maxy,j);
			}
		}
	}

	cout<<(minx+maxx)/2<<" "<<(miny+maxy)/2<<endl;

//	cin.get(); cin.get();
	return 0;
}