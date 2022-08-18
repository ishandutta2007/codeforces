/*
Compelled to speak when not to speak
My words lead and I follow
I must talk or else I'm weak
Let no one know my shell's hollow

False world created
I just watch it come to life
Your faith's my weapon
And your trust by my side

Lost all my senses
Can't feel, can't hear
I'm blinded, I'm blinded
Lost all my senses
Emotionally numb
Blinded, I'm blinded

Nothing's sacred and no one's safe
I'm feeding on denial
Getting careless, soon bound to fail
Fooled by my own betrayal

Are you lost in a fury?
Fearing to fail
Are you aching for vengeance
And got lost on the way?

Are you hiding your anger?
Fearing truth will prevail
Ashamed of the present
And what you've become today

False world created
I just watch it come to life
Your faith's my weapon
And your trust by my side

Lost all my senses
Can't feel, can't hear
I'm blinded, I'm blinded
Lost all my senses
Emotionally numb
Blinded, I'm blinded

Lost all my senses
Can't feel, can't hear
I'm blinded, I'm blinded
Lost all my senses
Emotionally numb
Blinded, I'm blinded
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 1010031;

int n;
int dist[N];
int a[N];
queue<int> qu;
void update(int a, int b)
{
	if (dist[a] != 0)
		return;
	dist[a] = dist[b] + 1;
	qu.push(a);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
//		cin >> a[i];
		scanf("%d", &a[i]);
	}

	qu.push(1);
	dist[1] = 1;
	while (qu.size())
	{
		int v = qu.front();
		qu.pop();
		if (v > 1)
			update(v - 1, v);
		if (v < n)
			update(v + 1, v);
		update(a[v], v);
	}

	for (int i = 1; i <= n; i++)
	{
		if (i>1)
			printf(" ");
		printf("%d", dist[i]-1);
	}

	cin.get(); cin.get();
	return 0;
}