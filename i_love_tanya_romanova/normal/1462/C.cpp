/*
So you head out, on a journey with no help at all
The words that they speak, you don't hear
Prepared to survive, and rise not to fall
The screams so loud fall on deaf ears

What were you thinking a minimalist's lie
You just sit there and wait in the cold
Outside there is hope strangers passing you by
Left with yourself and your soul

It's life in the death zone
The strong will survive
It's the sound of the death drome
You gamble with your life

You climb the mountain alone
You stand on the mountain alone
You die on that mountain alone
You made your mark
Concealed in the dark

Condemed to the ice god you just sit there
Frozen even into your soul
What morals exists out there in the cold?
Death on the mountain you're sold
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

const long long N = 200031;

int ans[N];

void backtrack(int num,int sum,int ldi){
	if (ans[sum]==0||ans[sum]>num)
		ans[sum]=num;
	for (int ad=ldi+1;ad<=9;ad++){
		backtrack(num*10+ad,sum+ad,ad);
	}
}

int tests,n;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    backtrack(0,0,0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	if (ans[n]==0)
    		cout<<-1<<endl;
    	else
    		cout<<ans[n]<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}