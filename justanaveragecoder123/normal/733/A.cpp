#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define mp make_pair
#define xx first
#define yy second
#define pb push_back
#define sz(x) (int)((x).size())

string v="_AEIOUY";

bool isv(char t) {
	for(auto i:v) if(i==t) return true;
	return false;
}

int main() {
	string t;cin>>t;
	string all="_"+t;
	all+="_";
	int last=0;
	int ans=0;
	for(int i=0;i<sz(all);++i)
	{
		
		if(isv(all[i]))
		{
			
			ans=max(ans, i-last);
			last=i;
		}
	}
	cout<<ans<<"\n";
	return 0;
}