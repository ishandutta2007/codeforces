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
//const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 7;

vector<int> z(string s) {
	int n = s.length();
	vector<int> res(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			res[i] = min(r - i + 1, res[i - l]);
		while(i + res[i] < n && s[res[i]] == s[i + res[i]])
			++res[i];
		if (i + res[i] - 1 > r)
			l = i,  r = i + res[i] - 1;
	}
	return res;
}

int com(string& s1, string& s2) {
    string s = s1 + s2;
    vector<int> a = z(s);
    for (int i = s1.size(); i < a.size(); ++i) {
        if (a[i] + i == a.size())
            return a[i];
    }
    return 0;
}

int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    string s1, s2, v;
    cin >> s1 >> s2 >> v;
    int n1 = s1.size(), n2 = s2.size(), n3 = v.size();
    vector<vector<string> > d1(n1 + 1, vector<string> (n3 + 1, "")), d2 = d1;
    string res = "";
    for (int j = 0; j < n2; ++j) {
        //cout << res << endl;
        for (int k = 0; k < n3; ++k) {
            string s = "";
            for (int i = 0; i < n1; ++i) {
                if (s.size() < d1[i][k].size()) 
                    s = d1[i][k];
                if (s2[j] == s1[i]) {
                    string ss = s + s1[i];
                    int k1 = com(v, ss);
                    if (k1 >= n3)
                        continue;
                    if (ss.size() > d2[i + 1][k1].size())
                        d2[i + 1][k1] = ss;
                    if (res.size() < ss.size())
                        res = ss;
                }
            }
        }
        d1 = d2;
    }
    
    if (res.empty())
        cout << 0 << endl;
    else
        cout << res << endl;
    return 0;
}