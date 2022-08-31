/*
Femininity, a sacred life
My goals and dreams achieved, or soon they might
Unintruded being, innocent
Young, with a hopeful future to be spent

I can't believe my idiocy
You came along with your invasion
Your act of violence not of lust
Upon me...

Racing through these darkened streets at night
Fleeing from this terror that haunts me
I am chosen, this can't be right
The pain that your thrust brings

I don't want your flesh
I'm not your whore
But you want my blood
I'm not a whore
Trapped down here inside
A nightmare that's become reality
A heinous violation
Of my humanity

Right before my eyes I see my world
Fractured so precise by one so cold
Through your veins run ice, I beg of thee
As I lie paralyzed please let me be

From within your soul I stare
I don't think I'll live to see this end
You'll reign eternally through my nightmares
If I ever sleep again

The hatred directed at me 'cause of what I am
Is as chilling as the defilement itself
I wonder, what kind of beast is man?
What emotions are and not felt?

I don't want your flesh
I'm not your whore
But you want my blood
I'm not a whore
I can't even comprehend
Why this act has come to be
Proven time and time again
The ultimate sadistic release

This violent form of incarceration
Trapped by savagery, helpless I lie
I refuse this indoctrination
Though you shatter this inner sanctum of mine

An ancient inherited shame
Bonding women and horror
Outlasting the boundaries of time
Enslaved forevermore

Inherent crimes
Through generations has become
A terror cycle...

You can't see me but you feel me
You only want what you don't understand
You can't have me so you take me
Forever scarred where you've stamped your brand

You look in my eyes and you tell me
What do you see?
Of this I'm deserving?

You can't see me but you feel me
You only want what you don't understhand
You can't have me so you take me
Forever scarred where you've stamped your brand

You need to crush me with your lividity
Does this make you feel more like a man
You can't have me, so you rape me
My innocence strangled by your hand

This must be necrophilia, for I am dead inside
Your violent misogyny, your strength drowns my cries
In shock, I'm crippled with disbelief
This can't be happening to me
Oh god, this hurts, I'm bleeding from friction
"Unconcious" I'm pleading to be...

You cannot imagine the anger I feel
Nor can you imagine the pain and despair
This double jeopardy soon happens again
When they scrape me for semen and hair
My mind is frozen with your face intact
This atrocity from which I haven't been spared
From now on, I'll only know lovemaking through
An act of intense terror

The malevolence which pours over me
You fill me with your rage
It's mortifying, diabolical,
Controlling through this stage
I struggle to cope with what's happening
I'm praying for my death
I've done nothing wrong, I've been victimized
So I'll pray for yours instead

The physical torment inflicted on me
Is insufferable but it doesn't compare
To your terrible criminal mentality
And the scars I'll forever bear
To live through this brutal show of force
Will cause me years of torment and grief
Awaiting this misery to run its course
As I scream out innocent pleas

This violent form of incarceration
Trapped by savagery, helpless I lie
I refuse this indoctrination
Though you shatter this inner sanctum of mine

An ancient inherited shame
Bonding women and horror
Outlasting the boundaries of time
Enslaved forevermore

I will force myself to carry on
And vengeance will be ultimately mine
If you are not imprisoned soon
By my hands you will die...

I don't what your flesh
I'm not your whore
But you wnat my blood
I'm not a whore
Through rape you've created me
A victim not above revenge
A churning, seething mass of hate
But you haven't conquered my soul
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

const int N = 1100031;

long long fact[N],invf[N];
long long n,m,a,b,m_pw[N];

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
	if (n<m)
		return 0;
	long long ret=fact[n];
	ret*=invf[m];
	ret%=bs;
	ret*=invf[n-m];
	return ret%bs;
}

long long ans;

long long solve(int path_length){
	long long ways=1;
	if (path_length>m)
		return 0;
	long long ways_to_set_weights=C(m-1,path_length-1);
	long long ways_to_pick_inner_vertices=C(n-2,path_length-1);
	ways*=ways_to_set_weights;
	ways%=bs;
	ways*=ways_to_pick_inner_vertices;
	ways%=bs;
	// order of inner matters
	ways*=fact[path_length-1];
	ways%=bs;
	//n-1-path_length edges of arbitrary length
	ways*=m_pw[n-1-path_length];
	ways%=bs;

	int used_vertices=path_length+1;
	if (used_vertices<n)
	{
		ways*=pw(n,n-used_vertices-1);
	    ways%=bs;
	    ways*=used_vertices;
	    ways%=bs;
	}

	//cout<<ways<<" "<<path_length<<endl;
	return ways;
}

set<vector<pair<int,int> > > solutions;
int used[N];
vector<pair<int,int> > edges;

int TTL;

void add_solution(vector<pair<int,int> > edges){
	sort(edges.begin(),edges.end());
	solutions.insert(edges);
}

void backtrack(){
	vector<int> a,b;
	for (int i=1;i<=TTL;i++){
		if (used[i])
			a.push_back(i);
		else
			b.push_back(i);
	}
	if (b.size()==0){
		add_solution(edges);
		return;
	}
	for (int i=0;i<a.size();i++){
		for (int j=0;j<b.size();j++){
			int v1=a[i];
			int v2=b[j];
			used[v1]=used[v2]=1;
			pair<int,int> p;
			if (v1<v2)
				p=make_pair(v1,v2);
			else
				p=make_pair(v2,v1);
			edges.push_back(p);
			backtrack();
			edges.pop_back();
			used[v2]=0;
		}
	}
}


int count_sols(int chain, int to_add){
	TTL=to_add+chain;
	solutions.clear();
	for (int i=1;i<=TTL;i++){
		used[i]=0;
	}
	for (int i=1;i<=chain;i++){
		used[i]=1;
	}
	backtrack();

	return solutions.size();
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

   /* for (int i=1;i<=7;i++){
    	for (int ad=1;ad<=5;ad++){
    		cout<<i<<" "<<ad<<" "<<count_sols(i,ad)<<endl;
    	}
    }
*/
    fact[0]=1;
    for (int i=1;i<N;i++){
    	fact[i]=fact[i-1]*i%bs;
    }

    invf[N-1]=inv(fact[N-1]);
    for (int i=N-2;i>=0;--i){
    	invf[i]=(invf[i+1]*(i+1))%bs;
    }

   // cout<<invf[0]<<endl;

    cin>>n>>m>>a>>b;

    m_pw[0]=1;
    for (int i=1;i<=n;i++){
    	m_pw[i]=m_pw[i-1]*m%bs;
    }

    for (int path_length=1;path_length<=n-1;path_length++){
    	ans=ans+solve(path_length);
    	ans%=bs;
    }
    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}