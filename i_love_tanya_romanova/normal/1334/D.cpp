/*
All the time friends of mine
Compliment me
All day long nothing's wrong
Just to please me
What the Hell, let them say
They above me
A two-faced lie can't be true
It all bores me
Friends of mine say I'm fine -
Don't believe them
Friend's of mine, they don't know
My suspicion
Push on in, stand up close
While I'm winning
Get a share, an empty stare -
Thanks, I'm leavin'
Friends of mine
Rule the world
Friends of mine
Ruin the world
But it's true, I don't know
Who's beside me
I look around, see my friends
Do they see me
I can't count on one or two
When I'm lovely
But the rest, their interest:
Big time money
Friends of mine
Take good care
Friends of mine
Better watch out
Watch yourselves
Friends of mine, I don't know
Who's beside me
I look around, see my friends
Do they see me
I can't count on one or two
When I'm lovely
But the rest, their interest:
Big time money
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 500031;

int tests;
long long n,l,r,cur_start;

vector<int> ans;

int block_size(int start,int finish){
	return 2*(finish-start);
}
int get_id(int cur_start,int cur_end,int ps){
	if (ps%2==1){
		return cur_start;
	}
	int full=ps/2;
	return cur_start+full;
}

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", sttextdout);
	ios_base::sync_with_stdio(0);
	// cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		cin>>n>>l>>r;
		int cur_start=1;

		ans.clear();

		int flag=0;

		if (r==1ll*n*(n-1)+1){
			flag=1;
			--r;
		}
		while (l<=r){
			//cout<<l<<" "<<r<<" "<<cur_start<<endl;
			//cin.get();
			if (l>block_size(cur_start,n)){
				l-=block_size(cur_start,n);
				r-=block_size(cur_start,n);
				cur_start++;
				continue;
			}
			int id=get_id(cur_start,n,l);
			ans.push_back(id);
			l++;
		}
		if (flag)
			ans.push_back(1);
		for (int i=0;i<ans.size();i++){
			if (i)
				cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}

	// cin.get(); cin.get();
	return 0;
}