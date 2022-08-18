/*
Well you just 17 and all you wanna do is disappear
You know what I mean there's a lot of space between
your ears
The way that you touch don't feel nothing
Hey hey hey hey, it was the D.N.A.
Hey hey hey hey, that made me this way
Do you know, do you know, do you know,
just how I feel
Sheer heart attack
Sheer heart attack
Real cardiac
I feel so in-articulate
Gotta feelin', gotta feelin', gotta feelin' like a paralyse
It ain't no, it ain't no, it ain't no, it ain't no surprise
Turn on the TV let it drip right down in your eyes
Hey hey hey hey, it was the D.N.A.
Hey hey hey hey, that made me this way
Do you know, do you know, do you know just how I
feel
Sheer heart attack
Sheer heart attack
Real cardiac
I feel so in-articulate
Do you know, do you know, do you know just how I
feel
Do you know, do you know, do you know, do you know
just how I feel
Sheer heart attack
Sheer heart attack
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
void solve(string st)
{
    for (int i=0;i<st.size();i++)
    {
        if (st[i]%8==0)
        {
            cout<<"YES"<<endl;
            cout<<st[i]<<endl;
            return ;
        }
    }
    for (int i=0;i<st.size();i++)
     for (int j=i+1;j<st.size();j++)
     {
        int num=st[i]-48;
        num=num*10+st[j]-48;
        if (num%8==0&&st[i]!='0')
        {
            cout<<"YES"<<endl;
            cout<<num<<endl;
            return ;
        }
     }
     
     for (int i=0;i<st.size();i++)
      if (st[i]>'0')
       for (int j=i+1;j<st.size();j++)
        for (int q=j+1;q<st.size();q++)
        {
            int num=st[i]-48;
            num=num*10+st[j]-48;
            num=num*10+st[q]-48;
            if (num%8==0)
            {
                cout<<"YES"<<endl;
                cout<<num<<endl;
                return ;
            }
        }
    cout<<"NO"<<endl;
}
int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
solve(st);

//cin.get();cin.get();
return 0;}