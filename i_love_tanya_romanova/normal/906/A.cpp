/*
I was spending my time in the doldrums
I was caught in the cauldron of hate
I felt persecuted and paralyzed
I thought that everything else would just wait
While you are wasting your time on your enemies
Engulfed in a fever of spite
Beyond your tunnel vision reality fades
Like shadows into the night

To martyr yourself to caution
Is not going to help at all
Because there'll be no safety in numbers
When the Right One walks out of the door

Can you see your days blighted by darkness?
Is it true you beat your fists on the floor?
Stuck in a world of isolation
While the ivy grows over the door

So I open my door to my enemies
And I ask could we wipe the slate clean
But they tell me to please go fuck myself
You know you just can't win
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

const int N = 510031;

string st[N];
int ans;
int n;
string trash;
int can_be[N];

bool unique_answer(){
	int cnt=0;
	for (int i=0;i<26;i++){
		if (can_be[i])
			++cnt;
	}
	return (cnt<2);
}

int is_presented[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	getline(cin,trash);

	for (int i=1;i<=n;i++){
		getline(cin,st[i]);
	}

	ans=st[n][2];

	int total_got=0;
	for (int i=1;i<n;i++){
		if (st[i][0]=='!'||st[i][0]=='?')
			++total_got;
	}
//	--total_got;

	int could_get=0;

	for (int i=0;i<26;i++){
		can_be[i]=1;
	}

	for (int i=1;i<n;i++){
		if (unique_answer())break;

		if (st[i][0]=='?'){
			int to=st[i][2]-'a';
			can_be[to]=0;
			++could_get;
		}

		for (int j=0;j<26;j++){
			is_presented[j]=0;
		}
		for (int j=2;j<st[i].size();j++){
			is_presented[st[i][j]-'a']=1;
		}


		if (st[i][0]=='!'){
			++could_get;
			for (int j=0;j<26;j++){
				if (is_presented[j]==0)
					can_be[j]=0;
			}
		}
		if (st[i][0]=='.'){
			for (int j=0;j<26;j++){
				if (is_presented[j]==1)
					can_be[j]=0;
			}
		}
	}

//	cout<<total_got<<" "<<could_get<<endl;

	cout<<total_got-could_get<<endl;

	cin.get(); cin.get();
	return 0;
}