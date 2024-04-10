#include<iostream>
#include <cstdio>
#include<algorithm>
#include<map>
#include<string>
              
#define inf (1<<30) 
#define s second
#define sz 100000
#define f first

using namespace std;

map <string, int> mp, mpp;
map <string, int> :: iterator it;

int n, x[sz], ma=-inf;
string s[sz];

int main(){     
    cin>>n;

 	for (int i = 0; i < n; i++) {
 		cin>>s[i]>>x[i];
        mp[s[i]]+= x[i];
    }
    for ( it = mp.begin(); it != mp.end(); it++)
	    if ( (*it).s > ma)  
	    	ma=(*it).s;
	for (int i = 0; i < n; i++) {
		mpp[s[i]]+= x[i];
		if (mp[s[i]] == ma && ma <= mpp[s[i]]) {
		 	puts(s[i].c_str());
		 	return 0;
		}
    } 
 	return 0;          
}