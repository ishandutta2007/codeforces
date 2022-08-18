/*
I am Iron Man

Has he lost his mind?
Can he see or is he blind?
Can he walk at all
Or if he moves will he fall?

Is he alive or dead?
Has he thoughts within his head?
We'll just pass him there
Why should we even care?

He was turned to steel
In the great magnetic field
When he traveled time
For the future of mankind

Nobody wants him
He just stares at the world
Planning his vengeance
That he will soon unfurl

Now the time is here
For Iron Man to spread fear
Vengeance from the grave
Kills the people he once saved

Nobody wants him
They just turn their heads
Nobody helps him
Now he has his revenge

Heavy boots of lead
Fill his victims full of dread
Running as fast as they can
Iron Man lives again!
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
#define hash asdgasdgasdgdfrywewery

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n,m;
vector<int> v[N];
long long C[N],ans;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int id,val;
		cin>>id>>val;
		v[id].push_back(val);
	}

	for (int i=1;i<=m;i++){
		sort(v[i].begin(),v[i].end());
		reverse(v[i].begin(),v[i].end());
		long long s=0;
		for (int j=0;j<v[i].size();j++){
			s+=v[i][j];
			if (s>0)
				C[j+1]+=s;
		}
	}

	for (int i=1;i<=n;i++){
		ans=max(ans,C[i]);
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}