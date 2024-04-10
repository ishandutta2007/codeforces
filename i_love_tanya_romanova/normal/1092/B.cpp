/*
Myth or legend
Nymph tale washed ashore
Near the kraken sleepeth stirs coral and bone
Infinite city
No sexy sneer
Hideous creation
Human and animal
Banter songs of rudeness to be adhered
Not on rocks that glisten
Harps to listen
Comb hair
Tear right to pieces
Left to recess a watery grave
Sensing the blood of prey
Swimming in fear for life
Rolling over
Falling into jaws
Teeth that chatter
It distracts them all
The Fiji mermaid
She will let it know
Time is coming to feed and knaw
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

const int N = 200031;

int n,ar[N],ans;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

	cin>>n;

	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	sort(ar,ar+n);
	for (int i=0;i<n;i+=2){
		ans+=ar[i+1]-ar[i];
	}
	cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}