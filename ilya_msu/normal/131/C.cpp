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



int main() {
        int n, m, t;
        cin >> n >> m >> t;
        long long answer = 0;
        vector<vector<long long> > data(31);
        data[0].push_back(1);
        for (int i = 1; i < 31; ++i) {
                data[i].resize(i + 1);
                data[i][0] = data[i][i] = 1;
                for (int j = 1; j < data[i].size() - 1; ++j) {
                        data[i][j] = data[i - 1][j - 1] + data[i - 1][j];
                }
        }
        for (int boys = 4; boys < t; ++boys) {
			long long x = 0;
			long long y = 0;
			if (boys <= n)
				x = data[n][boys];
			if (t - boys <= m)
				y = data[m][t - boys];
			answer += x * y;
        }
        cout << answer << endl;
        return 0;
}