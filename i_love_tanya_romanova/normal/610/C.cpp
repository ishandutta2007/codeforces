/*
Ruin is your profit
Meraud the hollow mind
Religious passion is not for you
Agnostic modern science
Suffocate superior forces
Tearing down this fortress of control

Dogmatic authority falls
Alternative to submission
Mental emancipation
Severance, selection of
All powers from above
Strong minded in preparation
For this sickening mess
We're living in

Threat for your security
Authority will collapse
End pseudo-democracy
Take fate in your own hands
Violent terroristic action
Only self-defense
Ignorence is unconciousness

No pessimistic vision
Corruption pseudo peace
Propaganda drug of nation
Deceiving you and me
A psychosocial revolt
Becomes aware, horowing truth
Hear my call!

Dogmatic authority falls!
*/

//#pragma comment(linker, "/STACK:16777216")
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1234567891
#define bsize 512

const int N = 510000;

using namespace std;

int n;
vector<vector<int> > had[20];

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	had[0].resize(1);
	had[0][0].push_back(1);

	for (int i = 1; i <= 9; i++)
	{
		had[i].resize(1 << i);
		int sz = (1 << i);
		sz /= 2;
		for (int j = 0; j < (1 << i); j++)
		{
			had[i][j].resize(1 << i);

			for (int q = 0; q < (1 << i); q++)
			{
				had[i][j][q] = had[i - 1][j % sz][q%sz];
				if (j >= sz&&q >= sz)
					had[i][j][q] ^= 1;
			}
		}
	}

	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < (1 << n); j++)
		{
			if (had[n][i][j])
				cout << "+";
			else
				cout << "*";
		}
		cout << endl;
	}

	cin.get(); cin.get();
	return 0;
}