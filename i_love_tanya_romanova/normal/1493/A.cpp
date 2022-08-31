/*
Stumbling through narrow paths.
Afraid of what will come next.
As the darkness closes in
I start to run.
What have I done to deserve
This never-ending hunt?
I will never be able to return home.
My existence is shattered.

As I stop to gasp for air, I wonder...
Wonder when my final call might come.
And if it's really worth escaping from.
I'm so tired.

Between trees and stones.
On stale paths, beneath my reality.
It's like I lost the key to my mind.
I can no longer control myself.
No more running!
I will fight my demons right here.

As I stop to gasp for air, I wonder...
Wonder when my final call might come.
And if it's really worth escaping from.
I'm so tired.

Dear child, through horrors
and fright you will fade.
Fade to distant worlds
and distant lives.
As you lose your suffering,
there's nothing more to believe in.
Your belief to this day has been life.
Now my belief will fill your soul
fill your soul with death.

As I stop to gasp for air, I wonder...
Wonder when my final call might come.
And if it's really worth escaping from.
I'm so tired.

I no longer run,
I stand my ground and wait...

I wait...
*/

#pragma GCC optimize("Ofast")
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

const long long bs = 1000000007;

const int N = 200031;

int tests,n,k;
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>k;
    	ans.clear();
    	int lb=(k+1)/2;
    	for (int i=lb;i<=n;i++){
    		if (i!=k)
    			ans.push_back(i);
    	}
    	cout<<ans.size()<<endl;
    	for (int i=0;i<ans.size();i++){
    		if (i)
    			cout<<" ";
    		cout<<ans[i];
    	}
    	cout<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}