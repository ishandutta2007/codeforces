/*
Hide from the public eye, choose to appear when it suits you
Claim you're just, killing women and children
Fight, when you choose to fight, hide in a cave when you're hunted
Like a beast spawned from hell, utilizing fear

Chosen by god or a coward insane?
Stand up and show me your face!

Suicidal, in a trance
A religious army
Fight without a uniform and hide in the crowd
Call it holy, call it just
Authorized by heaven
Leave your wounded as they die, and call it gods will

Run when its time to pay, fear consequence of your action
Reappear, when you're almost forgotten
Dream of a world in peace, yet you cause pain and destruction
Kill your own, a response of your actions

Captured in all you lies, fear is in your eyes
Creature who's gone insane, your war is in vain
Trapped in a cage of stone, we'll destroy your home
Consequence of your action
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
#define bs 1000000007
#define bsize 512

const int N = 210000;

using namespace std;

string st;
stack<char> S;
int ans;

int get_type(char c)
{
	if (c == '<' || c == '{' || c == '[' || c == '(')
		return 1;
	return 2;
}

bool paired(char a, char b)
{
	if (a == '<'&&b == '>')
		return true;
	if (a == '('&&b == ')')
		return true;
	if (a == '['&&b == ']')
		return true;
	if (a == '{'&&b == '}')
		return true;
	return false;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> st;

	for (int i = 0; i < st.size(); i++)
	{
		if (get_type(st[i]) == 1)
		{
			S.push(st[i]);
			continue;
		}
		if (S.size() == 0)
		{
			cout << "Impossible" << endl;
			return 0;
		}
		char val = S.top();
		if (!paired(val, st[i]))
			++ans;
		S.pop();
	}

	if (S.size())
	{
		cout << "Impossible" << endl;
		return 0;
	}
	else

		cout << ans << endl;
	cin.get(); cin.get();
	return 0;
}