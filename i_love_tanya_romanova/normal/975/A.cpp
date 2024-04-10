/*
I bid you welcome to my world
They call me existence
You have just entered through the gate
to your journey towards eternity
This part I control
In the beginning you'll fear nothing
As I climb beside you
Time will be your master in this laborious part of
human subsistence
This part I control
Black clouds embraces your soul
Slowly passing through repeating lacunas of anguish
When time takes your life
I will transfer you into the bare grip of thinking tranquility
Voices frilling the emptiness of the dead floating
Seamless across the surface into chilling stillness
Nothing can help you now

You'll never be alone again
You'll never die again
You'll never be born again
You'll forever be, stuck here in eternity
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

int n;
set<int> S;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (;n;--n){
		string st;
		long long x=0;
		cin>>st;
		for (int i=0;i<st.size();i++){
			int here=st[i]-'a';
			x|=(1<<here);
		}
		S.insert(x);
	}
	cout<<S.size()<<endl;

//	cin.get(); cin.get();
	return 0;
}