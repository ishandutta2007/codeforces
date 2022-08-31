/*
Refrain from the way we were
Slain the invincible
Changed are the the ways of man
Fortitude to face the path

[Chorus:]
Vanquish the pain don't want to see it fail
Faith divides us death unites us
Vanquish the pain don't want to seek despair
Faith divides us death unites us

Tears for a hopeless case
Outside is still so vague
Frayed the landscapes of old
Cleared the indelible

[Chorus]

Cannot sleep through darkened skies
Cannot dream until it's over
Cannot sleep through darkened skies
Cannot dream until it's over

[Chorus]
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

int tests;
string st;

string solve(string st){
	if (st.size()%2)
		return "NO";
	if (st[0]==')')
		return "NO";
	if (st[st.size()-1]=='(')
		return "NO";
	return "YES";
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>st;
    	cout<<solve(st)<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}