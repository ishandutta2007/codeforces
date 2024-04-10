/*
She's got black hair
And she has got a black dress
She's pretending
That her life is a mess
But I cannot rest
With so many worries
I can't lie down
And say I am done

I live 'cause I need more light
I hope I can change today
She would never think of changing
Too much fucking emo, it's false (I know)

She stops me in the street
And asks me to follow

I would if I could
If I wouldn't mind breaking her.
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

int tests;
int n;
map<pair<long long, long long>,int > M;
long long ans,dx,dy;
map<pair<long long, long long>,int> ::iterator it;

long long gcd(long long a,long long b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

pair<long long,long long> normalize(long long a,long long b){
	long long Q=gcd(abs(a),abs(b));
	a/=Q;
	b/=Q;
	//if (a<0)
	//	a*=-1,b*=-1;
	return make_pair(a,b);
}

pair<long long, long long> neg(pair<long long, long long> p){
	p.first*=-1;
	p.second*=-1;
	return normalize(p.first,p.second);
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	M.clear();
    	cin>>n;
    	ans=0;
    	for (int i=1;i<=n;i++){
    		long long x1,x2,y2,y1;
    		cin>>x1>>y1>>x2>>y2;
    		dx=x2-x1;
    		dy=y2-y1;
    		pair<long long, long long> P=normalize(dx,dy);
    		//cout<<P.first<<"!!!"<<P.second<<endl;
    		//ans+=M[neg(P)];
    		M[P]++;
    	}
    	for (it=M.begin();it!=M.end();it++){
    		long long cnt=(*it).second;
    		pair<long long, long long> pp=(*it).first;
    		pp=neg(pp);
    		//cout<<pp.first<<"@"<<pp.second<<" "<<cnt<<"@"<<ans<<"@"<<M[pp]<<endl;
    		if (M.find(pp)!=M.end())
    			ans+=M[pp]*cnt;
    	}
    	cout<<ans/2<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}