/*
Off through the new day's mist I run
Off from the new day's mist I have come
I hunt
Therefore I am
Harvest the land
Taking of the fallen lamb

Off through the new day's mist I run
Off from the new day'smist I have come
We shift
Pulsing with the earth
Company we keep
Roaming the land while you sleep

Shape shift nose to the wind
Shape shift feeling I've been
Move swift all senses clean
Earth's gift back to the meaning of life

Bright is the moon high in starlight
Chill is the air cold as steel tonight
We shift
Call of the wild
Fear in your eyes
It's later than you realized

Shape shift nose to the wind
Shape shift feeling I've been
Move swift all senses clean
Earth's gift back to the meaning of life

I feel I change
Back to a better day
Hair stands on the back of my neck
In wildness is the preservation of the world

So seek the wolf in thyself

Shape shift nose to the wind
Shape shift feeling I've been
Move swift all senses clean
Earth's gift
Back to the meaning of wolf and man
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-9
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
long long n,l,a,q,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n;l=0;a=-13;
for (int i=1;i<=n;i++)
{cin>>q;if (q!=a){ans+=l*(l+1)/2;l=1;a=q;}else ++l;}
ans+=l*(l+1)/2;cout<<ans<<endl;
cin.get();cin.get();
return 0;
}