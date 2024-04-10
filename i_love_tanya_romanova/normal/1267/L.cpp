/*
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

const int N = 500031;

int n,k,l;
string st;

int cnt[N];
int lo;
int ptr;
char board[1031][1031];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n>>l>>k;

    getline(cin,st);
    getline(cin,st);

    for (int i=0;i<st.size();i++){
    	cnt[st[i]]++;
    }

    lo=1;

    for (int col=1;col<=l;col++){
    	int ptr='a';
    		for (int i=lo;i<=k;i++){
    			while (cnt[ptr]==0)
    				++ptr;
    			board[i][col]=ptr;
    			--cnt[ptr];
    		}
    	while (board[lo][col]!=board[k][col])
    		++lo;
    }

    ptr='a';

    for(int col=1;col<=l;col++){
    	for (int i=1;i<=n;i++){
    		if (board[i][col]==0)
    		{
    			while (cnt[ptr]==0)
    				++ptr;
    			board[i][col]=ptr;
    			--cnt[ptr];
    		}
    	}
    }

    for (int i=1;i<=n;i++){
    	string temp;
    	for (int j=1;j<=l;j++){
    		temp+=board[i][j];
    	}
    	cout<<temp<<endl;
    }

//    cin.get(); cin.get();
    return 0;
}