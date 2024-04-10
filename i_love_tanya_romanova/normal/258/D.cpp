/*
Faintly arisen, tenderly torn
Dreamlike decision, unconsciously born

Firm in conviction yet tempt me they can
Deny me of trust and a demon I hide

A drive to be less than the fortunate
A dream in the casket of Eden
Crave that which you do not desire
Cling tightly to your deepest fear

I rose the greatest monument
Again and again
I bear the greatest treasure
Of time and a word

Treason spilt on the loneliest of graves
Desperation dealt the losing hand again
Wherein lie the purpose of the day?
Is there return in sadness?

Does your ceiling differ much from mine
Where we see each other?
Here in this light
Is that pillow more than a frame
That holds the chaos fast?
Now his hand a fist
Gain control

Silence fell and eyes now widened
Filling up the strength collapsing
Capable of the ending froze in the tracks
Brought to a bitter halt

On the floor it seems the steps are showing
Left a print just like it did in me
What has been and what will be
Never care 'cause I was in between
As I said with on afoot in loneliness
You hide here in me
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

#define bs 1000000007

const int N = 200031;

long double A[3031][3031];
int n,tests,ar[N];
int last_mod[N];
long long pw[N];
int T;

long long inv2;

long long P(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*P(a,b-1)%bs;
	return P(a*a%bs,b/2);
}

long long inv(long long x){
	return P(x,bs-2);
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    pw[0]=1;
    for (int i=1;i<N;i++){
    	pw[i]=pw[i-1]*2%bs;
    }

    inv2=inv(2);

    cin>>n>>tests;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=n;j++){
    		if (ar[i]>ar[j])
    			A[i][j]=1;
    	}
    }

    for (int i=1;i<=n;i++){
    	last_mod[i]=0;
    }

    for (int test=1;test<=tests;test++){
    	int a,b;
    	cin>>a>>b;
    	for (int i=1;i<=n;i++){
    		if (i!=a&&i!=b){
    			double here=A[a][i]+A[b][i];
    			here/=2;
    			A[a][i]=A[b][i]=here;
    			here=A[i][a]+A[i][b];
    			here=here/2;
    			A[i][a]=A[i][b]=here;
    		}
    	}
    	double here=A[a][b]+A[b][a];
    	here=here/2;
    	A[a][b]=A[b][a]=here;
    }


    long double ans=0;

    for (int i=1;i<=n;i++){
    	for (int j=i+1;j<=n;j++){
    		long double here=A[i][j];
    		ans+=here;
    	}
    }

    cout.precision(12);
    cout<<fixed<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}