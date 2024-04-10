/*
We belong to the world we belong to the wind
We are the spirit of the competition's end
Turning hours into days burning muscles feel the pain
The heart and soul of discipline my friends

We are sending you a challenge it's very clear
We came to win that is why we are here
Demanding to be tested, tested by the best
Not to be forgotten like all the rest

The time has come all the training done
The muscle and the blood will come to pay

Let the game begin hear the starting gun
Play from the heart today we will overcome
When the game is over all the counting's done
We were born to win number 1

Today is the day all the training through
We have come for the number one not the number two
Let the contest begin play hard fight to win
Immortality victory and fame

The time has come all the training done
The muscle and the blood will come to pay

Let the game begin hear the starting gun
Play from the heart today we will overcome
When the game is over all the counting's done
We were born to win number 1

Today is the day all the training through
We have come for the number one not the number two
Let the contest begin play hard fight to win
Immortality victory and fame

Let the game begin hear the starting gun
Play from the heart today we will overcome
When the game is over all the counting's done
We were born to win number 1
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 610031;

int n,m,a[531][531],b[531][531];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

	scanf("%d",&n);
	scanf("%d",&m);

	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}

	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>b[i][j];
		}
	}

	int shit=0;

	for (int r=1;r<=n;r++){
		int cnt=0;
		for(int j=1;j<=m;j++){
			if (a[r][j]!=b[r][j])
				cnt++;
		}
		if (cnt%2)
			shit=1;
	}

	for (int c=1;c<=m;c++){
		int cnt=0;
		for (int i=1;i<=n;i++){
			if (a[i][c]!=b[i][c])
				cnt++;
		}
		if (cnt%2)
			shit=1;
	}

	if (shit)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;

//    cin.get(); cin.get();
    return 0;
}