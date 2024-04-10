/*
Looking at the pages of my life
Faded memories of me and you
Mistakes you know I've made a few
I took some shots and fell from time to time
Baby, you were there to pull me through
We've been around the block a time or two
I'm gonna lay it on the line
Ask me how we've come this far
The answer's written in my eyes

Every time I look at you, baby, I see something new
That takes me higher than before and makes me want you more
I don't wanna sleep tonight, dreamin's just a waste of time
When I look at what my life's been comin' to
I'm all about lovin' you

I've lived, I've loved, I've lost, I've paid some dues, baby
We've been to hell and back again
Through it all you're always my best friend
For all the words I didn't say and all the things I didn't do
Tonight I'm gonna find a way

Every time I look at you, baby, I see something new
That takes me higher than before and makes me want you more
I don't wanna sleep tonight, dreamin's just a waste of time
When I look at what my life's been comin' to
I'm all about lovin' you

You can take this world away
You're everything I am
Just read the lines upon my face
I'm all about lovin' you

Every time I look at you, baby, I see something new
That takes me higher than before and makes me want you more
I don't wanna sleep tonight, dreamin's just a waste of time
When I look at what my life's been comin' to
I'm all about lovin' you

All about lovin' you
*/
 
#pragma comment(linker, "/STACK:66777216")
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

string st;
int n;

bool solve()
{
    if (st.size()%n)return false;
    int one=st.size()/n;
    for (int i=0;i<st.size();i+=one)
    {
        string temp="";
        for (int j=i;j<i+one;j++)
            temp+=st[j];
        string temp1=temp;
        reverse(temp.begin(),temp.end());
        if (temp!=temp1)return false;
    }
    return true;
}

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
cin>>n;
if (solve())
    cout<<"YES"<<endl;
else
    cout<<"NO"<<endl;
    
//cin.get();cin.get();
return 0;}