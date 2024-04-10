/*
This is a true story of a slaveman
Who fled his people from the white man
So I'll say that he showed me the way
To be brave, brave, don't be afraid
"Zumbi" his name, "Quilombo" his place
Our root you can never erase
"Zumbi" his name, "Quilombo" his place
Our root you can never erase

Thirty thousand Zumbi refugees
Fight the right, the right to be free
Rape the city, the masters of greed
Follow the warrior, the warrior Zumbi
No more no more no more slavery
No more no more no more misery
No more no more no more suffering

Zumbi Zumbi
Blow them away

Here we come, here we come slave drums
Here we come, here we come Quilombo
Time for war in tha land of the sun
I know God will not leave us alone
I know God will never leave us alone

Zumbi Zumbi
Got to be free

Quilombo Quilombo
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const int bs = 1000000007;

const int N = 600031;

long long n,m,val,D,a[N],b[N];
vector<long long> order;

long long gcd(long long a,long long b){
	while(a&&b)a>b?a%=b:b%=a;
	return a+b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>val;
    	a[i]=val;
    	order.push_back(val);
    }
    for (int i=1;i<=m;i++){
    	cin>>b[i];
    }

    sort(order.begin(),order.end());
    D=0;
    for (int i=1;i<order.size();i++){
    	D=gcd(D,order[i]-order[0]);
    }

    for (int i=1;i<=m;i++){
    	long long here=gcd(D,a[1]+b[i]);
    	if (i>1)
    		cout<<" ";
    	cout<<here;
    }
    cout<<endl;

    //cin.get(); cin.get();
    return 0;
}