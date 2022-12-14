#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;

string arr[1003]; int N , M; bool vis[1003];

int main(){
	cin >> N >> M;
	for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
	vector < string > pot1 , pot2; string mid;
	for(int i = 1 ; i <= N ; ++i){
		string tmp = arr[i]; reverse(tmp.begin() , tmp.end());
		for(int j = i + 1 ; j <= N ; ++j)
			if(!vis[j] && arr[j] == tmp){
				vis[i] = vis[j] = 1; pot1.push_back(arr[i]); pot2.push_back(arr[j]);
			}
		if(!vis[i] && tmp == arr[i] && mid.empty()) mid = arr[i];
	}
	cout << (pot1.size() + (bool)mid.size() + pot2.size()) * M << endl;
	for(auto t : pot1) cout << t;
	cout << mid;
	reverse(pot2.begin() , pot2.end());
	for(auto t : pot2) cout << t;
	return 0;
}