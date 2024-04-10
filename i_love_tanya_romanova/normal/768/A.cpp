/*
Let me see the sunshine
Let me feel the rain
Let me go where I want to go
I want to smell the flowers
See the dawn again
Find those friends I used to know
Find those friends I used to know

Well I spent twenty long years
In a dirty old prison cell
I never saw the light of day
If you could understand oh
That kind of living hell
That's the price I have to pay Oh Yeah
That's the price I have to pay Oh Yeah, oh oh

They said I killed a man
But I never told them why
So you can guess what I've been through
So for twenty long years
I've been thinking of that other guy
And what I saw him do to you
What I saw him do to you

Listen here
So if tomorrow comes
And I walk outside that door
Try to understand the strain
But if you smile that smile
I know I couldn't ask for more
I know I'd do it all again
Yes I would
I know I'd do it all again
Yeah yeah yeah yeah oh yeah
Do it all again
Do it all again
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int ans,ar[N],n;

int main(){
//	freopen("japanese.in","r",stdin);
//	freopen("japanese.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	sort(ar,ar+n);
	for (int i=0;i<n;i++)
	{
		if (ar[i]!=ar[0]&&ar[i]!=ar[n-1])
			++ans;
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}