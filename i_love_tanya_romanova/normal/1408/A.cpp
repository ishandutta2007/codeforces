/*
I miss the warm embrace I felt
First time you touched me
Secure and safe in open arms
I should have known you'd crush me
A snake you were when we met
I loved you anyway
Pulling out your poisoned fangs
The venom never goes away
Serpent swims free in my blood
Dragons sleeping in my veins
Jackyl speaking with tongue
Roach egg laying in my brain
Once stalked beneath your shadow
Sleepwalking to the gallows
I'm the sun that beats your brow in
'til I finally threw the towel in
Never knowing if I'd wake up in a
Whirlpool got redundant
My brain was just some driftwood
In a cesspool I became dead
From a rock star to a desk fool
Was my destiny someone said
Love's a tide pool
Taste the waters life's abundant
Taste me
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

const int N = 200031;

int tests,n,ans[N];
int ar[5][N];

int get_valid(int ps, int b1,int b2){
	for (int i=1;i<=3;i++){
		if (ar[i][ps]!=b1&&ar[i][ps]!=b2)
			return ar[i][ps];
	}
	return -1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	for (int i=1;i<=3;i++){
    		for (int j=1;j<=n;j++){
    			cin>>ar[i][j];
    		}
    	}
    	ans[1]=ar[1][1];
    	for (int i=2;i<n;i++){
    		ans[i]=get_valid(i,ans[i-1],ans[i-1]);
    	}
    	ans[n]=get_valid(n,ans[n-1],ans[1]);
    	for (int i=1;i<=n;i++){
    		if (i>1)
    			cout<<" ";
    		cout<<ans[i];
    	}
    	cout<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}