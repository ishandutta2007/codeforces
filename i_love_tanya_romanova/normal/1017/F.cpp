/*
You know that life isn't set
I lead the pack I ain't no pretender
You give as good as you get
We live and die 'cause there's no surrender

Chasing a dream as I go higher
Playing it mean, my heart's on fire
Living my life, ain't no pretender
Ready to fight with no surrender

You know the way that I feel
If you're with me you better hold on tighter
I'm only keeping it real
That's who I am, I'm just a non-stop fighter

Chasing a dream as I go higher
Playing it mean, my heart's on fire
Living my life, ain't no pretender
Ready to fight with no surrender

Run out of road
The end of the days
Not for the weak
Only the brave

Chasing a dream as I go higher
Playing it mean, my heart's on fire
Living my life, ain't no pretender
Ready to fight with no surrender

I'm chasing a dream as I go higher
I'm playing it mean, my heart's on fire
I'm living my life, ain't no pretender
Ready to fight with no surrender
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

const int N = 200031;

const int BLOCK = 1000000;

int pr[BLOCK+31];
vector<int> primes;
int n;

unsigned int ans;

unsigned int solver(int val){
	int ret=0;
	int q=n;
	while (q){
		ret+=q/val;
		q/=val;
	}
	//cout<<ret<<endl;
	return ret;
}

unsigned int A,B,C,D;

unsigned int polyn(unsigned int val){
	return A*val*val*val+B*val*val+C*val+D;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	pr[1]=1;
	for (int i=2;i<=20000;i++){
		if (pr[i]==0){
			for (int j=i*2;j<=20000;j+=i){
				pr[j]=1;
			}
		}
	}

	for (int i=2;i<=20000;i++){
		if (pr[i]==0){
			primes.push_back(i);
		}
	}

	cin>>n;

	cin>>A>>B>>C>>D;

	for (int start=1;start<=n;start+=BLOCK){
		for (int i=0;i<BLOCK;i++){
			pr[i]=0;
		}
		//cout<<start<<endl;
		for (int i=0;i<primes.size();i++){
			int rem=start%primes[i];
			//cout<<rem<<"@"<<" "<<primes.size()<<endl;
			int fi=start;
			if (rem)
				fi=start+(primes[i]-rem);
			//cout<<i<<" "<<primes[i]<<" "<<fi<<endl;
			for (int j=fi;j<=start+BLOCK;j+=primes[i]){
			//	cout<<j<<" "<<start<<endl;
				pr[j-start]=1;
			}
		}
		for (int j=0;j<BLOCK;j++){
			if (pr[j]==0){
				int val=j+start;
				if (val>n||val==1)
					continue;
				unsigned int here=solver(val);
				ans+=polyn(val)*here;
			//	cout<<val<<endl;
			}
		}
	}

	for (int i=0;i<primes.size();i++){
		int val=primes[i];
		if (val>n)
			continue;
		//cout<<val<<endl;
		unsigned int here=solver(val);
		ans+=polyn(val)*here;
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}