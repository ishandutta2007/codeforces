/*
Again we stalk the stage
At mach speed we engage
Feeding people's rage
The big cat's left it's cage
Back in the bus again
To catch another plane
The behavior's quite insane
But we do it for the fame, yeah

I lost my mind, I lost all my money
I lost my life to the killing road

The road will never end
It always starts again
Another show's around the bend
Another long lost friend
Faceless as the snow
There's nothing special about the road
It's just another haul
It's just too damn long that's all, yeah
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

int cnt[N];
int ar[N];
int n;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
		cnt[ar[i]]++;
	}

	for (int i=1;i<=100000;i++){
		if (cnt[i]%2){
			cout<<"Conan"<<endl;
			return 0;
		}
	}

	cout<<"Agasa"<<endl;

//	cin.get(); cin.get();
	return 0;
}