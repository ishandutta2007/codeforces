/*
Here we go!

Dance with the devil inside of me
I'm longing for a second chance
And taste what seems to remind me
of all my skulls and skeletons

Live and let live
Die and let die
War and peace in my hand - my temptations
This war and peace inside will take me to the end

Hell awaits
its closing in on me
it strokes its hand down on my back
and no more mistakes
my intentions are finally clear from how I've always been

Live and let live
Die and let die
Live and let live
Die and let die
War and peace in my hand - my temptations
This war and peace inside wont end
War and peace in my hand, yah
This war and peace inside will take me to the end

War and peace in my hand - my temptations
This war and peace inside wont end
War and peace in my hand, yah
This war and peace inside my head will take me to the end
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

const int N = 410031;

int n,q,L[N],R[N];
vector<int> events[5031];

int ans;
int with1[N];
int C[5031*5031];
int RES;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>q;
    for (int i=1;i<=q;i++){
    	cin>>L[i]>>R[i];
    	for (int j=L[i];j<=R[i];j++){
    		if (events[j].size()<4)
    		   events[j].push_back(i);
    	}
    }

    for (int i=1;i<=n;i++){
    	if (events[i].size()==0){
    		continue;
    	}
    	ans++;
    	if (events[i].size()==1){
    		with1[events[i][0]]++;
    	}
    	if (events[i].size()==2){
    		sort(events[i].begin(),events[i].end());
    		int I=events[i][0]*5007+events[i][1];
    		C[I]++;
    	}
    }

    RES=0;

    for (int i=1;i<=q;i++){
    	for (int j=i+1;j<=q;j++){
    		int here=ans;
    		here-=with1[i];
    		here-=with1[j];
    		int id=i*5007+j;
    		here-=C[id];
    	/*	if (here==4){
    			cout<<i<<" "<<j<<endl;
    		}*/
    		RES=max(RES,here);
    	}
    }

    cout<<RES<<endl;

//    cin.get(); cin.get();
    return 0;
}