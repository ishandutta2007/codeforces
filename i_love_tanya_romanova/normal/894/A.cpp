/*
Mama's gotta problem
She don't know what to say
Her little baby boy just left home today
She's got to be the loser in the end
She's got to be the loser in the end
Misuse her and you'll lose her as a friend
She's ma on whom you can always depend

She washed and fed, and clothed and cared
For nearly twenty years
And all she gets is "goodbye ma"
And the nightimes for her tears
She's got to be the loser in the end
She's got to be the loser in the end
Misuse her and you'll lose her as a friend
She's ma on whom you can always depend

So listen mothers everywhere
To just one mother's son
You'll get forgotten on the way
If you don't let them have their fun
Forget regrets, and just remember
It's so long since you were young

You're bound to be the loser in the end
You're bound to be the loser in the end
They'll choose their new shoes that's not far to bend
You're ma on whom they can always depend
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

const int N = 300031;

string st;
int ans;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>st;
	for (int i=0;i<st.size();i++){
		for (int j=i+1;j<st.size();j++){
			for (int q=j+1;q<st.size();q++){
				if (st[i]=='Q'&&st[j]=='A'&&st[q]=='Q')
					++ans;
			}
		}
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}