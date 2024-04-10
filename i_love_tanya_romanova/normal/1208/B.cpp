/*
I close both locks below the window
I close both blinds and turn away

Sometimes solutions aren't so simple
Sometimes goodbye's the only way

And the sun will set for you
The sun will set for you

And the shadow of the day
Will embrace the world in grey

And the sun will set for you

In cards and flowers on your window
Your friends all plead for you to stay

Sometimes beginnings aren't so simple
Sometimes goodbye's the only way

And the sun will set for you
The sun will set for you

And the shadow of the day
Will embrace the world in grey

And the sun will set for you

And the shadow of the day
Will embrace the world in grey

And the sun will set for you

And the shadow of the day
Will embrace the world in grey

And the sun will set for you
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

const int N = 200000;

int n,ar[N];
set<int> S;
int ans;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    int ans=n-1;

    for (int pref=0;pref<=n;pref++){
    	S.clear();
    	int shit=0;
    	for (int i=1;i<=pref;i++){
    		if (S.find(ar[i])!=S.end())
    			shit=1;
    		S.insert(ar[i]);
    	}
    	if (shit==0)
    		ans=min(ans,n-pref);
    	for (int j=n;j>pref;--j){
    		if (S.find(ar[j])!=S.end())
    			shit=1;
    		S.insert(ar[j]);
    		if (shit==0)
    			ans=min(ans,n-(pref+(n-j+1)));
    	}
    }
    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}