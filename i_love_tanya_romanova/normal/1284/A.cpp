/*
Got on chance, infiltrate them
Get it right, terminate them
The Panzers will, permeate them
Break their pride, denigrate them
And their people, retrograde them
Typhus, deteriate them
Epidemic, devastate them
Take no prisoners, cremate them

Going to war, give 'em hell
D-Day, next stop Normandie
Beginning of the end
WE know how to and sure as shit we'll win
War is peace sure man
A retreat for the damned
A playground for the demented
A haven for those who walk this world
Bereft of heart and soul
Love and war they say all is fair
Take his life
But won't take his hair
Your body has parts your
Country can spare
By the way son here's
Your wheelchair

He once had to be all he could be
Now he's nothing for no one nowhere to see
Funny thing, he's like you & me
It's a funny thing, a funny thing
Tears streak his solemn stare
Abandoned for wreckage nobody cares
No one knew what would happen there
No one spoke no one even dared
Don't ask what you can do for you country
Ask what your country can do for you
Take no prisoners, take no shit
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

const int N = 210031;

int n,m;
string A[N],B[N];
int tests;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n>>m;
    for (int i=0;i<n;i++){
    	cin>>A[i];
    }
    for (int i=0;i<m;i++){
    	cin>>B[i];
    }
    cin>>tests;
    for (;tests;--tests){
    	int x;
    	cin>>x;
    	--x;
    	cout<<A[x%n]<<B[x%m]<<endl;
    }

    //    cin.get(); cin.get();
    return 0;
}