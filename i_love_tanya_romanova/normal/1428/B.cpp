/*
Seek evil, you will find, speak evil, its on your mind
Build a bridge to anywhere to have a home to turn
To a brook flows from anywhere and you will find the evil
That you suffer unto having on your mind

Walk this way and you will find
Those burning bridges inside your mind
So you look back into nowhere
To see all these bridges are meant to stay

Aggression in large amounts, thats everything that counts
No hand waiting that must be paid, leave your encores all unplayed
Knocked down and out, you cry it out loud
Locked inside your self-made prison

Walk this way and you will find
Those burning bridges inside your mind
So you look back into nowhere
To see all these bridges are meant to stay

then one fine youre led astray, a witch flew on her broom
in sparkling skies she flew away and took with her your doom
then one fine youre led astray, a witch flew on her broom
in sparkling skies she flew away and took with her your doom

Seek evil, you will find, speak evil, its on your mind
Build a bridge to anywhere to have a home to turn
To a brook flows from anywhere and you will find the evil
That you suffer unto having on your mind

Walk this way and you will find
Those burning bridges inside your mind
So you look back into nowhere
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

const int N = 300031;

int tests,n;
string st;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	cin>>st;
    	int have_l=0;
    	int have_r=0;
    	for (int i=0;i<st.size();i++){
    		if (st[i]=='>')
    			have_l=1;
    		if (st[i]=='<')
    			have_r=1;
    	}
    	if (have_l+have_r<2){
    		cout<<n<<endl;
    		continue;
    	}
    	int ans=0;
    	for (int i=0;i<n;i++){
    		if (st[i]=='-'||st[(i+1)%n]=='-')
    			++ans;
    	}
    	cout<<ans<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}