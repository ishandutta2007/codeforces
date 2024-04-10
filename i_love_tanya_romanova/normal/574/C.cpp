/*
Hold on to love, that is what I do
Now that I've found you
And from above, every thing's stinking
They're not around you

And in the night, I could be helpless
I could be lonely, sleeping without you
And in the day, every thing's complex
There's nothing simple when I'm not around you

But I miss you when you're gone
That is what I do, bay, bay, bay
And it's goin' to carry on
That is what I do, bay, bay, bay

Hold on to my hands
I feel I'm sinking, sinking without you
And to my mind, every thing's stinking
Stinking without you

And in the night, I could be helpless
I could be lonely, sleeping without you
And in the day, every thing's complex
There's nothing simple when I'm not around you

And I miss you when you're gone
That is what I do, bay, bay, bay
And it's goin' to carry on
That is what I do, bay, bay, bay

Bay, bay, bay
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000000
#define bsize 512
#define MAG 40

using namespace std;

int n,ar[1<<20];
int er;

int main(){
//freopen("center.in","r",stdin);
//freopen("center.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    while (ar[i]%2==0)
        ar[i]/=2;
    while (ar[i]%3==0)
        ar[i]/=3;
}

for (int i=2;i<=n;i++)
    if (ar[i]!=ar[1])
        er=1;

if (er)
    cout<<"No"<<endl;
else
    cout<<"Yes"<<endl;
    
//cin.get();cin.get();
return 0;}