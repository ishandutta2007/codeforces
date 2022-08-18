/*
Maybe in another life
I could find you there
Pulled away before your time
I can't deal it's so unfair

And it feels
And it feels like
Heaven's so far away
And it feels
Yeah it feels like
The world has grown cold
Now that you've gone away

Leaving flowers on your grave
Show that I still care
But black roses and Hail Mary's
Can't bring back what's taken from me
I reach to the sky
And call out your name
And if I could trade
I would

And it feels
And it feels like
Heaven's so far away
And it stings
Yeah it stings now
The world is so cold
Now that you've gone away
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

const int N = 510031;

int n,m,c;
int ar[N];

bool validate(){
	for (int i=1;i<=n;i++){
		if (ar[i]==0){
			return false;
		}
	}
	return true;
}

int find1(int val){ // going l->r
	for (int i=1;i<=n;i++){
		if (i>1&&ar[i-1]>val)
			return i-1;
		if (ar[i]==0)
			return i;
	}
	return n;
}

int find2(int val){
	for (int i=n;i>=1;--i){
		if (i<n&&ar[i+1]<val)
			return i+1;
		if (ar[i]==0)
			return i;
	}
	return 1;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m>>c;
	for (int i=1;i<=m;i++){
		int val;
		cin>>val;
		if (val<=c/2){
			int Q=find1(val);
			ar[Q]=val;
			cout<<Q<<endl;
		}
		else
		{
			int Q=find2(val);
			ar[Q]=val;
			cout<<Q<<endl;
		}

		/*for (int j=1;j<=n;j++){
			cout<<ar[j]<<" ";
		}
		cout<<endl;
*/
		if (validate())
			break;
	}

//	cin.get(); cin.get();
	return 0;
}