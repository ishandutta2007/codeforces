/*
To ends unknown
By means unworthy
To answer wishes
Long dead and gone
Old empty promises
A just reward for the blind
Belief makes work for idle minds
We lost our way

The only dream that matters
Is the one you wake up from

Go

Onward to the singularity
Whatever they say
Whatever they do just go
Turn on this nonentity
Whatever they say
Whatever they do just go
We are faithless by default

I call for a world where we are nothing
More than the sum of what we know
Are we to be held hostage
By our tolerance for the intolerant
Then we've lost our way

To hope is to surrender
In this series of defeats

Go

Onward to the singularity
Whatever they say
Whatever they do just go
Turn on this nonentity
Whatever they say
Whatever they do just go
We are faithless by default
We've lost our way
A pain far too familiar
Denounce your savage self

Go

Onward to the singularity
Whatever they say
Whatever they do just go
Turn on this nonentity
Whatever they say
Whatever they do just go
We are faithless by default
*/

//#pragma GCC optimize("O3")
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

const int N = 400031;

int n,m;
string st;
char ar[200][200];

int ok;

bool inter_rows(int a,int b){
	for (int i=1;i<=m;i++){
		if (ar[a][i]=='#'&&ar[b][i]=='#')
			return 1;
	}
	return 0;
}

bool inter_cols(int a,int b){
	for (int i=1;i<=n;i++){
		if (ar[i][a]=='#'&&ar[i][b]=='#')
			return 1;
	}
	return 0;
}

bool dif_rows(int a,int b){
	for (int i=1;i<=m;i++){
		if (ar[a][i]!=ar[b][i])
			return 1;
	}
	return 0;
}

bool dif_cols(int a,int b){
	for (int i=1;i<=n;i++){
		if (ar[i][a]!=ar[i][b])
			return 1;
	}
	return 0;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>st;
		for (int j=1;j<=m;j++){
			ar[i][j]=st[j-1];
		}
	}

	ok=1;

	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if (inter_rows(i,j)){
				if (dif_rows(i,j))
					ok=0;
			}
		}
	}

	for (int i=1;i<=m;i++){
		for (int j=i+1;j<=m;j++){
			if (inter_cols(i,j))
			{
				if (dif_cols(i,j))
					ok=0;
			}
		}
	}

	if (ok)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

//	cin.get(); cin.get();
	return 0;
}