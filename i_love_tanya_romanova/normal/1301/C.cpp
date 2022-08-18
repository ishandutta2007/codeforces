/*
Dehumanization through industrialization
Bring fear to the masses of reincarnation
Manic frustration deterioration
Nature fights back for its own preservation

Concrete coffin breeds lunacy
Cold steel skeleton
Desperation in the factory
Crank out oblivion

Material world paranoia
Corporations rule the earth
Material world paranoia
Enslavery begins at birth

Power's illusion brings global confusion
A forgone conclusion of mind's evolution
Nature's destruction through massive production
A blatant example of mindless construction

Concrete coffin breeds lunacy
Cold steel skeleton
Desperation in the factory
Crank out oblivion

Material world paranoia

Don't dream about how life can be
Experience your dreams
Before this prefab culture wastes your life
Stay on the straight and narrow course
Material wealth is yours
But the promise of a better future is a lie

The promise of a better future is nothing but a lie
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
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1100031;

int tests,n,m;

long long ans;

long long c_sum(long long x){
	return x*(x+1)/2;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m;
    	int rem=n-m;
    	long long ttl=1ll*n*(n+1)/2;
    	int sho=rem/(m+1);
    	int usd=sho*(m+1);
    	int ttl_long=rem-usd;
    	int ttl_short=(m+1)-ttl_long;
    	ans=ttl-c_sum(sho)*ttl_short-c_sum(sho+1)*ttl_long;
    	cout<<ans<<endl;
    }
    //    cin.get(); cin.get();
    return 0;
}