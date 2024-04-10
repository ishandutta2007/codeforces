#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;

int get(const vector<string>& data, const vector<int>& per) {
    vector<string> ddata = data;
    for (int i = 0; i < data.size(); ++i)
        for (int k = 0; k < per.size(); ++k)
            ddata[i][k] = data[i][per[k] - 1];
    sort(ddata.begin(), ddata.end());
    int step = 1;
    int r = 0;
    for (int i = 0; i < per.size(); ++i) {
        r += step * (-ddata[0][per.size() - i - 1] + ddata.back()[per.size() - i - 1]);
        step *= 10;
    }
    return r;
}



int main() {
    int n, k;
    cin >> n >> k;
    vector<string> data(n);
    for (int i = 0; i < n; ++i)
        cin >> data[i];
    vector<int> factors(k + 1);
    factors[0] = 1;
    int min = 99999999;
    for (int i = 1; i < k + 1; ++i)
        factors[i] = factors[i - 1] * i;
    vector<int> per(k);
    for (int i = 0; i < factors[k]; ++i) {
        int i1 = i;
        for (int j = 0; j < k; ++j) {
            per[j] = i1 / factors[k - j - 1];
            i1 -= per[j] * factors[k - j - 1];
        }
        vector<bool> q(k, false);
        for (int j = 0; j < k; ++j) {
            int l = -1;
            int w = 0;
            while (l < per[j]) {
                if (!q[w])
                    ++l;
                ++w;
            }
            q[w - 1] = true;
            
            per[j] = w;
        }
    int m = get(data, per);
    if (m < min)
        min = m;
    }
    cout << min << endl;
    
    return 0;
}