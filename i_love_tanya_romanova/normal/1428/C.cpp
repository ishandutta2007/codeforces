/*
He wants your soul, he will blind you,
Tell you lies, betray you, deceive you
He calls himself so many names,
But his real one you will never, never know

Pray for me, now pray for me
Cry before you die, before you die
Pray for me, so pray for me
Die for your sins

He will preach untrue sermons, telling of lies and talking of sins,
The path is long and far
But he will never lead us to the promised land,
Dont follow, dont follow this false prophet

Pray for me, now pray for me
Cry before you die, before you die
Pray for me, so pray for me
Die for your sins

Take revenge on the whole human race
Take revenge on the whole human race

He will bring you to your knees and make you weak,
He will take his revenge on humanity
He wants your fortune, your belongings,
He will suck every single drop of your blood

Pray for me, now pray for me
Cry before you die, before you die
Pray for me, so pray for me
Die for your sins, for your sins

Pray for me, now pray for me
Cry before you die, before you die
Pray for me, so pray for me
Die for your sins

Cry for me
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

int tests,rmost,cnt;
string st;
vector<int> S;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>st;
    	S.clear();
    	for (int i=0;i<st.size();i++){
    		if (S.size()==0){
    			S.push_back(st[i]);
    			continue;
    		}
    		if (st[i]=='B'){
    			S.pop_back();
    		}
    		else
    			S.push_back(st[i]);
    	}
    	cout<<S.size()<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}