/*
Way, way down inside
There's a hollow soul
An emptiness shatters tomorrow

And I find it hard to breathe
For me in your company
Seems I've been taken for granted

And you're breaking me
And bleeding me down to nothing
It's tearing me down

You're breaking me
And bleeding me down to nothing
Yeah

Maybe, this time
Baby, it's meant to be
No more suffocating you or me
Oh, yeah

And I payed the price
But you're sentencing me to life
And I feel I bought in my time

And you're breaking me
And bleeding me down to nothing
It's tearing me down

You're breaking me
And bleeding me down to nothing
Again

Oh, you're breaking me
And bleeding me again
You're bleeding me, you're bleeding me

And you're breaking me
And bleeding me down to nothing
You're tearing me down

You're breaking me
And bleeding me down to nothing
You're tearing me, tearing me down again

Tearing me down again
You're breaking me
And bleeding me

Bleeding me again
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

string dig[100];
int macth[100][100];
string st;
int n;
int found_lcp;
int have;
int cur_sum;
string tst;
int match[200][200];

int matched(int x)
{
    if (x<n)
        return x+n;
    return x-n;
}

void remove_digit(int ps)
{
    int ps2=matched(ps);
    cur_sum-=match[st[ps]-'0'][st[ps2]-'0'];
}

void put_digit(int ps,int val)
{
    int ps2=matched(ps);
    cur_sum+=match[st[ps2]-'0'][val];
    st[ps]=val+48;
}

int naive_count(string st)
{
    int res=0;
    for (int i=0;i<n;i++)
        res+=match[st[i]-48][st[i+n]-48];
    return res;
}

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

dig[0]="1111110";
dig[1]="0110000";
dig[2]="1101101";
dig[3]="1111001";
dig[4]="0110011";
dig[5]="1011011";
dig[6]="1011111";
dig[7]="1110000";
dig[8]="1111111";
dig[9]="1111011";

for (int i=0;i<=9;i++)
    for (int j=0;j<=9;j++)
    {
        for (int q=0;q<dig[i].size();q++)
        {
            if (dig[i][q]=='1'&&dig[j][q]=='1')
                match[i][j]++;
        }
    }
cin>>st;

string tst=st;

n=st.size()/2;

//cout<<naive_count(st)<<"$"<<endl;

for (int i=0;i<n;i++)
    have+=match[st[i]-'0'][st[i+n]-'0'];

found_lcp=-1;

int suf=0;

cur_sum=have;

//cout<<"@"<<st<<"%"<<n<<endl;

for (int lcp=n*2-1;lcp>=0;lcp--)
{
    for (int q=st[lcp]-'0'+1;q<=9;q++)
    {
        //cout<<cur_sum<<"%"<<" "<<have<<"#"<<q<<" "<<st<<endl;
        remove_digit(lcp);
        //cout<<"#"<<cur_sum<<endl;
        put_digit(lcp,q);
        //cout<<"@@"<<cur_sum<<endl;
        if (cur_sum>have)
        {
            found_lcp=lcp;
            break;
        }
    }
    if (found_lcp!=-1)
        break;
    remove_digit(lcp);
    put_digit(lcp,8);
}

//cout<<cur_sum<<"   "<<have<<endl;

if (found_lcp==-1)
{
    cout<<-1<<endl;
    return 0;
}

for (int ps=found_lcp;ps<n*2;ps++)
{
    int val=tst[ps]-48;
    if (ps==found_lcp)
        val++;
    else
        val=0;
    for (int put=val;put<=9;put++)
    {
        remove_digit(ps);
        put_digit(ps,put);
        if (cur_sum>have)
            break;
//      cout<<st<<"#"<<cur_sum<<" "<<have<<" "<<naive_count(st)<<endl;
    }
//  cout<<st<<endl;
}

cout<<st<<endl;

//cout<<st<<" "<<tst<<" "<<found_lcp<<endl;

//cin.get();cin.get();
return 0;}