/*
A fallen time that's bygone
A crude elite that's from a distant zone
You turn a blind eye on what's "brave"
You don't know if it's the truth you told

Anger looks on the quiet dreaming
Seals the sense incandescent ones

Hold back desire for danger
A bet you lose, you'll have no way to turn
I see the man who lives and breathes corruption
Into a circle that you call your own

Don't run away, from the pain. A claim that you deal with
A power game, from within. Impossible for you to see this

Laid down the laws of deceit
The ones who cherish are the ones who'll go
Into the ashes of a tortured world
Only in mind's eye can you see a light

Harmony breaks, dark awakes, in old eyes - the trouble, feel it
Here to stay, mark the way, improvise the judgement hearing

Don't run away, from the pain. A claim that you deal with
A power game, from within. Impossible for you to see this

Anger looks on the quiet dreaming
Seals the sense incandescent ones

All remains of the glowing embers
Is a bleak cold irrelevance
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

#define bs 998244353

const int N = 610031;

int n;
vector<int> order;
int ar[N];
vector<pair<int,int> > V;

vector<pair<int,int> > compress(vector<int> v){
	sort(v.begin(),v.end());
	int cnt=0;
	vector<pair<int,int> > ret;
	for (int i=0;i<v.size();i++){
		if (i>0&&v[i]!=v[i-1]){
			ret.push_back(make_pair(v[i-1],cnt));
			cnt=0;
		}
		cnt++;
	}
	ret.push_back(make_pair(v.back(),cnt));
	return ret;
}

int dp[5031][5031];
int pref[5031][5031];

void recalc_pref(int row){
	for (int i=0;i<=n;i++){
		pref[row][i]=dp[row][i];
		if (i>0){
			pref[row][i]+=pref[row][i-1];
			pref[row][i]%=bs;
		}
	}
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

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	order.push_back(ar[i]);
    }

    V=compress(order);

   /* for (int i=0;i<V.size();i++){
    	cout<<V[i].first<<" "<<V[i].second<<endl;
    }*/

    for (int i=0;i<V.size();i++){
    	dp[1][i]=V[i].second;
    }

    for (int i=2;i<=n;i++){
    	recalc_pref(i-1);
    	for (int j=1;j<V.size();j++){
    		dp[i][j]=1ll*pref[i-1][j-1]*V[j].second%bs;
    	}
    }

  /*  for (int i=1;i<=n;i++){
    	for (int j=0;j<V.size();j++){
    		cout<<dp[i][j]<<" ";
    	}
    	cout<<endl;
    }*/

    fact[0]=1;
    for (int i=1;i<=n;i++){
    	fact[i]=fact[i-1]*i%bs;
    }

    for (int i=0;i<=n;i++){
    	invf[i]=inv(fact[i]);
    }

    long long ans=0;

    for (int i=1;i<=n;i++){
    	for (int j=0;j<V.size();j++){
    		long long pref=dp[i][j];
    		pref=pref*(V[j].second-1);
    		pref%=bs;
    		long long for_tail=n-i-1;
    		long long tail_ways=fact[for_tail];
    		long long ttl=(pref*tail_ways)%bs;
    		ans+=ttl;
    		ans%=bs;
    	}
    }

    cout<<ans*invf[n]%bs<<endl;

//    cin.get(); cin.get();
    return 0;
}