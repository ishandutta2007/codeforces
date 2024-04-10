/*
Breaking down the Earth
No chance for rebirth
Everyone will die
even you and I

I won't be a slave
who's digging his own grave
like all the others
Don't turn your back on your brothers

Now it's too late
to change our fate
Someday the rain
will wash away the pain

Time is running out
and there's no return
We are the dying race
and we will burn
Every spirit will be gone
and mankind will fall
Cause this is the end of it all

We all love and hate
destroy and create
The future is well-known
Dust will turn to stone

Madness and insanity
Prisoners without a key
Trapped here in Paradise
But no one ever realizes

Now it's too late
to change our fate
Someday the rain
will wash away the pain

Time is running out
and there's no return
We are the dying race
and we will burn
Every spirit will be gone
and mankind will fall
Cause this is the end of it all

Time is running out
and there's no return
We are the dying race
and we will burn
Every spirit will be gone
and mankind will fall
Cause this is the end of it all
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

string st1,st2;
int found;

vector<int> parse(string st)
{
	for (int i=0;i<st.size();i++)
		if (st[i]=='.')
			st[i]=' ';
	stringstream s(st);
	int trash;
	vector<int> re;
	while(s>>trash)
	{
		re.push_back(trash);
	}
	return re;
}

int get_moment(vector<int> v)
{
	return v[0]+v[1]*1000+v[2]*1000000;
}

int get_length(int m,int y)
{
	if (m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		return 31;
	if (m!=2)
		return 30;
	if (y%4==0)
		return 29;
	return 28;
}

bool valid_day(int d,int m,int y)
{
//	cout<<d<<" "<<m<<" "<<y<<"%"<<get_length(m,y)<<endl;
	return d>=1&&d<=get_length(m,y);
}

bool invalid(vector<int> v)
{
//	cout<<v[1]<<"%"<<endl;
//	cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<valid_day(v[0],v[1],v[2])<<endl;
	return (!(v[1]>=1&&v[1]<=12&&valid_day(v[0],v[1],v[2])));
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st1;
cin>>st2;

vector<int> v1=parse(st1);
vector<int> v2=parse(st2);

sort(v2.begin(),v2.end());

do
{
	int D1=get_moment(v1);
	int D2=get_moment(v2);
	/*cout<<"#"<<D1<<" "<<D2<<endl;
	if (D2>D1)
	{
		D1=D1+100000000;
	}
	*/
	if (invalid(v2))
		continue;
//	cout<<D1<<" "<<D2<<" "<<v2[0]<<" "<<v2[1]<<" "<<v2[2]<<endl;
//	cout<<"!"<<D1<<" "<<D2<<endl;
	if (D1-D2>=18000000)
		found=1;
}
while (next_permutation(v2.begin(),v2.end()));

if (found)
	cout<<"YES"<<endl;
else
	cout<<"NO"<<endl;

//cin.get();cin.get();
return 0;}