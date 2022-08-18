/*
Standing by my window, breathing summer breeze
Saw a figure floating, 'neath the willow tree
Asked us if we were happy, we said we didn't know
Took us by the hands and up we go

We followed the dreamer through the purple hazy clouds
He could control our sense of time
We thought we were lost but no matter how we tried
Everyone was in peace of mind

We felt the sensations drift inside our frames
Finding complete contentment there
And all the tensions that hurt us in the past
Just seemed to vanish in thin air

He said in the cosmos is a single sonic sound
That is vibrating constantly
And if we could grip and hold on to the note
We would see our minds were free...oh they're free

We are lost above
Floating way up high
If you think you can find a way
You can surely try
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
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 500031;

int tests,n,k;
string st;
vector<pair<int,int> > ans;

string construct(int len,int k){
	string ret;
	--k;
	for (int i=0;i<k;i++){
		ret+="()";
	}
	int ohead=len-2*k;
	for (int i=0;i<ohead/2;i++){
		ret+="(";
	}
	for (int i=0;i<ohead/2;i++){
		ret+=")";
	}
	return ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
  //  ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;

    for (;tests;--tests){
    	cin>>n>>k;
    	cin>>st;
    	string goal=construct(n,k);

    	ans.clear();

    	for (int i=0;i<goal.size();i++){
    		if (goal[i]!=st[i]){
    			int j=i+1;
    			while (goal[i]!=st[j])
    				++j;
    			ans.push_back(make_pair(i+1,j+1));
    			for (int q=i;q<=j;q++){
    				if (q<(j-(q-i)))
    					swap(st[q],st[j-(q-i)]);
    			}
    		}
    	}

    	cout<<ans.size()<<endl;
    	for (int i=0;i<ans.size();i++){
    		cout<<ans[i].first<<" "<<ans[i].second<<endl;
    	}
    }

//    cin.get(); cin.get();
    return 0;
}