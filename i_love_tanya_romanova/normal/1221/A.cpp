/*
On hymns of battle we rode to glory
Hail england did we
By the sign of the hammer
We fought the world
Kings of metal to be
Louder than hell
Warriors of the world
Now gods of war
Stand our ground knights immortal
For metal once more
Hail kill and die
On this ground for death and glory
Are all who believe
Blood and steel bound together
In a fight to be free
We will arm the just
And grind to dust
Those who deny
Our sacred right
Of glory and might
We shall survive
Hail kill and die
Hail kill and die
Dark avengers armed with hatred
Black arrows and wings
By the hammer of thor
A holy war
For the crown and the ring
We ride the dragon and wield the power
To fight til we die
Sons of odin stand so tall
We all touch the sky
Hail kill and die
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

const int N = 200031;

int tests;
int n;

bool solve(vector<int> v){
	while (true){
		sort(v.begin(),v.end());
		int ok=0;
		int ps=-1;
		for (int i=0;i<v.size();i++){
			if (v[i]==2048)
				return true;
			if (i>0&&v[i]==v[i-1]){
				ps=i;
			}
		}
		if (ps==-1)
			return false;
		vector<int> v2;
		for (int i=0;i<v.size();i++){
			if (i==ps-1)
				continue;
			if (i==ps)
				v2.push_back(v[i]*2);
			else
				v2.push_back(v[i]);
		}
		v=v2;
	}
	return false;
}
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
    	vector<int> v;
    	for (;n;--n){
    		int val;
    		cin>>val;
    		v.push_back(val);
    	}
    	if (solve(v)){
    		cout<<"YES"<<endl;
    	}
    	else
    	{
    		cout<<"NO"<<endl;
    	}
    }

//    cin.get(); cin.get();
    return 0;
}