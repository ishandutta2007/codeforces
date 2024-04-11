#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, int>;
const int MAXN = 1000005;
const int mod = 1e9 + 7;

int n, k;
string s;
stack<int> stk;
bool fu[MAXN];

int main(){
	cin >> n >> k;
	cin >> s;
	int rem = (n - k) / 2;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '(') stk.push(i);
		else{
			if(rem > 0){
				fu[stk.top()] = 1;
				fu[i] = 1;
				rem--;
			}
			stk.pop();
		}
	}
	for(int i=0;i <s.size(); i++){
		if(!fu[i]) putchar(s[i]); 
	}
}