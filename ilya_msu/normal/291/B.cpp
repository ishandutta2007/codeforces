#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000;

map<int, int> m;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//FILE* f = fopen("input.txt", "r");
	vector<string> res;
	int in = 0;
	string s;
	stringstream ss;
	char c;
	while(scanf("%c", &c) > 0) {
		if (c == '"') {
			if (in == 0) {
				in = 1;
				while (ss >> s)
					res.push_back(s);
				s = "";
			}
			else {
				in = 0;
				res.push_back(s);
				ss.clear();
			}
			continue;
		}
		if (in)
			s += c;
		else
			ss << c;
	}
	while (ss >> s)
		res.push_back(s);
	for (int i = 0; i < res.size(); ++i)
		//printf("<%s>\n", res[i]);
		cout << "<" << res[i] << ">\n";
	return 0;
}