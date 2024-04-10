/*
I don't care, I don't care, I don't care, I don't care, I don't care, care if it's old
I don't mind, I don't mind, I don't mind, I don't mind, mind, don't have a mind
Get away, get away, get away, get away, away, away from your home
I'm afraid, I'm afraid, I'm afraid, I'm afraid, afraid, ghosts

Even if you have, even if you need
I don't mean to stare, we don't have to breed
We could plant a house, we could build a tree
I don't even care, we could have all three
She said, she said, she said, she said, she said, she said, she said, she said

I don't care, I don't care, I don't care, I don't care, care, care if it's old
I don't mind, I don't mind, I don't mind, I don't mind, mind, don't have a mind
Get away, get away, get away, get away, away, away from your home
I'm afraid, I'm afraid, I'm afraid, I'm afraid, afraid, ghosts

Even if you have, even if you need
I don't mean to stare, we don't have to breed
We could plant a house, we could build a tree
I don't even care, we could have all three
She said, she said, she said, she said, she said, she said, she said, she said

Even if you have, even if you need
I don't mean to stare, we don't have to breed
We could plant a house, we could build a tree
I don't even care, we could have all three
She said, she said, she said, she said, she said, she said, she said, she said, she said
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

string st;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>st;
	cin>>st;
	for (int i=0;i+1<st.size();i++){
		if (st[i]=='1'&&st[i+1]=='1'){
			cout<<"No"<<endl;
			return 0;
		}
	}

	for (int i=0;i<st.size();i++){
		if (st[i]=='0'){
			if (i>0&&st[i-1]=='1')
				continue;
			if (i+1<st.size()&&st[i+1]=='1')
				continue;
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;

//	cin.get(); cin.get();
	return 0;
}