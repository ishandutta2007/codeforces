/*
Get on the snakes
With a swarm of motor flys
Get on the snakes
Under the Cola xolored sky

Don't worry, everything's clean
Road worthy, hungry and mean

Get on the snakes
Where the metal river bleeds
Get on the snake
Where you never will believe
Hey baby, what's your disease
My heart's bleeding
I'm dying to leave

Get on the snake
Where the water turns to steam
Get on the snake
With a suicide machine

Don't worry, everything's clean
Road worthy, hungry and mean
Hungry and mean...
Hungry and mean...
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

int n,x;
vector<int> ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>x;

	if (n==2&&x==0){
		cout<<"NO"<<endl;
		return 0;
	}

	int bd=n;
	if (n%2)
		bd-=1;
	else
		bd-=2;

	int res=0;

	for (int i=1;i<=bd;i++){
		res^=(800000+i);
		ans.push_back(800000+i);
		if (res==x&&i==bd){
			ans.pop_back();
			res^=(800000+i);
			ans.push_back(800000+i+1);
			res^=(800000+i+1);
		}
	}

	if (bd==n-2)
		ans.push_back(0);
	ans.push_back(res^x);

	cout<<"YES"<<endl;
	for (int i=0;i<ans.size();i++)
	{
		if (i)
			cout<<" ";
		cout<<ans[i];
	}

	cin.get(); cin.get();
	return 0;
}