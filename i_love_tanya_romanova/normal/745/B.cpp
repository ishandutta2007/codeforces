/*
When you are old enough to read these words
Their meaning will unfold
These words are all that's left
And though we've never met, my only son
I hope you know
That I would have been there to watch you grow
But my call was heard and I did go
Now your mission lies ahead of you
As it did my so long ago
To help the helpless ones who all look up to you
And to defend them to the end

Defender

Ride like the wind
Fight proud, my son
You're the defender
God has sent

Father,father,father
I look up to you and heed thy call

This letter ends my search
I'll live your dream now passed on to me
And I now wait to shake the hand of fate
Like the dusk awaiting dawn
So wizards cast your spell
With no heart to do me well
So it is written, it shall be

Defender

Ride like the wind
Fight proud, my son
You're the defender
God has sent
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
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 500031;

int n,m,cntx,maxx,minx,maxy,miny;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	cntx=0;
	minx=1e9;
	maxx=-1e9;
	miny=1e9;
	maxy=-1e9;

	for (int i=0;i<n;i++)
	{
		string st;
		cin>>st;
		for (int j=0;j<m;j++)
		{
			if (st[j]=='.')
				continue;
			minx=min(minx,i);
			maxx=max(maxx,i);
			miny=min(miny,j);
			maxy=max(maxy,j);
			cntx++;
		}
	}

	if (cntx==(maxx-minx+1)*(maxy-miny+1))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;


	cin.get(); cin.get();
	return 0;
}