/*
She seemed dressed in all of me, stretched across my shame.
All the torment and the pain
Leaked through and covered me
I'd do anything to have her to myself
Just to have her for myself
Now I don't know what to do, I don't know what to do when she makes me sad.

She is everything to me
The unrequited dream
A song that no one sings
The unattainable, Shes a myth that I have to believe in
All I need to make it real is one more reason
I don't know what to do, I don't know what to do when she makes me sad.

But I won't let this build up inside of me
I won't let this build up inside of me
I won't let this build up inside of me
I won't let this build up inside of me

A catch in my throat choke
Torn into pieces
I won't, no!
I don't wanna be this...

But I won't let this build up inside of me
I won't let this build up inside of me
I won't let this build up inside of me
I won't let this build up inside of me

She isn't real
I can't make her real
She isn't real
I can't make her real
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