/*
I was that kid sittin' over
in the corner,
smiling with a shit-eating
grin
And I was that kid smilin' in
the back of class
'cause I'm fryin' on mescaline
I was that kid drinkin' 40's
on the bleachers
getting drunk after school
Gettin' home too late,
fallin' on my face,
way too drunk to skate
and actin' a fool

I was that kid never doing
good at
nothing except for maybe
at P.E.
And I was that kid getting
bullied by the
Filipinos rolling with ABT
Me and my friends reading
the satanic bible thinking
we should start a band
Cutting class to jam,
cutting class to jam
In my dad's garage we
learned to

Act a fool - don't need to
be cool
Pissed off too and
breaking the rules
Mama told me stay in
school
don't rock 'n roll
But this is my American
high

I was that kid that was
crank-calling
your girlfriend, couldn't
get a goddamn date
And I was that kid that was
getting hella busted for
pissin' on the bart train
I fuckin' hated school
except for hanging out
with my friends, the
outcast that was
startin' up a band
Fremont was the town,
California-bound,
bay area sound, taught me
to

Act a fool - don't need to
be cool
Pissed off too and
breaking the rules
Mama told me stay in
school
don't rock 'n roll
But this is my American
high

I'm that kid you tried to
punk in English class
Now I'm in a band and
you're kissing my...

Asteroids beat out homework
Slayer beat out Zeppelin
Not the sharpest noggin
that's why I'm in this band

And what you got against
me, I don't need a new job
What you got against me,
I'll get by on my own
Tellin' me I'm never getting
by from my songs
I love it when you're
proven wrong

Act a fool - don't need to
be cool
Pissed off too and
breaking the rules
Mama told me stay in
school
don't rock 'n roll
But this is my American
high

Act a fool - don't need to
be cool
Break the rules
'cause this is my American
high.
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 2100031;

int n,a,b,reach[N];

vector<int> ans;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	scanf("%d",&n);
	scanf("%d",&a);
	scanf("%d",&b);

	reach[0]=1;
	for (int i=0;i<n;i++){
		if (reach[i]){
			reach[i+a]=a;
			reach[i+b]=b;
		}
	}

	if (reach[n]==0){
		cout<<-1<<endl;
		return 0;
	}

	int cur=n;
	int cur_done=0;

	while (cur>0){
		int next_cycle;
		if (cur>=a&&reach[cur-a]>0)
			next_cycle=a;
		else
			next_cycle=b;
		for (int i=cur_done+1;i<cur_done+next_cycle;i++){
			ans.push_back(i+1);
		}
		ans.push_back(cur_done+1);
		cur_done+=next_cycle;
		cur-=next_cycle;
	}

	for (int i=0;i<ans.size();i++){
		if (i)
			printf(" ");
		printf("%d",ans[i]);
	}
	cout<<"\n";

//	cin.get(); cin.get();
	return 0;
}