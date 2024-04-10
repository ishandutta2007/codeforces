/*
Welcome to our fortress tall
Take some time to show you around
Impossible to break these walls
For you see the steel is much too strong
Computer banks to rule the world
Instruments to sight the stars

Possibly I've seen too much
Hangar 18 I know too much.

Foreign life forms inventory
Suspended State of cryogenics
Selective amnesia's the story
Believed foretold but who'd suspect
The military intelligence
Two words combined that can't make sense

Possibly I've seen too much
Hangar 18 I know too much.
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

int n,m,ar[N];

int solver(int cut,int l,int r){
	if (cut<l)
		return l;
	if (cut>r)
		return m+1;
	return cut;
}

int better(int old,int T,int l,int r){
	int here=solver(T,l,r);
	return min(old,here);
}

bool solve(int val){
	int cur=0;
	for (int i=1;i<=n;i++){
		int l,r;
		int bst=m+1;

		if (ar[i]+val<m){
			bst=better(bst,cur,ar[i],ar[i]+val);
		}
		else
		{
			bst=better(bst,cur,ar[i],m-1);
			bst=better(bst,cur,0,(ar[i]+val)%m);
		}
		cur=bst;
	}
	if (cur>=m)
		return false;
	return true;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m;

    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }
    int l,r;
    l=0;
    r=m;
    while (l<r){
    	int mid=l+r;
    	mid/=2;
    	if (solve(mid))
    		r=mid;
    	else
    		l=mid+1;
    }
    cout<<l<<endl;

//    cin.get(); cin.get();
    return 0;
}