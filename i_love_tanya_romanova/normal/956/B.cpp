/*
Right now  right here
We stand alone
Against pitiless indifference
We stand alone
Forever confounded by the broadening margins
Taken out of context and in to denial
Give in to ignorance and the world responds in kind
Put an end to the search and nullify this sense of life

Alone in silence
Yes I am frightened and so are you
Against pitiless indifference
We stand alone

Against the ever-coming night
So we step back to reveal a new perspective
When the allure of our gift has worn off
Not the least bit curious when giant steps are made
No going back
Our time is running out

Alone in silence
Yes I am frightened and so are you
Against pitiless indifference
We stand alone

Must we resort to "the end of all inquiry"
For this to make sense?
This to make sense
Right here  right now
We stand alone
Give up and recount them
The days of your life
Where truth was of essence
And time was alive
That is no incentive
To give in to the absurd
Reality and construct
Live forever to oppose
Forever opposed

Alone in silence
Yes I am frightened and so are you
Against pitiless indifference
We stand alone
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

int n,U,ar[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>U;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}

	double ans=-1e9;

	int ptr=1;
	for(int i=1;i<=n;i++){
		while (ptr+1<=n&&ar[ptr+1]-ar[i]<=U)
			++ptr;
		if (ptr>i+1){
			double hereA=ar[ptr]-ar[i+1];
			double hereB=ar[ptr]-ar[i];
			ans=max(ans,hereA/hereB);
		}
	}

	if (ans<-1){
		cout<<-1<<endl;
	}
	else{
		cout.precision(12);
		cout<<fixed<<ans<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}