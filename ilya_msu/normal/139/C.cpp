#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>

using std::sqrt;

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
//using std::min;
using std::max;
using std::set;

struct room {
	int l, w, h;
};

struct ob {
	int l, w, c;
};

bool rif(string s1, string s2, int k) {
	int i = s1.size() - 1;
	int x = 0;
	int x1, x2;
	while ((i >= 0) && (x < k)) {
		if ((s1[i] == 'a') || (s1[i] == 'e') || (s1[i] == 'i') || (s1[i] == 'o') || (s1[i] == 'u'))
			++x;
		--i;
	}
	if (x < k)
		return false;
	else
		x1 = i + 1;
	i = s2.size() - 1;
	x = 0;
	while ((i >= 0) && (x < k)) {
		if ((s2[i] == 'a') || (s2[i] == 'e') || (s2[i] == 'i') || (s2[i] == 'o') || (s2[i] == 'u'))
			++x;
		--i;
	}
	if (x < k)
		return false;
	else
		x2 = i + 1;
	if (s1.size() - x1 != s2.size() - x2)
		return false;
	for (i = x1; i < s1.size(); ++i)
		if (s1[i] != s2[i + x2 - x1])
			return false;
	return true;
}

int rifma(string s1, string s2, string s3, string s4, int k) {
	if (rif(s1, s2, k) && (rif(s3, s4, k)))
		if (rif(s1, s3, k))
			return 4;
		else return 1;
	else {};
	if (rif(s1, s3, k) && (rif(s2, s4, k)))
		return 2;
	if (rif(s1, s4, k) && (rif(s2, s3, k)))
		return 3;
	return 0;
}

int main() {
	int n, k;
	cin >> n >> k;
	string s1, s2, s3, s4;
	vector<bool> answer(4, true);
	for (int i = 0; i < n; ++i) {
		
			cin >> s1 >> s2 >> s3 >> s4;
			int x = rifma(s1, s2, s3, s4, k);
			if (x == 0) {
				cout << "NO" << endl;
				return 0;
			}
			if (x == 1)
				answer[2] = answer[3] = answer[1] = false;
			if (x == 2)
				answer[0] = answer[3] = answer[2] = false;
			if (x == 3)
				answer[3] = answer[1] = answer[0] = false;

	}
	
	if (answer[3])
		cout << "aaaa" << endl;
	else {
		if (answer[0])
		cout << "aabb" << endl;
		else
		if (answer[1])
		cout << "abab" << endl;
		else
		if (answer[2])
		cout << "abba" << endl;
		else
			cout << "NO" << endl;
	}

	
    return 0;
}