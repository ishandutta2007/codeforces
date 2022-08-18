/*
This is the place
Where all the junkies go
Where time gets fast
But everything gets slow

Can I get some Vaseline
Step into a modern scene
Take a chance on that
Which seems to be
The making of a dream

I don't want to do it
Like my Daddy did
I don't want to give it
To my baby's kid

This is my calling
I said my darling
Shocking, appalling
All I can do to you
Hammers are falling
I said my darling
Shocking, appalling
All I can do to you

This is the place
Where all the devils plead
Their case to take from you
What they need

Can I isolate your gene
Can I kiss your dopamine
In a way I wonder
If she's living in a magazine

I don't want to say it
If it isn't so
I don't want to weigh it
But I've got to know

This is my calling
I said my darling
Shocking, appalling
All I can do to you
Hammers are falling
I said my darling
Shocking, appalling
All I can do to you

I saw you out there yesterday
What did you want to say
A perfect piece of DNA
Caught in a flashing ray
I caught you out there in the fray
What did you want to say
A masterpiece of DNA
Caught in a flashing ray

Can I smell your gasoline
Can I pet your wolverine
On the day my best friend died
I could not get my copper clean

I don't want to take it up
With Little Joe
I don't want to fake it
But I've got to know

This is my calling
I said my darling
Shocking, appalling
All I can do to you
Hammers are falling
I said my darling
Shocking, appalling
All I can do to you

I'm a misfit
I'm born with all of it
The fucking ultimate
Of love inside the atom split

I'm in a flash ray
A mash of DNA
Another poppin' Jay
Who thinks he's got
Something to say
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

vector<int> outer;
int cnt_with_tp[N];
int n;
string name[N];
int ocup[N];
int tp[N];

int get_num(string st){
	int res=0;
	for (int i=0;i<st.size();i++)
	{
		res=res*10+st[i]-48;
	}
	return res;
}

bool is_final_position(string st){
	if (st[0]=='0')
		return false;
	int here=get_num(st);
	return (here>=1&&here<=n);
}

// free0 for free positions in 0 zone
vector<int> free0,free1;

// bad0 for bad positions in 0 zone
vector<int> bad0,bad1;

vector<pair<string,string> > ans;

void write_down_move(string a,string b){
	ans.push_back(make_pair(a,b));
}

string get_string(int x){
	string res="";
	while (x)
	{
		res+=char(x%10+48);
		x/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}

string get_rand()
{
	string ret="";
	ret+=char(rand()%26+'a');
	for (int i=1;i<=5;i++)
	{
		ret+=char(rand()%10+48);
	}
	return ret;
}

bool is_ok(string st){
	for (int i=1;i<=n;i++)
	{
		if (name[i]==st)
			return false;
	}
	return true;
}

string get_rand_string(){

	srand(time(NULL));

	while (true){
		string here=get_rand();
		if (is_ok(here))
			return here;
	}
}

void move_to_outer(int id){
	string new_name=get_rand_string();
	write_down_move(name[id],new_name);
	//cout<<"move "<<name[id]<<" "<<new_name<<"\n";
	name[id]=new_name;
	outer.push_back(id);
}

void make_move(int from,int to){
	int id_to_move=ocup[from];
	ocup[from]=0;
	ocup[to]=id_to_move;
	write_down_move(get_string(from),get_string(to));
	//cout<<"move "<<from<<" "<<to<<"\n";
	name[id_to_move]=get_string(to);
}

void make_helper_move(){
	if (bad0.size()>0){
		int id=bad0.back();
		bad0.pop_back();
		free0.push_back(id);
		move_to_outer(ocup[id]);
		ocup[id]=0;
	}
	else
	{
		int id=bad1.back();
		bad1.pop_back();
		free1.push_back(id);
		move_to_outer(ocup[id]);
		ocup[id]=0;
	}
}

void resolve01()
{
	// everything is ok
	if (bad0.size()==0&&bad1.size()==0)
		return;
	// need some space
	if (free0.size()==0&&free1.size()==0)
	{
		make_helper_move();
	}

	while (bad0.size()||bad1.size()){
		if (free0.size()>0&&bad1.size()>0){
			int From=bad1.back();
			bad1.pop_back();
			int To=free0.back();
			free0.pop_back();
			free1.push_back(From);
			make_move(From,To);
		}
		if (free1.size()>0&&bad0.size()>0){
			int From=bad0.back();
			bad0.pop_back();
			int To=free1.back();
			free1.pop_back();
			free0.push_back(From);
			make_move(From,To);
		}
	}
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>name[i];
		cin>>tp[i];
		cnt_with_tp[tp[i]]++;
		if (is_final_position(name[i])){
			ocup[get_num(name[i])]=i;
		}
		else
		{
			outer.push_back(i);
		}
	}

	// resolve 1..n

	for (int i=1;i<=cnt_with_tp[1];i++){
		if (ocup[i]==0){
			free1.push_back(i);
		}
		else
		{
			if (tp[ocup[i]]==0)
				bad1.push_back(i);
		}
	}

	for (int i=cnt_with_tp[1]+1;i<=n;i++)
	{
		if (ocup[i]==0){
			free0.push_back(i);
		}
		else
		{
			if (tp[ocup[i]]==1)
				bad0.push_back(i);
		}
	}

	resolve01();

	// add outer

	for (int i=1;i<=cnt_with_tp[1];i++){
		if (ocup[i]==0)
			free1.push_back(i);
	}
	for (int i=cnt_with_tp[1]+1;i<=n;i++)
	{
		if (ocup[i]==0)
			free0.push_back(i);
	}

	for (int i=0;i<outer.size();i++)
	{
		int id=outer[i];
		int where_to_put;
		if (tp[id]==0){
			where_to_put=free0.back();
			free0.pop_back();
		}
		else
		{
			where_to_put=free1.back();
			free1.pop_back();
		}
		write_down_move(name[id],get_string(where_to_put));
//		cout<<"move "<<name[id]<<" "<<where_to_put<<"\n";
	}

	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++)
	{
		cout<<"move "<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
	cin.get(); cin.get();
	return 0;
}