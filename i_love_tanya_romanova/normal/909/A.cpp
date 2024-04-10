/*
Waitin', watchin' the clock, it's four o'clock, it's got to stop
Tell him, take no more, she practices her speech
As he opens the door, she rolls over...
Pretends to sleep as he looks her over

She lies and says she's in love with him, can't find a better man...
She dreams in color, she dreams in red, can't find a better man...
Can't find a better man
Can't find a better man
Ohh...

Talkin' to herself, there's no one else who needs to know...
She tells herself, oh...
Memories back when she was bold and strong
And waiting for the world to come along...
Swears she knew it, now she swears he's gone

She lies and says she's in love with him, can't find a better man...
She dreams in color, she dreams in red, can't find a better man...
She lies and says she still loves him, can't find a better man...
She dreams in color, she dreams in red, can't find a better man...
Can't find a better man
Can't find a better man
Yeah...

She loved him, yeah... she don't want to leave this way
She feeds him, yeah... that's why she'll be back again

Can't find a better man
Can't find a better man
Can't find a better man
Can't find a better... man...
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

const int N = 200031;

string pref(string st,int len){
	string temp="";
	for (int i=0;i<len;i++){
		temp+=st[i];
	}
	return temp;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	string st1,st2;
	cin>>st1>>st2;
	string ans=st1+st2;

	for (int i=1;i<=st1.size();i++){
		for (int j=1;j<=st2.size();j++){
			string temp=pref(st1,i)+pref(st2,j);
			if (temp<ans)
				ans=temp;
		}
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}