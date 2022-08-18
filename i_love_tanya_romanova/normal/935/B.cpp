/*
I'm living in this line
I know my place, could think of no way

Of edging along in a loser's race
The line was moving slowly
Day by night
Everybody's shuffling on to keep a place in the line

Nine long years I've been in line
Getting nowhere there is no reason
For this line I don't care.
Everybody's standing in the burning sun
Everybody's shuffling on keeping a place in the line

Don't you think we're gonna make it
We've got a place in line
We're gonna make it some time
Somehow
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

const int N = 400031;

string st;
int last;
int x,ans,y;

int eval(){
	if (x>y)
		return 1;
	if (x<y)
		return -1;
	return 0;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>st;
	cin>>st;
	last=0;
	for (int i=0;i<st.size();i++){
		if (st[i]=='U')
			++x;
		else
			++y;
		int cur=eval();
		if (cur!=last&&last!=0&&cur!=0)
			ans++;
		//cout<<cur<<"@"<<endl;
		if (cur!=0)
			last=cur;
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}