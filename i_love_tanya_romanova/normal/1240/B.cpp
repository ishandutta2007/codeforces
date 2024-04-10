/*
It's way past midnight
There's a howling wind
Oh God what can it be?
Something out there evil
And it's coming straight for me
The house is dark and very cold
I know there's no one here
Why am I scared to death
Just petrified with fear

'Cause I'm shakin' and I'm thinkin'
Of something evil lurking
And waiting for me in the house
'Cause I'm shakin' and I'm thinkin'
Of something evil lurking
And waiting for me in the dark
The dark

When I opened up the door
And snapped on the switch
The room was filled with light
Then something black and very fast
Fled upon my sight
What I feared most as a child
Was the coming of the night
Now my horrors have become quite real
My nightmares breathe new life

'Cause I'm shakin' and I'm thinkin'
Of something evil lurking
And waiting for me in the house
Yes, I'm shakin' and I'm thinkin'
Of something evil lurking
And waiting for me in the dark
Dark!

What is it in the house
That the darkness brings to life?
I sense their eyes upon me
As I grab a butcher knife
Whatever it is that waits for me
It hides beneath my bed
If I try to sleep tonight
By morning I'll be dead!

'Cause I'm shakin' and I'm thinkin'
Of something evil lurking
And waiting for me in the house
Yes, I'm shakin' and I'm thinkin'
Of something evil lurking
And waiting for me in the dark
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
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 500031;

int tests;
set<int> S;
map<int,int> fi,la;
int n;
int a[N];
int bst,cur;
set<int>::iterator it;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	S.clear();
    	fi.clear();
    	la.clear();
    	for (int i=1;i<=n;i++){
    		cin>>a[i];
    		S.insert(a[i]);
    		if (fi.find(a[i])==fi.end())
    			fi[a[i]]=i;
    		la[a[i]]=i;
    	}

    	bst=0;
    	cur=0;
    	int cur_end=-1;
    	for (it=S.begin();it!=S.end();it++){
    		int val=(*it);
    		if (fi[val]<cur_end){
    			cur=0;
    		}
    		cur++;
    		bst=max(bst,cur);
    		cur_end=la[val];
    	}
    	cout<<(int)S.size()-bst<<endl;
    }

//    cin.get(); cin.get();
    return 0;
}