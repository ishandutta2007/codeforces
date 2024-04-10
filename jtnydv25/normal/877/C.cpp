#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

vector<int> vec;

int n;
void go(int i){
	if(i == n - 1){
		vec.push_back(i + 1);
		vec.push_back(i);
		if(n == 2) vec.push_back(i + 1);
		return ;
	}
	vec.push_back(i + 1);
	vec.push_back(i);
	go(i + 1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for(int i = 2; i <= n; i+= 2) vec.push_back(i);
	for(int i = 1; i <= n; i+=2) vec.push_back(i);
	for(int i = 2; i <= n; i+= 2) vec.push_back(i);

	cout << vec.size() << endl;
	for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
}