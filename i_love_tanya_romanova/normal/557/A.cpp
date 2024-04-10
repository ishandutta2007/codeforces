/*
He got retribution
He got loaded guns
Uses silver bullets in the chamber
And shoots them just for fun

He got the solution
Got long lasting pride
He got silver lining in his pocket
And a bag full of alibis

Hey baby, shine the light on me
As I shoot across the sky
Hey baby, I'm your Superman
And somebody gonna die

Got me spinning in circles
Got me towing the line
Got me into the mess I'm in
But the speed has made me blind

Got me spinning in circles
Hanging by a thread
If I had one wish to use, I swear it
I wish you were dead

It's a shallow constitution
It's only homicide
You only get what you make it to be
But your request is denied

Sweet electrocution
Sweeter than the bride
Put an X on the hollow eyes
So we all know that they've died

Hey baby, shine the light on me
As I shoot across the sky
It's all up to Batman
And somebody's gonna die, don't ask why

We got our retribution
Got the final done
We got the spark, we hit the mark
And the killing's just begun

Sweet electrocution
Sweeter by your side
Let it go, let it fly to the sky
And we die

Here we go again! [x2]

Got me spinning in circles
Got me towing the line
Got me into the mess I'm in
But the speed has made me blind

Got me spinning in circles
Hanging by a thread
If I had one wish to use, I swear it
I wish you were dead

Wish you were dead
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
#define bs 1000000007
#define bsize 512

using namespace std;

int n;
int l[10],r[10];
vector<int> av;
int rem;

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<3;i++)
{
    cin>>l[i]>>r[i];
}

for (int ans1=r[0];ans1>=l[0];--ans1)
{
    rem=n-ans1;
    if (rem<=r[1]+r[2]&&rem>=l[1]+l[2])
        {
            av.push_back(ans1);
            n-=ans1;
            break;
        }
}

for (int ans2=r[1];ans2>=l[1];--ans2)
{
    rem=n-ans2;
    if (rem>=l[2]&&rem<=r[2])
    {
        av.push_back(ans2);
        av.push_back(rem);
        break;
    }
}
for (int i=0;i<av.size();i++)
{
    if (i)cout<<" ";
    cout<<av[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}