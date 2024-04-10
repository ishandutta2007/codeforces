/*
Critical moments pass,
As doctrines of fools will last.
I am just trying to cope,
Into my horrorscope.
Through eyes and ears they bleed,
Reciting their holy creed.
Heeding but one request,
The future is put to rest...

Bless me in darkened days,
Down to my knees I pray.
I am just trying to cope
Within this horrorscope.
In the wake of all frustration,
I begin to lose control.

Watched as the weapons fired,
Bombs bursting in the air...
Burned in the fields of fire!
Standing in the middle of nowhere.
Watched as the weapons fired,
Baptized in fields of fire!

Well,
The change is here,
And the future clear.
I can feel it coming.
So full of hate,
It's getting late!
Yeah, I know it's coming.
When all the choice
Turned to just one voice,
Yeah, the wind is turning.

This is your horrorscope...

Words laced with blasphemy,
Drip with sincerity.
Falling into the plan,
Like sacrificial lambs.
Hearing the words and said,
Rings like nail to the head.
Now I can see the stars,
I know we have gone too far.

Watched as the weapons fired,
Bombs bursting in the air...
Baptized in fields of fire!
Watched as the weapons fired,

Well,
The change is here,
And the future clear.
I can feel it coming.
So full of hate,
It's getting late!
Yeah, I know it's coming.
When all the choice
Turned to just one voice,
Yeah, the wind is turning.

Well,
The change is here,
And the future clear.
I can feel it coming.
So full of hate,
It's getting late!
Yeah, I know it's coming.
When all the choice
Turned to just one voice,
Yeah, the wind is turning.

This is your horrorscope.
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
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int cnt1[N][40],cnt2[N][50];
int S[N][27];


bool eq(string a,string b){
	for (int i=0;i<=a.size();i++){
		for (int j=0;j<26;j++)
			cnt1[i][j]=0,
			cnt2[i][j]=0;
	}
	for (int i=0;i<a.size();i++){
		for (int j=0;j<26;j++){
			cnt1[i+1][j]=cnt1[i][j];
			cnt2[i+1][j]=cnt2[i][j];
			cnt1[i+1][a[i]-'a']++;
			cnt2[i+1][b[i]-'a']++;
		}
	}
	for (int i=1;i<a.size();i++){
		int d=0;
		for (int j=0;j<26;j++){
			if (cnt1[i][j]!=cnt2[i][j])
				d=1;
		}
		if (d==0)
			return true;
	}
	return false;
}

bool good(string st){
	string temp=st;
	string found;
	sort(temp.begin(),temp.end());
	do{
		if (temp==st)
			continue;
		if (eq(temp,st)==0){
			found=temp;
			break;
		}
	}while (next_permutation(temp.begin(),temp.end()));
	if (found.size()==0){
		return true;
	}
	cout<<found<<endl;
	return false;
}

string st;
int tests;

bool solver(int l,int r){
	if (l==r)
		return 1;
	if (st[l-1]!=st[r-1])
		return 1;
	int ttl=0;
	for (int i=0;i<26;i++){
		if (S[r][i]!=S[l-1][i])
			++ttl;
	}
	return (ttl>=3);
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*string st;
    while (cin>>st){
    	cout<<good(st)<<endl;
    }*/

    cin>>st;
    for (int i=1;i<=st.size();i++){
    	for (int j=0;j<26;j++){
    		S[i][j]=S[i-1][j];
    	}
    	S[i][st[i-1]-'a']++;
    }

    cin>>tests;
    for (;tests;--tests){
    	int l,r;
    	cin>>l>>r;
    	if (solver(l,r))
    		puts("Yes");
    	else
    		puts("No");
    }

    //    cin.get(); cin.get();
    return 0;
}