/*
And the warm wind caressed me deeply
Gently touched my soul
Made me forget all dark thoughts
Sadness on its way
Sorrow nevermore to stay

I'm the mare in my dreams
I'm the scarred wrist I fear
I'm another life that will fade
Shadows of my haunted soul
The pain that will not end

Come take it all, burn it away
Let the sunshine in again
Stop the loneliness - make it sane
Twist the broken mirror into one
Make me believe the pain has gone
*/

#pragma GCC optimize("Ofast")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const long long bs = 1000000007;

const int N = 200031;

int tests,n,k;
string st;
int cnt[N];
int next_char;
int cur_count[N];

bool is_good(string st){
	for (int i='a';i<='z';i++){
		cur_count[i]=0;
	}
	for (int i=0;i<st.size();i++){
		cur_count[st[i]]++;
	}
	for (int i='a';i<='z';i++){
		if (cur_count[i]%k)
			return false;
	}
	return true;
}

int min_required(){
	int ret=0;
	for (int i=0;i<26;i++){
		int here=cnt[i]%k;
		if (here)
			ret+=k-here;
	}
	return ret;
}

int have_to_add[N];
vector<int> order;

void restore_string(int pref_len, int next_char){
	for (int i=0;i<26;i++){
		cnt[i]=0;
	}
	for (int i=0;i<pref_len;i++){
		cnt[st[i]-'a']++;
	}
	cnt[next_char]++;
	st[pref_len]=next_char+'a';
	for (int i=0;i<26;i++){
		have_to_add[i]=0;
		if (cnt[i]%k)
			have_to_add[i]=k-cnt[i]%k;
	}
	int to_spare=st.size()-pref_len-1;
	int total_forced=0;
	for (int i=0;i<26;i++){
		total_forced+=have_to_add[i];
	}
	to_spare-=total_forced;
	have_to_add[0]+=to_spare;
	order.clear();
	for (int i=0;i<26;i++){
		for (int j=0;j<have_to_add[i];j++){
			order.push_back(i);
		}
	}
	for (int i=pref_len+1;i<st.size();i++){
		st[i]=char(order[i-pref_len-1]+'a');
	}
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>k;
    	cin>>st;
    	for (int i=0;i<26;i++){
    		cnt[i]=0;
    	}
    	if (is_good(st)){
    		cout<<st<<endl;
    		continue;
    	}
    	for (int i=0;i<st.size();i++){
    		cnt[st[i]-'a']++;
    	}

    	int pref_len=-1;

    	for (int i=st.size()-1;i>=0;--i){
    		cnt[st[i]-'a']--;
    		if (pref_len!=-1)
    			break;
    		for (int j=st[i]-'a'+1;j<26;j++){
    			cnt[j]++;
    			if (min_required()<st.size()-i&&(min_required()%k==(st.size()-i-1)%k)){
    				pref_len=i;
    				next_char=j;
    				//cout<<i<<"@@@"<<j<<" "<<min_required()<<endl;
    				break;
    			}
    			cnt[j]--;
    		}
    	}
    	if (pref_len==-1){
    		cout<<-1<<endl;
    	}
    	else
    	{
    		//cout<<pref_len<<"@"<<next_char<<endl;
    		restore_string(pref_len,next_char);
    		cout<<st<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}