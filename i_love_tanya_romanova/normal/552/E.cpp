/*
Crushing all your worthless goals
I define control
Your pain's my fucking ecstasy
So putrid is my world of tyranny

Accentuate your desperation
Flesh from bone, I'll rip and tear
I hate the fact
That we breathe the same air

Helpless, as I dominate
I won't celebrate
Until you've all been crucified
I can not rest 'til everyone has died

I can't stand the victim in you
Infecting everything that I do

I will eradicate
Obliterate, depopulate
Divine, atrocious suffering
Cleansation of the weak, supremacy

Pissing on your faith
Incinerate God's whore
Perpetual is my reign
I will eat your soul

Must maintain control of the weak

Must maintain control of the weak
Must contain the minds of the free
Must maintain control of the weak
Must contain the minds of the free
Must maintain control of the weak
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
#define bsize 256

using namespace std;

string st;
vector<long long> v1;
vector<char> v2;
pair<long long, long long> val1[1<<19],val2[1<<19];
long long ans;

int main(){
//freopen("towers.in","r",stdin);
//freopen("towers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
for (int i=0;i<st.size();i+=2)
{
    v1.push_back(st[i]-48);
}
for (int i=1;i<st.size();i+=2)
    v2.push_back(st[i]);

for (int pre=0;pre<v1.size();pre++)
{
    long long cur=v1[0];
    long long ttl=0;
    for (int i=0;i<pre;i++)
    {
        if (v2[i]=='*')
        {
            cur*=v1[i+1];
        }
        else
        {
            ttl+=cur;
            cur=v1[i+1];
        }
    }
    
    val1[pre]=make_pair(ttl,cur);
    //if (pre==0)
    //  val1[pre]=make_pair(0,0);
    ans=max(ans,ttl+cur);
}

reverse(v1.begin(),v1.end());
reverse(v2.begin(),v2.end());

for (int pre=0;pre<v1.size();pre++)
{
    long long cur=v1[0];
    long long ttl=0;
    for (int i=0;i<pre;i++)
    {
        if (v2[i]=='*')
        {
            cur*=v1[i+1];
        }
        else
        {
            ttl+=cur;
            cur=v1[i+1];
        }
    }
    
    val2[pre]=make_pair(ttl,cur);
    //if (pre==0)
    //  val2[pre]=make_pair(0,0);
}

reverse(v1.begin(),v1.end());
reverse(v2.begin(),v2.end());
/*
for (int i=0;i<v1.size();i++)
 cout<<val2[i].first<<"   "<<val2[i].second<<endl;
 
 cout<<endl;
for (int i=0;i<v1.size();i++)
 cout<<val1[i].first<<"   "<<val1[i].second<<endl;
 */
for (int start=0;start<v1.size();start++)
{
    long long cur=v1[start];
    long long ttl=0;
    for (int i=start;i+1<v1.size();i++)
    {
        if (v2[i]=='*')
        {
            cur*=v1[i+1];
        }
        else
        {
            ttl+=cur;
            cur=v1[i+1];
        }
        long long tans=0;
        
        long long coefmult,coefadd;
        coefmult=1;
        coefadd=0;
        if (start>0)
        {
            if (v2[start-1]=='*')
                coefadd+=val1[start-1].first,
                coefmult*=val1[start-1].second;
            else
                coefadd+=val1[start-1].first+val1[start-1].second;
        }
        int suf=0;
        if (i+2<v1.size())
        {
            suf=v1.size()-(i+2);
            if (v2[i+1]=='*')
                coefadd+=val2[suf-1].first,
                coefmult*=val2[suf-1].second;
            else
                coefadd+=val2[suf-1].first+val2[suf-1].second;
        }
        ans=max(ans,(cur+ttl)*coefmult+coefadd);
        //cout<<start<<"   "<<i<<" "<<(cur+ttl)*coefmult+coefadd<<" "<<coefmult<<" "<<coefadd<<" "<<suf<<" "<<cur<<"  "<<ttl<<endl;
    }
}
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}