/*
We too feel alone

That place in my mind
Is that space that you call mine
That place in my mind
Is that space that you call mine

Where have I been all this time?
Lost enslaved fatal decline
I've been waiting for this to unfold (Good)
The pieces are only as good as the whole

Severed myself from my whole life
Cut out the only thing that was right
What If I never saw you again
I'd die right next to you in the end

That place in my mind
Is that space that you call mine
That place in my mind
Is that space that you call mine

I won't let you walk away
Without hearing what I have to say
Without hearing what I have to say
Without hearing what I have to say
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

const int N = 210031;

int n,m,a[N],b[N];
vector<int> candies[N];

int time_to(int a,int b){ // from a to b
	if (b>=a)
		return b-a;
	return b-a+n;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m;
    for (int i=1;i<=m;i++){
    	cin>>a[i]>>b[i];
    	--a[i];
    	--b[i];
    	candies[a[i]].push_back(i);
    }

    for (int start=0;start<n;start++){
    	int ans=0;
    	for (int i=0;i<n;i++){
    		int times_visit_this=candies[i].size();
    		if (times_visit_this==0)
    			continue;
    		int best=1e9;
    		int path_len=time_to(start,i)+n*(times_visit_this-1);
    		for (int j=0;j<candies[i].size();j++){
    			int id=candies[i][j];
    			int to=b[id];
    			int here=path_len+time_to(i,to);
    			best=min(best,here);
    		}
    		ans=max(ans,best);
    	}
    	if (start)
    		cout<<" ";
    	cout<<ans;
    }
    cout<<endl;


//    cin.get(); cin.get();
    return 0;
}