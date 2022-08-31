/*
I came across a smoking field, pulsating afterglow
I saw a seering flash of light erupt and skyward go
I staggered back in dazed surprise
What was it I had seen?
And as I stood there mesmerized I heard my spirit scream

Invader invader nearby
Invader, invader is nigh

This is the first of more to come in carefully planned attacks
If it is so we must prepare defenses to fight back
The call is out throughout the world
United we must stand
To build a line, strategic force, they will not take a man

Invader invader nearby
Invader, invader is nigh

When they come to take control every man must play his role
They won't take our world away when the children we leave
Will have to believe in today

We warn you now you things out there
Whatever you may send
We won't give in without a fight, a fight until the end
With vigilance by day and night our scanners trace the sky
A shield is sealed upon this earth, a shield you won't get by

Invader invader nearby
Invader, invader is nigh
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
#define prev asdgSHJsfgsdfhdsh

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n,score[N];
string st1,st2;
int cnt[20][20];

long long ans;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	cin>>st1;
	cin>>st2;
	for (int i=0;i<n;i++){
		cnt[st1[i]-'0'][st2[i]-'0']++;
	}

	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			if (i==j)
				continue;
			for (int q=0;q<2;q++)
			{
				for (int w=0;w<2;w++){
					int old=(i|q)*2+(j|w);
					int nw=(j|q)*2+(i|w);
					if (old==nw)
						continue;
					ans+=1ll*cnt[i][q]*cnt[j][w];
				}
			}
		}
	}

	cout<<ans/2<<endl;

//	cin.get(); cin.get();
	return 0;
}