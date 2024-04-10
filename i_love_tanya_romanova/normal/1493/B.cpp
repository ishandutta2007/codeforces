/*
In this black cold night
Make me calm
Stop the blood running from my eyes
In my mind
From the places in my mind

When the darkness embraces me
I do not feel alone
When the darkness embraces me
I know I'm going home

In this black cold night
Chase the pain from within my heart
Wipe the blood from my eyes
From the places in my mind

When the darkness embraces me
I do not feel alone
When the sorrow takes me
I'm embracing the darkness alone
Please - take me home

I'm the snake in my own so called paradise
Embracing myself with darkness
My demise

In this black cold night
Make me calm
Stop the blood running from my eyes
In my mind
From the pain within my mind
*/

#pragma GCC optimize("Ofast")
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

const long long bs = 1000000007;

const int N = 200031;

int mir[1000];
int tests;
int H,M;
string st;
int cur_h,cur_m;

int get_h(char c1,char c2){
	return (c1-48)*10+c2-48;
}

int get_m(char c1,char c2){
	return get_h(c1,c2);
}

bool valid_mirror(int h,int m){
	if (mir[h/10]==-1||mir[h%10]==-1||mir[m/10]==-1||mir[m%10]==-1)
		return false;
	int new_h=10*mir[m%10]+mir[m/10];
	int new_m=10*mir[h%10]+mir[h/10];
	return (new_h<H&&new_m<M);
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    for (int i=0;i<=9;i++){
    	mir[i]=-1;
    }
    mir[0]=0;
    mir[1]=1;
    mir[2]=5;
    mir[5]=2;
    mir[8]=8;

    cin>>tests;
    for (;tests;--tests){
    	cin>>H>>M;
    	cin>>st;
    	cur_h=get_h(st[0],st[1]);
    	cur_m=get_m(st[3],st[4]);

    	while (true){
    		if (valid_mirror(cur_h,cur_m))
    			break;
    		cur_m++;
    		if (cur_m==M){
    			cur_m=0;
    			cur_h++;
    			cur_h%=H;
    		}
    	}
    	cout<<cur_h/10<<cur_h%10<<":"<<cur_m/10<<cur_m%10<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}