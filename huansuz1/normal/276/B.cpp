#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;


map<char,int> mp;
int n,p,ma,z;
string s;

int main(){
    cin>>s;
    for (int i=0; i<s.length(); i++)
    	mp[s[i]]++;
    for (int i='a'; i<='z'; i++)
    	if (mp[i]%2==1) z++;
    if (z<=1 || s.length()==1) cout<<"First"; else {
    	z--;
    	if (z%2==1) cout<<"Second"; else cout<<"First";
    }
	return 0;
}