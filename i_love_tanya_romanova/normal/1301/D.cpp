/*
Fulfilling morbid dreams
Of those who never have time to sleep
Enduring to extremes
Held by a promise that they won't keep
Dark silence is so real
Walls painted black as night
Locked up in chains of steel
Down in the cellar nothing is right

Mistress of perversity
Unwilling tool of other's lust
Witnessing abnormality
With no one left to trust
Hell couldn't be this bad
Sold by her father to gratify
She never had a chance
Raped, beaten, sodomized

Her martyred soul cries out
Yet no one hears her scream
Her world is fear and doubt
She's a prisoner of this grotesque scene

Mistress of perversity
She never had a chance
Raped, beaten, sodomized
Twisted urges drove her to the end
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
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1100031;

int n,m,k;

string build_solution(int n,int m){
	string ret="";

	// first col
	for (int i=2;i<=n;i++){
		ret+="D";
	}
	for (int i=n-1;i>=1;--i){
		ret+="U";
	}

	// all the rest cols
	for (int i=2;i<=m;i++){
		ret+="R";
		for (int j=2;j<=n;j++){
			ret+="D";
			ret+="L";
			ret+="R";
		}
		for (int j=n-1;j>=1;--j){
			ret+="U";
		}
	}

	for (int i=m-1;i>=1;--i){
		ret+="L";
	}
	return ret;
}

struct step
{
	int times;
	string pattern;
};

vector<step> compress(string st){
	vector<step> ret;
	int done=0;
	while (done<st.size()){
		int len=1;
		for (int q=done+1;q<=done+3&&q<st.size();q++){
			if (st[q]==st[done])
				break;
			len++;
		}
		if (len==4)
			len=3;

		//cout<<"@"<<len<<endl;

		int cnt=0;
		int old=done;
		while (true){
			if (done+len>st.size())
				break;
			int ok=1;
			for (int i=0;i<len;i++){
				if (st[old+i]!=st[done+i])
					ok=0;
			}
			if (ok){
				cnt++;
				done+=len;
			}
			else
				break;
		}
//		cout<<cnt<<endl;

		string temp="";
		for (int i=old;i<old+len;i++){
			temp+=st[i];
		}
		step S;
		S.times=cnt;
		S.pattern=temp;
		ret.push_back(S);
	}
	return ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m>>k;

    string S=build_solution(n,m);

   // cout<<S<<endl;
    if (S.size()<k){
    	cout<<"NO"<<endl;
    	return 0;
    }

    string my_moves="";
    for (int i=0;i<k;i++){
    	my_moves+=S[i];
    }

    vector<step> V=compress(my_moves);

    cout<<"YES"<<endl;
    cout<<V.size()<<endl;
    for (int i=0;i<V.size();i++){
    	cout<<V[i].times<<" "<<V[i].pattern<<endl;
    }

    //    cin.get(); cin.get();
    return 0;
}