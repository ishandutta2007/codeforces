/*
Why can't you say sorrow
Why can't you say think I believe
Thou must not steal borrow
Why must you steal things I receive?

Why can't you say sorrow
Why can't you say think I believe
Why must you steal borrow
Always conceal cling to belief

Damaged this way hollowed
Living the lie that you can't take
Damaged maintained solemn
Living for rules you only break

How can you say?

The enemy is thrown into the sadness,
For the enemy there's only pain and sadness then death...
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
string st1,st2;
int cnt1,cnt2;
int n;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	cin>>st1;
    	cin>>st2;
    	cnt1=0;
    	cnt2=0;
    	for (int i=0;i<st1.size();i++){
    		if (st1[i]==st2[i])
    			continue;
    		if (st1[i]>st2[i])
    			cnt1++;
    		else
    			cnt2++;
    	}
    	if (cnt1>cnt2){
    		cout<<"RED"<<endl;
    	}
    	if (cnt1<cnt2){
    		cout<<"BLUE"<<endl;
    	}
    	if (cnt1==cnt2){
    		cout<<"EQUAL"<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}