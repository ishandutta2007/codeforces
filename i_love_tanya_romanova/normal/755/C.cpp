/*
Creepy crawl
On concrete and dust
Asphalt jungle
Piles of crust

Non sense thoughts
Inside the mind
What really means
What I want?

Open up your mind
And go your own way
Open up your mind
And go your own way
Open up your mind
And go your own way
Open up your mind
And go your own way

Straight old thoughts
To force you down
Raping rape
Breed apart

Open up your mind
And go your own way
Open up your mind
And go your own way
Open up your mind
And go your own way

Open up your mind
And go your own way
Open up your mind
And go your own way
Open up your mind
And go your own way
Open up your mind
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n,ar[N];
int ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}

	for (int i=1;i<=n;i++)
	{
		if (ar[ar[i]]==i&&ar[i]>=i)
			++ans;
	}

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}