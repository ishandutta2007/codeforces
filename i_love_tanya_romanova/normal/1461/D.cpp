/*
We know all the words of power,
All about the witching hour,
We know the reason why you're scared,
And here comes your nightmare.

Over your shoulder honey, you don't wanna turn around,
Bring the night closer, we are gonna bring you down,
It's the times that we live in, erosion of the mind,
Easy to be cruel, Hard to be kind.

When the mode of music changes,
The walls around the city shakes,
Look into the face of danger,
We know how to make you break.

Over your shoulder honey, right behind your back,
Make you a true believer, maybe give you heart attack
We are what you made us, see what we can find,
Easy to be cruel, Hard to be kind.

We can't help the way we feel,
We don't want to make a deal,
Look out, honey, use your head,
Might be murder in your bed.

Over your shuolder honey, the face still shines,
Nobody you recognize, isn't yours, isn't mine,
See the mouth smiling, make the words rhyme,
Easy to be cruel, Hard to be kind.
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

const int bs = 1000000007;

const int N = 600031;

int tests;
int n,q;
vector<int> order;
set<long long> reachable;
int ar[N];

void backtrack(vector<int> v){
	vector<int> l,r;
	int mi=v[0];
	int ma=v[0];
	for (int i=0;i<v.size();i++){
		if (v[i]<mi)
			mi=v[i];
		if (v[i]>ma)
			ma=v[i];
	}

	long long cur_S=0;

	for (int i=0;i<v.size();i++){
		cur_S+=v[i];
	}
	reachable.insert(cur_S);

	int mid=(ma+mi)/2;

	for (int i=0;i<v.size();i++){
		if (v[i]<=mid)
			l.push_back(v[i]);
		else
			r.push_back(v[i]);
	}
	if (l.size()==0||r.size()==0)
		return;
	backtrack(l);
	backtrack(r);
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>q;
    	order.clear();
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    		order.push_back(ar[i]);
    	}
    	reachable.clear();
    	backtrack(order);
    	for (;q;--q){
    		long long val;
    		cin>>val;
    		if (reachable.find(val)!=reachable.end()){
    			cout<<"Yes"<<"\n";
    		}
    		else
    		{
    			cout<<"No"<<"\n";
    		}
    	}
    }

    //cin.get(); cin.get();
    return 0;
}