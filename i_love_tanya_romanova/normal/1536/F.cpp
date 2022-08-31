/*
Raise the sights, the city lights are calling
We're hot tonight, the time is right, there's nitro in the air
In the street is where we'll meet, we're warning
On the beat, we won't retreat, beware

Thousand of cars and a million guitars
Screaming with power in the air
We've found the place where the decibels race
This army of rock will be there

To ram it down, ram it down
Straight through the heart of this town
Ram it down, ram it down
Razing the place to the ground
Ram it down

Bodies revvin' in leather heaven in wonder
Lights are dimmin' and heads are swimmin' as thunder hits the stage
Hell breaks loose, turn on the juice get stronger
We metal maniacs begin to rave

Thousand of cars and a million guitars
Screaming with power in the air
We've found the place where the decibels race
This army of rock will be there

To ram it down, ram it down
Straight through the heart of this town
Ram it down, ram it down
Razing the place to the ground
Ram it down

Shout it out, we're all together now
Shout it out, we join as one, one

Thousand of cars and a million guitars
Screaming with power in the air
We've found the place where the decibels race
This army of rock will be there

To ram it down, ram it down
Straight through the heart of this town
Ram it down, ram it down
Razing the place to the ground
Ram it down
*/

#pragma GCC optimize("Ofast")
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

const long long bs = 1000000007;

const int N = 2100031;

map<string, int> score;
map<string,int> ::iterator it;

bool invalid(string st){
	for (int i=0;i<st.size();i++){
		if (st[i]=='.')
			continue;
		if(st[i]==st[(i+1)%st.size()])
			return true;
	}
	return false;
}

void minimax(string st){
	if (score.find(st)!=score.end())
		return;
	score[st]=-1;
	for (int i=0;i<st.size();i++){
		if (st[i]=='.')
		{
			for (int ad=0;ad<2;ad++){
				string temp=st;
				temp[i]=ad+'A';
				if (invalid(temp))
					continue;
				minimax(temp);
				if (score[temp]==-1)
					score[st]=1;
			}
		}
	}
}

void run_solver(int len){
	string temp="";
	for (int i=0;i<len;i++){
		temp+=".";
	}
	minimax(temp);
}

int ANS;

void count_ways(string st){
	int available_moves=0;
	for (int i=0;i<st.size();i++){
		for (int ad=0;ad<2;ad++){
			if (st[i]!='.')
				continue;
			string temp=st;
			temp[i]=ad+'A';
			if (invalid(temp))
				continue;
			if (score[temp]==1&&score[st]==1)
				continue;
			available_moves++;
			count_ways(temp);
		}
	}
	if (available_moves==0)
		++ANS;
	return;
}

long long fact[N],invf[N];

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

long long inv(long long x){
	return pw(x,bs-2);
}

long long C(long long n,long long m){
	if (m>n)
		return 0;
	long long res=fact[n];
	res*=invf[m];
	res%=bs;
	res*=invf[n-m];
	return res%bs;
}

int ar[N];

long long n,ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

   /* for (int i=2;i<=8;i++){
    	run_solver(i);
    	string S="";
    	for (int j=0;j<i;j++){
    		S+=".";
    	}
    	ANS=0;
    	count_ways(S);
    	cout<<i<<" "<<ANS<<" "<<ANS/i<<endl;
    }*/

    //for (it=score.begin();it!=score.end();it++){
    //	cout<<(*it).first<<" "<<(*it).second<<endl;
    //}

    fact[0]=1;
    for (int i=1;i<N;i++){
    	fact[i]=fact[i-1]*i%bs;
    }

    invf[N-1]=inv(fact[N-1]);
    for (int i=N-2;i>=0;--i){
    	invf[i]=invf[i+1]*(i+1);
    	invf[i]%=bs;
    }

/*    for (int n=2;n<=8;n++){
    	long long ans=0;
    	for (int mask=0;mask<(1<<n);mask++){
    		int c=0;
    		for (int i=0;i<n;i++){
    			if (mask&(1<<i))
    			 ar[i]=0;
    			else
    				ar[i]=1;
    		}
    		for (int i=0;i<n;i++){
    			if (ar[i]==1)
    				++c;
    		}
    		if (c%2==1)
    			continue;
    		int shit=0;
    		for (int i=0;i<n;i++){
    			if (ar[i]==0&&ar[(i+1)%n]==0)
    				shit=1;
    		}
    		if (shit==0)
    			ans+=2*fact[c];
    	}
    	cout<<n<<" "<<ans<<endl;
    }
*/

    cin>>n;
    ans=0;
    for (int ocup=2;ocup<=n;ocup+=2){
    	int holes=n-ocup;
    	if (holes==0){
    		ans+=2*fact[ocup];
    		ans%=bs;
    		continue;
    	}
    	//last isn't a hole; have n-holes positions, need to choose holes of them to have 0 in front
    	long long ways=C(n-holes,holes);
    	ans+=ways*2*fact[ocup];
    	ans%=bs;
    	// last is a hole
    	// n-holes positions left, pick holes-1 holes in front
    	// first can't be a hole, so n-holes-1 positions left
    	ways=C(n-holes-1,holes-1);
    	ans+=ways*2*fact[ocup];
    	ans%=bs;
    }
    cout<<ans<<endl;

    //cin.get(); cin.get();
    return 0;
}