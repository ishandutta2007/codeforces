/*
I'll wait here,
You're crazy,
Those vicious streets are filled with strays,
You should have never gone to Hollywood.

They find you,
To time you,
Say your the best they've ever seen,
You should have never trusted Hollywood.

I wrote you,
And told you,
You were the biggest fish out here,
You should have never gone to Hollywood.

They take you,
And make you,
They look at you in disgusting ways,
You should never trusted Hollywood.

I was standing on the wall,
Feeling ten feet tall,
All you maggots smoking fags on Santa Monica Boulevard,
This is my front page,
This is my new age,
All you bitches put your hands in the air and wave them like you just don't care.

All you maggots smoking fags out there on Sunset Boulevard.

All you bitches put your hands in the air and wave them like you just don't care.

Phoney people come to pray,
Look at all of them beg to stay,
Phoney people come to pray.

(The lines in the letter said, "We have gone to Hackensack")
Look at all of them beg to stay

Phoney people come to pray.

All you maggots smoking fags on Santa Monica Boulevard,
All you maggots smoking fags out there on Sunset Boulevard.
All you maggots smoking fags out there on Hollywood Boulevard.

You should have never trusted Hollywood.
You should have never gone to Hollywood.

All you bitches put your hands in the air and wave them like you just don't care.

You should have never trusted Hollywood.
*/

#include <math.h>
#include <iostream>
#include <algorithm>
//#include <fstream>
#include <string.h>
#define M_PI        3.14159265358979323846
using namespace std;
long long n,m,k,i,a[100100],b[100100],c[100100],x,j,ans;
int main()
{//freopen("race.in","r",stdin);freopen("race.out","w",stdout);
cin>>n>>m>>k;
for (i=1;i<=m;i++)cin>>
a[i]>>b[i]>>c[i];
for (j=1;j<=k;j++){
    cin>>x;
for (i=1;i<=m;i++)
{if (x>=a[i]&&x<=b[i])
ans+=c[i]+(x-a[i]);}
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}