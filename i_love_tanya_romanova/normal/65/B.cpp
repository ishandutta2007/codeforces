/*
She looked right into my
eyes and said to me
The hurt that you try to
hide is killing me
You drink a thousand lies,
to freeze the past in time

I've tried to fill this
silence up
But now it's back again

See the pain in my eyes
see the scars deep inside
My God, I'm down in this
hole again
With the laughter I smile
with the tears that I cry
Keep going down this road
called life

She says that I'm insecure,
I guess she's right
'Cause just when I think
I'm sure, alone at night
the agonies come back, this
pain won't let me be

I try to fill the silence up
but now it's back again

See the pain in my eyes
see the scars deep inside
My God, I'm down in this
hole again
With the laughter I smile
with the tears that I cry
Keep going down this road
called life
Don't need your sympathy
I just want for this silence
to stop killing me

It's deafening
it's deafening
this silence inside me

I try to fill the silence up
but now it's back again
It's empty like a suicide
this pain inside

See the pain in my eyes
see the scars deep inside
My God, I'm down in this
hole again
With the laughter I smile
with the tears that I cry
Keep going down this road
called life
Don't need your sympathy
I just want for this silence
to stop killing me.
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long n;
string bound;
vector<string> ans;

string solve(string a,string l)
{
 string bst="9999";
 for (int i=0;i<4;i++)
 for (int j='0';j<='9';j++)
 {
     string b=a;
     b[i]=j;
     if (b>=l)bst=min(bst,b);
 }      
 return bst;
}

int main(){
//freopen("revolutions.in","r",stdin);
//freopen("revolutions.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
bound="1000";

for (int i=1;i<=n;i++)
{
    cin>>st;
    st=solve(st,bound);
    //cout<<bound<<" "<<st<<endl;
    bound=st;
    
    ans.push_back(st);    
}

/*for (int i=0;i<ans.size();i++)
cout<<ans[i]<<endl;
*/
if (ans[n-1]>"2011")cout<<"No solution"<<endl;
else for (int i=0;i<n;i++)
cout<<ans[i]<<endl;

cin.get();cin.get();
return 0;}