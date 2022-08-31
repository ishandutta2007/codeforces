/*
You guys ready...
Alone... listless... breakfast table in an otherwise empty room
Young girl... violins... center of her own attention
Mother reads aloud, child tries to understand it
Tries to make her proud
The shades go down, it's in her head
Painted room... can't deny there's something wrong...
Don't call me daughter, not fit to
The picture kept will remind me
Don't call me daughter, not fit to
The picture kept will remind me
Don't call me...
She holds the hand that holds her down
She will... rise above...
Don't call me daughter, not fit to
The picture kept will remind me
Don't call me daughter, not fit to be
The picture kept will remind me
Don't call me...
Don't call me daughter, not fit to
The picture kept will remind me
Don't call me daughter, not fit to be
The picture kept will remind me
Don't call me...
The shades go down
The shades go down
The shades go, go, go...
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 200031;

int x,y,z,a,b,c;

bool solve(){
	if (x>a)
		return false;
	a-=x;
	if (a+b<y)
		return false;
	return (a+b+c>=y+z);
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

	cin>>x>>y>>z;
	cin>>a>>b>>c;
	if (solve()){
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;

//    cin.get(); cin.get();
    return 0;
}