/*
Faintly arisen, tenderly torn
Dreamlike decision, unconsciously born

Firm in conviction yet tempt me they can
Deny me of trust and a demon I hide

A drive to be less than the fortunate
A dream in the casket of Eden
Crave that which you do not desire
Cling tightly to your deepest fear

I rose the greatest monument
Again and again
I bear the greatest treasure
Of time and a word

Treason spilt on the loneliest of graves
Desperation dealt the losing hand again
Wherein lie the purpose of the day?
Is there return in sadness?

Does your ceiling differ much from mine
Where we see each other?
Here in this light
Is that pillow more than a frame
That holds the chaos fast?
Now his hand a fist
Gain control

Silence fell and eyes now widened
Filling up the strength collapsing
Capable of the ending froze in the tracks
Brought to a bitter halt

On the floor it seems the steps are showing
Left a print just like it did in me
What has been and what will be
Never care 'cause I was in between
As I said with on afoot in loneliness
You hide here in me
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

const int LOT = 1600031;

int pr[LOT+31];

vector<int> primes[LOT+31];

int n,ar[N];
set<int> S;
set<int>::iterator it;

int thold;

bool banned[LOT+31];

bool can_add(int number){
	for (int i=0;i<primes[number].size();i++){
		int val=primes[number][i];
		if (banned[val])
			return false;
	}
	return true;
}

void ban_number(int number){
	for (int i=0;i<primes[number].size();i++){
			int val=primes[number][i];
			if (banned[val])
				return;
			banned[val]=1;
			for (int j=val;j<=LOT;j+=val){
				if (S.find(j)!=S.end())
					S.erase(j);
			}
		}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	int C=0;

	pr[1]=1;
	for (int i=2;i<=LOT;i++){
		if (pr[i]==0){
			for (int j=i;j<=LOT;j+=i){
				pr[j]=1;
				primes[j].push_back(i);
			}
			if (i>100000)++C;
		}
	}

	//cout<<C<<endl;

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
//		ar[i]=2;
	}

	for (int i=1;i<=LOT;i++){
		S.insert(i);
	}


	int cut_pos=n+1;

	for (int i=1;i<=n;i++){
		if (!can_add(ar[i])){
			cut_pos=i;
			break;
		}
		ban_number(ar[i]);
	}


	for (int i=cut_pos;i<=n;i++){
		if (i==cut_pos)
			thold=ar[i];
		else
			thold=1;
		it=S.upper_bound(thold);
		ar[i]=(*it);
		ban_number(*it);
	}

	for (int i=1;i<=n;i++){
		if (i>1)
			cout<<" ";
		cout<<ar[i];
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}