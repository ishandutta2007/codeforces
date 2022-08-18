/*
Unknown man
Speaks to the world
Sucking your trust
A trap in every world

War for territory
War for territory

Choice control
Behind propaganda
Poor information
To manage your anger

War for territory
War for territory

Dictators' speech
Blasting off your life
Rule to kill the urge
Dumb assholes' speech

Years of fighting
Teaching my son
To believe in that man
Racist human being
Racist ground will live
Shame and regret
Of the pride
You've once possessed

War for territory
War for territory
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

int n,XF,YF,a,b;
int used[1031][1031];

bool outside(int a,int b){
	return (a<1||a>n||b<1||b>n);
}

bool check(int a,int b){
	if (a==XF||b==YF||a+b==XF+YF||a-b==XF-YF)
		return true;
	return false;
}

void dfs(int a,int b){
	if (outside(a,b))
		return ;
	if (used[a][b])
		return;
	if (check(a,b))
		return;
	used[a][b]=1;
	for (int dx=-1;dx<=1;dx++){
		for (int dy=-1;dy<=1;dy++){
			dfs(a+dx,b+dy);
		}
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	cin>>XF>>YF;

	cin>>a>>b;
	dfs(a,b);

	cin>>a>>b;
	if (used[a][b])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

//	cin.get(); cin.get();
	return 0;
}