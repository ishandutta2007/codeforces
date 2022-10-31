#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#define ll long long
using namespace std;

int len[2345] , x[2345] , y[2345] , z[4321];
string s,t;
int N;
vector < pair < int  , int > >  v;


void Z( string s , string t , int start , bool rev ) {

	string S = s+"#"+t;
	int n = S.size() , sz = s.size() , l = 0 , r = 0;
	z[0]=0;
	for (int i = 1; i < n; i++) {
		z[i] = 0;
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && S[z[i]] == S[i+z[i]])
			z[i]++;
		if (i+z[i]-1 > r) {
			l = i;  r = z[i]+i-1; }

		if (i > sz) {
			int j = i-sz-1;
			if (len[j] < z[i]) {
				len[j] = z[i];
				x[j] = start;
				y[j] = start+z[i]-1;
				if(rev){
					x[j] = N - x[j] - 1;
					y[j] = N - y[j] - 1;
				}
			}
		}
	}


}

                                                                         


int main(){
	cin >> s >> t;
	N = s.size();
	for (int i=0; i<s.size(); i++) {
	    string q = "";
		for (int j = i; j < s.size(); j++)
			q += s[j];
		Z(q , t , i , 0);
	}
	reverse(s.begin() , s.end());
	for (int i=0; i<s.size(); i++) {
	    string q = "";
		for (int j = i; j < s.size(); j++)
			q += s[j];
		Z(q , t , i , 1);
	}
	int i = 0;
	while (i < t.size()) {
		v.push_back(make_pair(x[i]+1 , y[i]+1));
		if (len[i] == 0) { cout << -1; return 0; }
		i+=len[i];
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout<<v[i].first << " " << v[i].second << endl; 


    return 0;             
}