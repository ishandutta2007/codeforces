#include<bits/stdc++.h>
using namespace std;

map < string , int > m;

int main(){
	int N , maxN = 0;
	string s , maxDir;
	cin >> N >> s;
	for(int i = 0 ; i < N - 1 ; i++)
		m[string(s , i , 2)]++;
	for(map < string , int > :: iterator it = m.begin() ; it != m.end() ; ++it)
		if(maxN < it->second){
			maxN = it->second;
			maxDir = it->first;
		}
	cout << maxDir;
	return 0;
}