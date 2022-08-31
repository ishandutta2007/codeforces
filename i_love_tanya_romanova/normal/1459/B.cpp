/*
More than this
A certain divide ask yourself why,
More than this
Turn back in time wondering why

Then you'll see, tears won't wash this away
Memories of the years that started the pain

All of this
Thoughts that unite long been denied
All of this
Anger ignites a lasting goodbye

Then you'll see, tears won't wash this away
Memories of the years that started the pain

Can't you see tears won't wash out the rage?
Memories fallen years that started the hate
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

set<pair<int,int> > S;
pair<int,int> fi;
int n;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n;

    int hor_moves=(n+1)/2;
    int ver_moves=n/2;

    for (int le=0;le<=hor_moves;le++){
    	for (int up=0;up<=ver_moves;up++){
    		fi=make_pair(-le+(hor_moves-le),-up+ver_moves-up);
    		S.insert(fi);
    	}
    }

    for (int le=0;le<=ver_moves;le++){
    	for (int up=0;up<=hor_moves;up++){
    		fi=make_pair(-le+(ver_moves-le),-up+hor_moves-up);
    		S.insert(fi);
    	}
    }

    cout<<S.size()<<endl;

    //cin.get(); cin.get();
    return 0;
}