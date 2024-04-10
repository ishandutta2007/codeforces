/*
And I know
That it's true
All the fire
Has burned thru
Well you know I've played
So hard
And the light
Grows so dim
And my time's getting slim
All the words
Just don't mean much

And I know I'm saying
Goodbye
And I know that I'm going
Down
To die

In my heart
There's a wind
And it swirls up a din
It's so loud
It drowns my mind
Till the coin that I pass
To the ferryman's grasp
Let's me leave
My pain
Behind

So I part
And I'm oh so cold
And I hope to release
My heart
Better leave
While my song still calls
It's the truth
That I'm going
Down
To die
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 610031;

int tests;
string st;
vector<int> order;
vector<int> solution;
int have[N];

void make_answer(vector<int> solution){
	string ans="";
	for (int i=0;i<solution.size();i++){
		for (int j=0;j<have[solution[i]];j++){
			ans+=char(solution[i]+'a');
		}
	}
	cout<<ans<<endl;
}

void greedy(){
	solution.clear();
	for (int i=0;i<order.size();i+=2){
		solution.push_back(order[i]);
	}
	for (int i=1;i<order.size();i+=2){
		solution.push_back(order[i]);
	}
	make_answer(solution);
}

bool valid(vector<int> v){
	for (int i=1;i<v.size();i++)
		if (abs(v[i]-v[i-1])==1)
			return false;
	return true;
}

void try_all_permutations(){
	int found=0;
	do{
		if (valid(order))
		{
			make_answer(order);
			found=1;
			break;
		}
	}while (next_permutation(order.begin(),order.end()));
	if (found==0){
		cout<<"No answer"<<endl;
	}
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>st;
    	for (int i=0;i<26;i++){
    		have[i]=0;
    	}
    	for (int i=0;i<st.size();i++){
    		int id=st[i]-'a';
    		have[id]++;
    	}
    	order.clear();

    	for (int i=0;i<26;i++){
    		if (have[i]){
    			order.push_back(i);
    		}
    	}
    	if (order.size()<=6){
    		try_all_permutations();
    	}
    	else
    	{
    		greedy();
    	}
    }

//    cin.get(); cin.get();
    return 0;
}