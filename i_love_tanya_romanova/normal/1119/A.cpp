/*
The north star always guides me
When winter skies are gray
And I wait for the sun when all ate one
I shall not betray
Calling at me
I'm waiting when all are led astray

Carry On my sons forever
Carry On when I am gone
Carry On for when the day is long
Forever Carry On
For as long as we together
Then forever Carry On

Darkness all around us
We don't close our eyes
No one's gonna ground us
We were born to fly
Comin' at us no stopping
Born to amplify

Carry On my sons forever
Carry On when I am gone
Carry On for when the day is long
Forever Carry On
For as long as we together
Then forever Carry On

Yea, be my brother
Fight to stay alive
All the world can't change us
With all their burned-out jive
Come get us now we're waiting
We won't ride and hide

Carry On my sons forever
Carry On when I am gone
Carry On for when the day is long
Forever Carry On
For as long as we together
Then forever Carry On

Now we're all together
Let's sing a fighting song
One hundred thousand riders
We can't all be wrong
Comin' at us no stopping
Always Carry On

Carry On my sons forever
Carry On when I am gone
Carry On for when the day is long
Forever Carry On
For as long as we together
Then forever Carry On
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

const int N = 610031;

int n,ar[N],ans,fi;

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
    }

    for (int i=2;i<=n;i++){
    	if (ar[i]!=ar[1]){
    		fi=i;
    		break;
    	}
    }

    for (int i=2;i<=n;i++){
    	if (ar[i]!=ar[fi])
    		ans=max(ans,i-fi);
    	if (ar[i]!=ar[1])
    		ans=max(ans,i-1);
    }

    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}