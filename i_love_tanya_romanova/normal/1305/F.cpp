/*
Tic toc, time is up
Tic toc, time is up!

(I know you!)
You're the one on the magazine covers and everyone loves ya
(Such a star!)
You're the one everyone wants to be like, but no one can be

Mother may I have a moment?
Feel I've come undone
Can you stop me from this spinning?
Nowhere left to run

Special's a term they use to describe someone when they're afraid to admit that they're right!

(I see you!)
You're the one that's in all of the movies, on everyone's TVs
(Such a farce!)
You're convinced that your shit doesn't stink and we all should adore you

Father can you stop this bleeding?
Hate what we've become
I've turned my cheek so many times
Fear I'm almost done!

Death is a term that they use to describe something they can't accept because it comes with a price!

Tic toc
Tic toc

Grant me the serenity to accept the things I cannot change, the courage to change the things I can and the wisdom to know the difference

Father can you stop this bleeding?
Hate what we've become
I've turned my cheek so many times
Fear I'm almost done!
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

long long gcd(long long a,long long b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

int n;
long long ar[N];

long long ans;
int pr[N];
vector<int> v_primes;

vector<long long> get_primes(long long val){
	vector<long long> ret;
	for (int i=0;;i++){
		if (1ll*v_primes[i]*v_primes[i]>val)
			break;
		if (val%v_primes[i])
			continue;
		ret.push_back(v_primes[i]);
		while (val%v_primes[i]==0)
			val/=v_primes[i];
	}
	if (val>1)
		ret.push_back(val);
	return ret;
}

set<long long> done;

void solver(long long val){
	if (done.find(val)!=done.end())
		return;
	done.insert(val);
	long long ttl=0;
	for (int i=1;i<=n;i++){
		long long ret_here=ar[i]%val;
		if (ar[i]>=val)
			ret_here=min(ret_here,val-ret_here);
		else
			ret_here=val-ret_here;
		ttl+=ret_here;
		if (ttl>=ans)
			break;
	}
	//cout<<ttl<<" "<<val<<endl;
	ans=min(ans,ttl);
}

int get_rand(int bound){
	int ret=0;
	for (int i=0;i<=60;i++){
		ret=ret*2+rand()%2;
		ret%=bound;
	}
	return ret+1;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    srand(time(NULL)+31);
    long long Q=rand()+31;

    for (int iter=1;iter<=31;iter++){
    	srand(Q);
    	Q=rand();
    }

    // ans <=n
    // therefore at least half of the numbers changed by at most 1
    // so 1/4 to guess a pair right away

    pr[1]=1;
    for (int i=2;i<N;i++){
    	if (pr[i]==0){
    		for (int j=i*2;j<N;j+=i){
    			pr[j]=1;
    		}
    	}
    }

    for (int i=2;i<N;i++){
    	if (pr[i]==0)
    		v_primes.push_back(i);
    }

    cin>>n;


    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    random_shuffle(ar+1,ar+n+1);

    for (int i=1;i<=n;i++){
    	if (ar[i]%2)
    		ans++;
    }

    while (true){
    	if (clock()*1.0/CLOCKS_PER_SEC>1.8)
    		break;
    	int id1=get_rand(n);
    	int id2=get_rand(n);
    	for (int dx=-1;dx<=1;dx++){
    		for (int dy=-1;dy<=1;dy++){
    			long long val1=ar[id1]+dx;
    			long long val2=ar[id2]+dy;
    			if (val1<1||val2<1)
    				continue;
    			long long Q=gcd(val1,val2);
    			vector<long long> V=get_primes(Q);
    			for (int q=0;q<V.size();q++){
    				solver(V[q]);
    			}
    		}
    	}
    }

    cout<<ans<<endl;

    //    cin.get(); cin.get();
    return 0;
}