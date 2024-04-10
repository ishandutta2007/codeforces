/*
In a foreign field he lay
Lonely soldier, unknown grave
On his dying words he prays
Tell the world of Paschendale

Relive all that he's been through
Last communion of his soul
Rust your bullets with his tears
Let me tell you 'bout his years

Laying low in a blood filled trench
Kill time 'til my very own death
On my face I can feel the falling rain
Never see my friends again

In the smoke, in the mud and lead
Smell the fear and the feeling of dread
Soon be time to go over the wall
Rapid fire and end of us all

Whistles, shouts and more gun fire
Lifeless bodies hang on barbed wire
Battlefield nothing but a bloody tomb
Be reunited with my dead friends soon

Many soldiers eighteen years
Drown in mud, no more tears
Surely a war no-one can win
Killing time about to begin

Home, far away
From the war, a chance to live again
Home, far away
But the war, no chance to live again

The bodies of ours and our foes
The sea of death it overflows
In no man's land, God only knows
Into jaws of death we go

Crucified as if on a cross
Allied troops they mourn their loss
German war propaganda machine
Such before has never been seen

Swear I heard the angels cry
Pray to god no more may die
So that people know the truth
Tell the tale of Paschendale

Cruelty has a human heart
Every man does play his part
Terror of the men we kill
The human heart is hungry still

I stand my ground for the very last time
Gun is ready as I stand in line
Nervous wait for the whistle to blow
Rush of blood and over we go

Blood is falling like the rain
Its crimson cloak unveils again
The sound of guns can't hide their shame
And so we die on Paschendale

Dodging shrapnel and barbed wire
Running straight at cannon fire
Running blind as I hold my breath
Say a prayer symphony of death

As we charge the enemy lines
A burst of fire and we go down
I choke a cry but no-one hears
Feel the blood go down my throat

Home, far away
From the war, a chance to live again
Home, far away
But the war, no chance to live again

Home, far away
From the war, a chance to live again
Home, far away
But the war, no chance to live again

See my spirit on the wind
Across the lines, beyond the hill
Friend and foe will meet again
Those who died at Paschendale
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600000;

int n;
long long ar[N];
vector<long long> order;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
		order.push_back(ar[i]);
	}

	if (n==1){
		cout<<ar[1]<<endl;
		return 0;
	}

	sort(order.begin(),order.end());

	long long res=0;
	for (int i=0;i<order.size();i++){
		if (i==0)
			res+=-order[i];
		else if (i+1==order.size())
			res+=order[i];
		else
			res+=abs(order[i]);
	}

	cout<<res<<endl;

//	cin.get(); cin.get();
	return 0;
}