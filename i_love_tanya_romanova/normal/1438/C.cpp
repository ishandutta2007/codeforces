/*
Imagine there's no heaven,
It's easy if you try,
No hell below us,
Above us only sky,
Imagine all the people
living for today...

Imagine there's no countries,
It isnt hard to do,
Nothing to kill or die for,
No religion too,
Imagine all the people
living life in peace...

You may say Im a dreamer,
but Im not the only one,
I hope some day you'll join us,
And the world will live as one.

(Imagine all the people sharing all the world)

Imagine no possesions,
I wonder if you can,
No need for greed or hunger,
A brotherhood of man,
Imagine all the people
Sharing all the world...

You may say Im a dreamer,
but Im not the only one,
I hope some day you'll join us,
And the world will live as one.
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

const int N = 600031;

int tests,n,m,ar[231][231];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m;
    	for (int i=1;i<=n;i++){
    		for (int j=1;j<=m;j++){
    			cin>>ar[i][j];
    			int should_be=(i+j)%2;
    			if (ar[i][j]%2!=should_be)
    				++ar[i][j];
    		}
    	}
    	for (int i=1;i<=n;i++){
    		for (int j=1;j<=m;j++){
    			if (j>1)
    				cout<<" ";
    			cout<<ar[i][j];
    		}
    		cout<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}