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

int main() {
	int n;
	cin >> n;
	vector<room> data(n);

	for (int i = 0; i < n; ++i) 
		scanf("%d %d %d", &data[i].l, &data[i].w, &data[i].h);
	int m;
	cin >> m;
	vector<ob> data2(m);
	for (int i = 0; i < m; ++i) 
		scanf("%d %d %d", &data2[i].l, &data2[i].w, &data2[i].c);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		long long min = 500000001;
		for (int j = 0; j < m; ++j) {
			int per = 2 * (data[i].l + data[i].w);
			int q = per / data2[j].w;
			int r = per - q * data2[j].w;
			if (r != 0)
				++q;
			/*long long hei = q * data[i].h;
			int num = hei / data2[j].l;
			int res = hei - num * data2[j].l;
			if (res != 0)
				++num;
			long long result = data2[j].c * num;*/
			int nunu = data2[j].l / data[i].h;
			if (nunu == 0)
				continue;
			int num = q / nunu;
			int re = q - num * nunu;
			if (re != 0)
				++num;
			long long result  = num * data2[j].c;
			if (result < min)
				min = result;
		}
		sum += min;
	}
	cout << sum << endl;
    return 0;
}