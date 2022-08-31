/*
Time to run, yea
Time to hide
Holy war in the land of fire
Never tempt the
Wrath of gods
Gonna dance in the death of life
Take the hand
Enter the world
Just remember you will surely die
Never sell
Evil for lies
Gonna give to you the kiss of life

Serpents of the lord
Crawling
To the will of god
Serpents of your lord
Crawling
All evil

Serpent Jesus
Snake of Christ
Nailed to a cross
Of a holy design
Blood to water
Water to wine
Whip the soul 'til a mother cries
Bring it down, baby
Pierce the side
Start the legend with a funeral rite
Serpent Jesus
Snake of Christ
Gonna build you
A world of lies

(Serpents of the lord) Serpents of the lord
Crawling
To the will of god
(Serpents of the lord) Serpents of your lord
Crawling
All evil

Oh yea
Oh yea
Oh yea
Crawling

Serpent Jesus
Snake of Christ
Nailed to a cross
Of a holy design
Blood to water
Water to wine
Whip the soul 'til a mother cries
Bring it down, baby
Pierce the side
Start the legend with a funeral rite
Serpent Jesus
Snake of Christ
Gonna build you
World of lies

(Serpents of the lord) Serpents of the lord
Crawling
To the will of god
(Serpents of the lord) Serpents of the lord
Crawling
All evil, yea
Yea
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

vector<int> v;

int n,z,val;

bool valid(int x){
	for (int i=0;i<x;i++){
		if (v[i]+z>v[v.size()-x+i])
			return false;
	}
	return true;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>z;
    for (int i=1;i<=n;i++){
    	cin>>val;
    	v.push_back(val);
    }

    sort(v.begin(),v.end());
    int l,r;
    l=0;
    r=v.size()/2;
    while (l<r)
    {
    	int mid=l+r+1;
    	mid/=2;
    	if (valid(mid))
    		l=mid;
    	else
    		r=mid-1;
    }
    cout<<l<<endl;


//    cin.get(); cin.get();
    return 0;
}