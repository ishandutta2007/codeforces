/*
You're breaking a chain
Lying until you can erase the past
Born with a look of deceit
Praying that all the bitter guilt's defeated
Born...

Stand on your own, killed from behind
Fools are blind, unwilling to accept, decline...
You'll turn a blind eye...

Bought by a sickening man
The weakened gather as fast as they can
'Whore' is what people roar
From fear of rejection,
You'll come back for more
Strong, don't see that love has ceased
In the end, only death release..

Stand on your own, Killed from behind
Fools are blind, you're on a lonely road...
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

const int bs = 998244353;

const int N = 600031;

int tests;
string st;
int cnt;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	int n;
    	cin>>n;
    	cin>>st;
    	cnt=0;
    	for (int i=st.size()-1;i>=0;--i){
    		if (st[i]==')')
    			++cnt;
    		else
    			break;
    	}
    	if (cnt*2>st.size())
    		cout<<"Yes"<<endl;
    	else
    		cout<<"No"<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}