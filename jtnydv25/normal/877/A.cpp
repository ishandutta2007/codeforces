#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

int cnt;
string arr[5] = {"Olya", "Slava", "Ann", "Nikita", "Danil"};
int main(){
	string s;
	cin >> s;
	int n = s.length();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 5; j++)
			if(i + arr[j].length() <= n && s.substr(i, arr[j].length()) == arr[j]){
				cnt++;
			}
	}
	if(cnt != 1) cout <<"NO";
	else cout << "YES";
}