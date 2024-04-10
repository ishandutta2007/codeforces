/*
Deluding in mystirium, innocent deliverance
Chosen minds are sailing, on waters of departure
Leaving spells of deceit, giving light to the blind
Dreaming with the war gods
Searching for the true bringers of life

Visions of tragedy, tearing you apart here
Their spirits following, about to begin this
Astral purgatory, screaming for the savior
Heavenly illusions burning
As they leave this darkened crypt behind

An aura in front of thee, reaches out for my hand
As tears fall from the trees, last days of freedom
Maybe I'm coming home, but should I get lost here
There's one thing guiding me
I won't be afraid to let it go

Reflection of rebirth
King god of the universe
Reflecting as you
Smell the ovens apocalyptic atmosphere
Perished nature harmony departed
I've got the feeling I know what you dream
Cryptic shadows darkening the screen

A different life's dimension
Watch them kill the world we used to know
Why am I the one that has to be there
Another life's reflection
Darker than the ones I've suffered through
Barricades that make us fear each other

No gods, no dictators
Don't force me to return
No gods, no frustration
Don't force me to return
To return

Enter the tragedy, as I stand in front of you
Take thy hand again, another spark of earth life
Over the continents, shadows getting closer
Darkening the firmament
Until you come and take them all away

Sounds of sirens echo through the black skies
Symphonies of sadness as, her soul cries
Cryptic shadows as the war is over
We shall not see the planet recover
*/

//#pragma comment(linker, "/STACK:16777216")
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 200000;

using namespace std;

int n,ar[N],R;
vector<pair<int, int> > v;
int ans;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
//	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
		v.push_back(make_pair(ar[i],i));
	}
	
	sort(v.begin(),v.end());
	
	R=0;
	for (int i=0;i<v.size();i++)
	{
		R=max(R,v[i].second);
		if (R==i+1)
			++ans;
	}
	cout<<ans<<endl;
	
	return 0;
}