/*
Got no religion, got no excuse
It's my own decision, won't take no abuse
Got my own way of living, your life I despise
Nothing I could be giving, change the look in my eyes

Got no distractions, got a one track mind
Noone ever told me, what I needed to find
If you can't understand me, then I just don't care
Do you want me to be, when there's nothing we share
When there's nothing we share

I ain't giving in, to all your goddamm rules
I'm gonna win, I don't listen to fools

I know you wanna judge me, you are all the same
Those you can't understand, always take all the blame
But I just don't buy, course I know the score
Something never change, we've all heard it before

I'm changing the rules
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

int tests;
int ok;
string st;

string apply(string s,int l,int r){
	string ret;
	for (int i=0;i<s.size();i++){
		if (i<l||i>r)
			ret+=s[i];
	}
	return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>st;
    	cin>>st;
    	ok=0;
    	if (st=="2020")
    		ok=1;
    	for (int i=0;i<st.size();i++){
    		for (int j=i;j<st.size();j++){
    			if (st.size()!=(j-i+5))
    				continue;
    			string temp=apply(st,i,j);
    			if (temp=="2020")
    				ok=1;
    		}
    	}
    	if (ok)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}