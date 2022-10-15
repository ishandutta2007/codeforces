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





int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> symbols(26, 0);
    for (int i = 0; i < s.size(); ++i)
        ++symbols[(int)(s[i] - 'a')];
    int max = 0;
    char maxChar;
    for (int i = 0; i < 26; ++i)
        if (symbols[i] > max) {
            max = symbols[i];
            maxChar = 'a' + i;
        }
    vector<int> primes;
    vector<bool> numbers(s.size() + 1, true);
    for (int i = 2; i < numbers.size(); ++i) {
        if (numbers[i]) {
            primes.push_back(i);
            int i1 = i;
            while (i1 + i < numbers.size()) {
                i1 += i;
                numbers[i1] = false;
            }
        }
    }
    vector<int> data;

    for (int i = 0; i < primes.size(); ++i)
        if (primes[i] * 2 <= n) {
            data.push_back(primes[i]);
        }
    int x = 0;
    vector<bool> use(n + 1, false);
    for (int i = 1; i <=n; ++i) {
        for (int j = 0; j < data.size(); ++j)
            if (i % data[j] == 0)
                use[i] = true;
        if (use[i])
            ++x;
    }
    if (x > max) {
        cout << "NO" << endl;
        return 0;
    }
    else {
        cout << "YES" << endl;
        symbols[maxChar - 'a'] -= x;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (use[i + 1])
                cout << maxChar;
            else {
                while (symbols[k] == 0)
                    ++k;
                cout << (char)('a' + k);
                --symbols[k];
            }
        }
    }
    cout << endl;
    return 0;
}