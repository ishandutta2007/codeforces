#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

string s;
lint t;

int n;

string decpart, sosupart;
int decinc;

int main(){
	cin >> n >> t;
	cin >> s;
	int p = 0;
	for(auto &i : s){
		if(i == '.'){
			p = 1;
			continue;
		}if(p == 0) decpart.push_back(i);
		else sosupart.push_back(i);
	}
	int st = -1, ed = -1;
	for(int i=0; i<sosupart.size(); i++){
		if(sosupart[i] >= '5'){
			st = i;
			break;
		}
	}
	if(st == -1){
		cout << decpart << "." << sosupart;
		return 0;
	}
	while(st >= 0 && t){
		t--;
		while(sosupart.size() > st) sosupart.pop_back();
		if(sosupart.size()) sosupart.back()++;
		else decpart.back()++;
		if(sosupart.size() && sosupart.back() == '5') st--;
		else break;
	}
	if(decpart.back() == '0' + 10){
		reverse(decpart.begin(), decpart.end());
		for(int i=0; i<decpart.size(); i++){
			if(decpart[i] > '9'){
				if(i == decpart.size() - 1) decpart.push_back('1');
				else decpart[i+1]++;
				decpart[i] = '0';
			}
		}
		reverse(decpart.begin(), decpart.end());
	}
	if(sosupart.empty()) cout << decpart;
	else cout << decpart << "." << sosupart;
}