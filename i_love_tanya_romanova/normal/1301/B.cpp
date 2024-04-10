/*
Fulfilling morbid dreams
Of those who never have time to sleep
Enduring to extremes
Held by a promise that they won't keep
Dark silence is so real
Walls painted black as night
Locked up in chains of steel
Down in the cellar nothing is right

Mistress of perversity
Unwilling tool of other's lust
Witnessing abnormality
With no one left to trust
Hell couldn't be this bad
Sold by her father to gratify
She never had a chance
Raped, beaten, sodomized

Her martyred soul cries out
Yet no one hears her scream
Her world is fear and doubt
She's a prisoner of this grotesque scene

Mistress of perversity
She never had a chance
Raped, beaten, sodomized
Twisted urges drove her to the end
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
#define left asdgashgrketwjklrej
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

const int N = 1100031;

int tests,n,ar[N];
vector<int> vals;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;

    	vals.clear();

    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}

    	ar[0]=ar[n+1]=0;

    	for (int i=1;i<=n;i++){
    		if (ar[i]!=-1){
    			if (ar[i-1]==-1||ar[i+1]==-1)
    				vals.push_back(ar[i]);
    		}
    	}

    	if (vals.size()==0)
    		vals.push_back(1);

    	sort(vals.begin(),vals.end());

    	int T=(vals[0]+vals.back())/2;
    	for (int i=1;i<=n;i++){
    		if (ar[i]==-1)
    			ar[i]=T;
    	}

    	int mx=0;
    	for (int i=1;i<n;i++){
    		mx=max(mx,abs(ar[i]-ar[i+1]));
    	}

    	cout<<mx<<" "<<T<<endl;
    }
    //    cin.get(); cin.get();
    return 0;
}