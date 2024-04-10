/*

Night falls and I'm alone
Skin, yeah, chilled me to the bone
You turned and you ran, oh yeah
Oh slipped right from my hands

Yeah

Blue on black
Tears on a river
Push on a shove
It don't mean much
Joker on jack
Match on a fire
Cold on ice
A dead man's touch
Whisper on a scream
Never change a thing
Doesn't bring you back
It's like blue on black

Blind, oh, but now I see
Truth, lies and in between
Wrong can't be undone, oh no
Well it slipped from the tip of your tongue

Yeah

Blue on black
Tears on a river
Push on a shove
It don't mean much
Joker on jack
Match on a fire
Cold on ice
A dead man's touch
Whisper on a scream
Never change a thing
Doesn't bring you back
It's blue on black

Blue on black
Tears on a river
Push on a shove
It don't mean much

Blue on black
Tears on a river
Push on a shove
It don't mean much
Joker on jack
Match on a fire
Cold on ice
A dead man's touch
Whisper on a scream
Never change a thing
Doesn't bring you back
It's blue on black
Yeah, blue on black
Yeah, it's blue on black
Yeah, blue on black
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

const int N = 2031;

int n;
vector<char> v;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=0;i<n;i++){
		char c;
		cin>>c;
		v.push_back(c);
	}
	for (int i=1;i<=n;i++){
		if (n%i==0)
			reverse(v.begin(),v.begin()+i);
	}
	for (int i=0;i<v.size();i++){
		cout<<v[i];
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}