/*
Suspicion is your name
Your honesty to blame
Put dignity to shame
Dishonor
Witchhunt, modern day
Determining decay
The blatant disarray
Disfigure
The public eyes disgrace
Defying common place
Unending paper chase
Unending

Deafening
Painstaking
Reckoning
This vertigo it doth bring

Shortest straw
Challenge liberty
Downed by law
Live in infamy
Rub you raw
Witchhunt riding through
Shortest straw
The shortest straw has been pulled for you

Pulled for you
Shortest straw
Pulled for you
Shortest straw
Pulled for you
Shortest straw
The shortest straw has been pulled for you

The accusations fly
Discrimination, why?
Your inner self to die
Intruding
Doubt sunk itself in you
Its teeth and talons through
Youre living Catch-22
Deluding
A mass hysteria
A megalomania
Reveal dementia
Reveal

Secretly
Silently
Certainly
In vertigo you will be

Shortest straw
Challenge liberty
Downed by law
Live in infamy
Rub you raw
Witchhunt riding through
Shortest straw
This shortest straw has been pulled for you

Pulled for you
Shortest straw
Pulled for you
Shortest straw
Pulled for you
Shortest straw
Shortest straw has been pulled for you
Shortest straw
Pulled for you
Shortest straw
Pulled for you
Shortest straw
Pulled for you
Shortest straw
Shortest straw has been pulled for you

Behind you, hands are tied
Your being, ostracized
Your hell is multiplied
Upending
The fallout has begun
Oppressive damage done
Your many turned to none
To nothing
Youre reaching your nadir
Your will has disappeared
The lie is crystal clear
Defending

Channels red
One word said
Blacklisted
With vertigo make you dead

Shortest straw
Challenge liberty
Downed by law
Live in infamy
Rub you raw
Witchhunt riding through
Shortest straw
The shortest straw has been pulled for you
Pulled for you
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1100031;

int n;
string st;
int suf_min[N],pref_min[N],bal;
int ans;
int cur_bal;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    cin>>st;
    for (int i=0;i<st.size();i++){
    	if (st[i]=='(')
    		++bal;
    	else
    		--bal;
    }

    cur_bal=0;

    for (int i=0;i<st.size();i++){
    	if (st[i]=='(')
    		++cur_bal;
    	else
    		--cur_bal;
    	pref_min[i+1]=pref_min[i];
    	pref_min[i+1]=min(pref_min[i+1],cur_bal);
    }

    cur_bal=bal;
    suf_min[st.size()]=bal;

    for (int i=st.size()-1;i>=0;--i){
    	if (st[i]=='(')
    		--cur_bal;
    	else
    		++cur_bal;
    	suf_min[i]=suf_min[i+1];
    	suf_min[i]=min(suf_min[i],cur_bal);
    }

    for (int i=0;i<st.size();i++){
    	if (pref_min[i]<0)
    		continue;
    	int new_bal=bal;
    	if (st[i]==')')
    		new_bal+=2;
    	else
    		new_bal-=2;
    	if (new_bal!=0)
    		continue;
    	int new_suf=suf_min[i+1];
//    	cout<<i<<" "<<new_suf<<endl;
    	if (st[i]==')')
    		new_suf+=2;
    	else
    		new_suf-=2;
    	if (new_suf<0)
    		continue;
    	++ans;
    }

    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}