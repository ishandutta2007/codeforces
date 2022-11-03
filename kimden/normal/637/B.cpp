#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	map<string,int> m;
	map<int,string> m1;
	string a;
	int n,i;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a;
		m[a] = i+1;
	}
	for(auto k: m){
		m1[-k.second]=k.first;
	}
	for(map<int,string>::iterator k1=m1.begin();k1!=m1.end();k1++){
		if(k1!=m1.begin()){
			cout << "\n";
		}
		cout << k1->second;
	}
	return 0;
}