/*
Well, you killed your first man at 13,
Killer instinct, Animal supreme,
By 16 you had learned to fight
The way of the warrior, you took it as your right.

Sunlight, falling on your steel,
Death in life is your ideal,
Life is like a wheel

Through earth and water, fire and wind,
You came at last - nothing was the end,
Make a cut by fire and stones,
Take you and your blade and break you both
in two - break you both in two.

Sunlight, falling on your steel,
Death in life is your ideal,
Life is like a wheel rolling on and on.
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
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 700031;

int n;
string st;
int ans[N];
int D1,D2;

vector<int> O;

int C;
int res[100];

void answer(){
	cout<<"!";
	for (int i=0;i<O.size();i++){
		cout<<" "<<O[i];
	}
	cout<<endl;
}

void make_query(int a,int b){
	++C;
	cout<<"? "<<a<<" "<<b<<endl;
	int ret;
	cin>>ret;
	res[C]=ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    O.push_back(4);
    O.push_back(8);
    O.push_back(15);
    O.push_back(16);
    O.push_back(23);
    O.push_back(42);
    make_query(1,2);
    make_query(3,4);
    make_query(1,5);
    make_query(1,3);

    do
    {
    	if (O[0]*O[1]==res[1]&&O[2]*O[3]==res[2]&&O[0]*O[4]==res[3]&&O[0]*O[2]==res[4])
    		answer();
    }
    while (next_permutation(O.begin(),O.end()));

//    cin.get(); cin.get();
    return 0;
}