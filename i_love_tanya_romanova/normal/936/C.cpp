/*
Pesticide in torrents, how fast it flows
Total pollution the earth can't stand much longer
Chemical industry brings new diseases
The fear of self-destruction is growing stronger
Nuclear waste in an uncontrolled deluge
Reduces the earth to an airless planet
Reformation lies far away
Now is your only chance to save it

Contamination in every place
Condemn the human race
Everything will decay
Broken down by toxic trace

New plagues have come and soon there'll be more
Apocalypse not for the first time
Suppression is alive and that's for sure
Everyone will be annihilated
Enforcement of the last eclipse
Can't ignore predictions from the past
Ignore the warnings of ancient prophets
Every minute of your life could be your last

Contamination in every place
Condemn the human race
Everything will decay
Broken down by toxic trace

Metamorphoses of the earth to a lifeless desert
Voracity for richness, ruin of mankind
Craving more and more, to the world's requiem
This is the earth's last century

Now deprivation from things that count, to make an easier life for me
Total confusions for the non-believers who ignore the writings on the wall
Times of suffering for everyone, no-one can hide from reality
Social injustice will be no more, without exception, devastate all

Times have changed from the past to now
The earth is mankind's subject
Perfect creation stands over all
Experimenting with lethal objects
Domination, submission, demand for more
De-humanizes the brains of the rulers
What gives them the right to menace us all
This time will come but then it will be too late
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 400031;

string st1,st2;
int n;
int cnt[N];

string st;

string apply(string st,int Q){
	string temp="";
	for (int i=st.size()-Q;i<st.size();i++){
		temp+=st[i];
	}
	string res=temp;
	reverse(res.begin(),res.end());
	for (int i=0;i<st.size()-Q;i++)
	{
		res+=st[i];
	}
	return res;
}

vector<int> apply_vec(vector<int> st,int Q){
	vector<int> temp;
	for (int i=st.size()-Q;i<st.size();i++){
		temp.push_back(st[i]);
	}
	vector<int> res=temp;
	reverse(res.begin(),res.end());
	for (int i=0;i<st.size()-Q;i++)
	{
		res.push_back(st[i]);
	}
	return res;
}

vector<int> entries[1000];

vector<int> v1,v2;

int done;

int get_ps(int what){
	for (int i=0;i<v1.size();i++){
		if (v1[i]==what)
			return i;
	}
	return -1;
}

vector<int> ans;

void DEBUG(){
	//cout<<st1<<endl;
}

void APPLY(int sz){
	if (sz==0)
		return;
	ans.push_back(sz);
	//cout<<"@@@"<<st1<<" "<<sz<<endl;
	st1=apply(st1,sz);
	v1=apply_vec(v1,sz);
	DEBUG();
}

void make_swap(int old,int nw){
	APPLY(st1.size()-old);
	APPLY(old-nw);
	APPLY(st1.size());
	++done;
}

void append_char(int ps_in_final){
	int should_be=done;
	int is_now=get_ps(v2[ps_in_final]);
	//cout<<is_now<<"@"<<should_be<<endl;
	/*for (int i=0;i<v1.size();i++){
		cout<<v1[i]<<" ";
	}
	cout<<endl;*/
	make_swap(is_now,should_be);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	/*cin>>st;
	for (int i=1;i<=6;i++){
		for (int j=1;j<=6;j++){
			for (int q=1;q<=6;q++){
				string temp=st;
				temp=apply(temp,i);
				temp=apply(temp,j);
				temp=apply(temp,q);
				if (temp[0]==st[2]&&temp[1]==st[1]&&temp[2]==st[0]&&temp[3]==st[5]){
					cout<<i<<" "<<j<<" "<<q<<" "<<temp<<endl;
				}
			}
		}
	}
*/
	cin>>n;
	cin>>st1;
	cin>>st2;
	for (int i=0;i<st1.size();i++){
		cnt[st1[i]]++;
		cnt[st2[i]]--;
	}

	for (int i='a';i<='z';i++){
		if (cnt[i]!=0){
			cout<<"-1"<<endl;
			return 0;
		}
	}

	for (int i=0;i<st1.size();i++){
		entries[st1[i]].push_back(i);
		v1.push_back(i);
	}

	for (int i=0;i<st2.size();i++){
		int here=entries[st2[i]].back();
		v2.push_back(here);
		entries[st2[i]].pop_back();
	}

	if (v2.size()%2==1){
		append_char(v2.size()/2);
		for (int i=0;i<v2.size()/2;i++){
			append_char(v2.size()/2-i-1);
			append_char(v2.size()/2+i+1);
		}
	}
	else
	{
		append_char(v2.size()/2-1);
		append_char(v2.size()/2);
		for (int i=1;i<v2.size()/2;i++){
			append_char(v2.size()/2-1-i);
			append_char(v2.size()/2+i);
		}
	}

	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++){
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	//cout<<st1<<endl;

//	cin.get(); cin.get();
	return 0;
}