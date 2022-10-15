#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>

using std::sqrt;

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;

struct point {
	int x, y;
};

struct vec {
	int x, y;
	bool operator == (vec rhs) {
		return ((x == rhs.x) && (y == rhs.y));
	}
	int d() {
		return x * x + y * y;
	}
	
};

int scal(vec lhs, vec rhs) {
		return (lhs.x * rhs.x + lhs.y * rhs.y);
}


bool checkPr(vector<point> data) {
	vec v1, v2, v3, v4;
	vec z;
	z.x = z.y = 0;
	v1.x = data[1].x - data[0].x;
	v1.y = data[1].y - data[0].y;
	v2.x = data[2].x - data[1].x;
	v2.y = data[2].y - data[1].y;
	v3.x = -data[3].x + data[2].x;
	v3.y = -data[3].y + data[2].y;
	v4.x = -data[0].x + data[3].x;
	v4.y = -data[0].y + data[3].y;
	if ((v1 == v3) && (v2 == v4)) {
		if (z == v1)
			return false;
		if (z == v2)
			return false;
		if (z == v3)
			return false;
		if (z == v4)
			return false;
		if (scal(v1, v2) == 0)
			return true;
	}
	return false;
}

bool checkSq(vector<point> data) {
	vec v1, v2, v3, v4;
	vec z;
	z.x = z.y = 0;
	v1.x = data[1].x - data[0].x;
	v1.y = data[1].y - data[0].y;
	v2.x = data[2].x - data[1].x;
	v2.y = data[2].y - data[1].y;
	v3.x = -data[3].x + data[2].x;
	v3.y = -data[3].y + data[2].y;
	v4.x = -data[0].x + data[3].x;
	v4.y = -data[0].y + data[3].y;
	if ((v1 == v3) && (v2 == v4)) {
		if (z == v1)
			return false;
		if (z == v2)
			return false;
		if (z == v3)
			return false;
		if (z == v4)
			return false;
		if ((scal(v1, v2) == 0) && (v1.d() == v2.d()))
			return true;
	}
	return false;
}


int main() {
        int n;
        cin >> n;
        vector<int> data(n);
        for (int i = 0; i < n; ++i)
                cin >> data[i];
		if (n == 1) {
			if (data[0] == 1) {
				cout << 2 << endl;
				return 0;
			}
			else {
				cout << 1 << endl;
				return 0;
			}
		}
        sort(data.begin(), data.end());
        if (data[n - 1] == 1)
                ++data[n - 2]; 
        cout << 1 << " ";
        for (int i = 1; i < n; ++i)
                cout << data[i - 1] << " ";
        cout << endl;   
        return 0;
}


//int main() {
//	int ed1, ed2, n;
//	ed1 = ed2 = n = 0;
//	char c;
//	vector<char> data;
//	while(scanf("%c", &c) > 0) {
//		
//		if (c == '1') {
//			++ed1;
//			++ed2;
//			++n;
//		data.push_back(c);
//		}
//		if (c == '?') {
//			++ed1;
//			++n;
//		data.push_back(c);
//		}
//		if (c == '0') {
//			++n;
//		data.push_back(c);
//		}
//
//	}
//	vector<bool> ans(4, false);
//	/*if (ed1 >= n - ed1 + 2)
//		ans[0] = true;
//	if (n - ed2>= ed2 + 2)
//		ans[3] = true;*/
//	if (n % 2 == 0) {
//		int k = n / 2;
//		if (ed1 > k)
//			ans[3] = true;
//		if (ed2 < k)
//			ans[0] = true;
//		if ((ed2 <= k) && (k <= ed1)) {
//			vector<char> data0 = data;
//			vector<char> data1 = data;
//			int i = 0;
//			while(k - ed2 > 0) {
//				if (data[i] == '?') {
//					data1[i] = '1';
//					++ed2;
//				}
//				++i;
//			}
//			for (int j = i; j < data.size(); ++j)
//				data1[j] = '0';
//			i = data.size() - 1;
//			while(ed1 - k > 0) {
//				if (data[i] == '?') {
//					data0[i] = '1';
//					--ed1;
//				}
//				--i;
//			}
//			for (int j = i; j > -1; --j)
//				data0[j] = '0';
//			
//			if (data0[data.size() - 1] == '0')
//				ans[2] = true;
//			else
//				ans[1] = true;
//			if (data1[data.size() - 1] == '0')
//				ans[2] = true;
//			else
//				ans[1] = true;
//		}
//	}
//	else {
//		int k = n / 2;
//		if (ed1 > k + 1)
//			ans[3] = true;
//		if (ed2 < k)
//			ans[0] = true;
//		if (((ed2 <= k) && (k <= ed1))) {
//			vector<char> data0 = data;
//			vector<char> data1 = data;
//			int i = 0;
//			while(k - ed2 > 0) {
//				if (data[i] == '?') {
//					data1[i] = '1';
//					++ed2;
//				}
//				++i;
//			}
//			for (int j = i; j < data.size(); ++j)
//				if (data1[j] == '?')
//				data1[j] = '0';
//			i = data.size() - 1;
//			while(ed1 - k > 0) {
//				if (data[i] == '?') {
//					data0[i] = '1';
//					--ed1;
//				}
//				--i;
//			}
//			for (int j = i; j > -1; --j)
//				if (data1[j] == '?')
//				data0[j] = '0';
//			
//			if (data0[data.size() - 1] == '0')
//				ans[2] = true;
//			else
//				ans[1] = true;
//			if (data1[data.size() - 1] == '0')
//				ans[2] = true;
//			else
//				ans[1] = true;
//		}
//		else
//			if   ((ed2 <= k + 1) && (k + 1 <= ed1)){
//				vector<char> data0 = data;
//			vector<char> data1 = data;
//			int i = 0;
//			while(k + 1 - ed2 > 0) {
//				if (data[i] == '?') {
//					data1[i] = '1';
//					++ed2;
//				}
//				++i;
//			}
//			for (int j = i; j < data.size(); ++j)
//				if (data1[j] == '?')
//					data1[j] = '0';
//			i = data.size() - 1;
//			while(ed1 - k - 1> 0) {
//				if (data[i] == '?') {
//					data0[i] = '1';
//					--ed1;
//				}
//				--i;
//			}
//			for (int j = i; j > -1; --j)
//				if (data1[j] == '?')
//				data0[j] = '0';
//			
//			if (data0[data.size() - 1] == '0')
//				ans[2] = true;
//			else
//				ans[1] = true;
//			if (data1[data.size() - 1] == '0')
//				ans[2] = true;
//			else
//				ans[1] = true;
//			}
//	}
//		
//	if (ans[0])
//		cout << "00" << endl;
//	if (ans[1])
//		cout << "01" << endl;
//	if (ans[2])
//		cout << "10" << endl;
//	if (ans[3])
//		cout << "11" << endl;
//
//	return 0;
//}