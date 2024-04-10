/*
The sun no longer shines as bright as it
Use to do
The world no longer breath as easy as it
Used to do

We're trapped inside
These are dark days
We're left behind
In so many ways
We're burnt alive
These are dark days
Are coming for us now

The water is no longer running as smoothly as it
Used to do
And the air is not as clear as it
Used to be

See the stone is bleeding
Hear the wicked thunder
Fell the earth is shaking
The whole world's going under

Our time is slowly running
It's burning under our feet
See the creatures in pain
And we will not return again
*/

#pragma GCC optimize("O3")
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

const int bs = 1000000007;

const long long N = 200031;

int tests,n,ar[N];
int ptrl,ptrr;
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}
    	ptrl=1;
    	ptrr=n;
    	ans.clear();
    	while (ptrl<=ptrr){
    		if (ans.size()%2==0){
    			ans.push_back(ar[ptrl]);
    			++ptrl;
    		}
    		else
    		{
    			ans.push_back(ar[ptrr]);
    			--ptrr;
    		}
    	}
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