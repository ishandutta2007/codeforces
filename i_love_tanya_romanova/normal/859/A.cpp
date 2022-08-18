/*
The long lost winter, acceptance woes
A lasting slumber, a sickness flows
The last of summer, the longing rivers froze
A grasping hunger, as darkness grows

Feeling so alive in this hopeless dream
Feeling so alive in this hopeless dream

We're the ones who pay with honour
Your pain rejected, your holy symbols inane
Your honour remains infected again

The frost of winter, acceptance shows
A grasping hunger, as fever grows
At last the summer, the longing rivers flow
A lasting thunder, as darkness grows

Feeling so alive in this hopeless dream
Feeling so alive in this hopeless dream

We're the ones who pay with honour
A malediction, your holy symbols inane
Will honour remain rejected again?
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

const int N = 500031;

int n,mx;
int ans;

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
		int val;
		cin>>val;
		mx=max(mx,val);
	}
	ans=mx-25;
	if (ans<0)
		ans=0;

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}