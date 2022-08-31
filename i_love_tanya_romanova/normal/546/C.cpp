/*
I wake up in the mornin'
And I raise my weary head
I got an old coat for a pillow
And the earth was last night's bed
I don't know where I'm goin'
Only God knows where I've been
I'm a devil on the run
A six gun lover
A candle in the wind, yeah

You're brought into this world
But they say you're born in sin
Well at least they've given me something
I didn't have to steal or have to win
Well, they tell me that I'm wanted
Yeah I'm a wanted man
I'm colt in your stable
I'm what Cain was to Able
Mister catch me if you can

I'm goin' down in a blaze of glory
(Down)
Take me now but know the truth
I'm goin' down in a blaze of glory
(Down)
Lord I never drew first
But I drew first blood
I'm no one's son
Call me young gun

You ask about my conscience
And I offer you my soul
You ask if I'll grow to be a wise man
Well I ask if I'll grow old
You ask me if I known love
And what it's like to sing songs in the rain?
Well, I've seen love come
I've seen it shot down
I've seen it die in vain

Shot down in a blaze of glory
(Down)
Take me now but know the truth
But I'm going down in a blaze of glory
(Down)
Lord, I never drew first
But I drew first blood
I'm a devil's son
Call me young gun
Yeah

Each night I go to bed
I pray the Lord my soul to keep
No, I ain't lookin' for forgiveness
But before I'm six foot deep
Lord, I got to ask a favor
And I'll hope you'll understand
'Cause I've lived life to the fullest
Let this boy die like a man
Starin' down the bullet
Let me make my final stand

Shot down in a blaze of glory
(Down)
Take me now but know the truth
I'm going down in a blaze of glory
(Down)
Lord, I never drew first
But, I drew first blood
I'm no one's son
Call me young gun

I'm the young gun
Young gun, yea eee yea
Young gun
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

int n,q,val;
vector<int> p1,p2;
int ans;

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>q;
for (int i=1;i<=q;i++)
{
    cin>>val;
    p1.push_back(val);
}
cin>>q;
for (int i=1;i<=q;i++)
{
    cin>>val;
    p2.push_back(val);
}

reverse(p1.begin(),p1.end());
reverse(p2.begin(),p2.end());

for (int iter=1;iter<=1000000;iter++)
{
    if (p1.size()==0)break;
    if (p2.size()==0)break;
    ans=iter;
    int v1=p1.back();
    int v2=p2.back();
    p1.pop_back();
    p2.pop_back();
    if (v1<v2)
    {
        p2.insert(p2.begin(),v1);
        p2.insert(p2.begin(),v2);
    }
    else
    {
        p1.insert(p1.begin(),v2);
        p1.insert(p1.begin(),v1);
    }
/*for (int i=0;i<p1.size();i++)
     cout<<p1[i]<<" ";
    cout<<endl;
    for (int i=0;i<p2.size();i++)
     cout<<p2[i]<<" ";
     cout<<endl;*/
}

if (p1.size()&&p2.size())cout<<-1<<endl;
else
{
    cout<<ans<<" ";
    if (p1.size())cout<<1<<endl;
    else cout<<2<<endl;
}
//cin.get();cin.get();
return 0;}