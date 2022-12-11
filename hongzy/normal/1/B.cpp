#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

string s;
int T, cnt;

int INT(string s) {
	int k = 0, c = 1;
	for(int i=s.size()-1; i>=0; i--)
		k += c * (s[i] - 'A' + 1), c *= 26;
	return k;
}

string STR(int s) {
	int sz=0, i=0;
	stack<char> S;
	while(s) {
		int _push = s % 26;
		S.push(_push == 0 ? 'Z' : 'A' + _push - 1);
		s /= 26;
		if(_push == 0) s --; //Z
		sz ++;
	}
	string str;
	str.resize(sz);
	while(!S.empty()) str[i++] = S.top(), S.pop();
	return str;
}

bool Judge(string s) {
	int pos_R = s.find('R'), pos_C = s.find('C');
	if(pos_R < pos_C - 1 && pos_C > 1 && s[pos_C-1] >= '0' && s[pos_C-1] <= '9') return true;
	return false;
}

void Work1() {
	int pos_R = s.find('R'), pos_C = s.find('C'), x1;
	string x = s.substr(pos_C+1);
	stringstream Cg;
	Cg << x; Cg >> x1;
	cout << STR(x1) << s.substr(pos_R+1, pos_C - pos_R - 1) << endl;
}

void Work2() {
	int p = 0;
	for(int i=0; i<s.size(); i++)
		if(s[i] >= '0' && s[i] <= '9') {
			p = i;
			break;
		}
	cout << 'R' << s.substr(p) << 'C' << INT(s.substr(0, p)) << endl;
}

int main() {
	cin >> T;
	while(T --) {
		cin >> s;
		if(Judge(s)) Work1();
		else Work2();
	}
	return 0;
}