#include<iostream>
#include<vector>
#include<string>
#include<stack>

using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;


int main() {
    int n;
    cin >> n;
    vector<vector<int> > data(3);
    data[0].push_back(1);
    data[0].push_back(2);
    data[1].push_back(1);
    data[1].push_back(3);
    data[2].push_back(2);
    data[2].push_back(3);
    int k = 3;
    int sum = 3;
    while (sum + k <= n) {
        vector<int> newData(k);
        for (int i = sum + 1; i < sum + k + 1; ++i) {
            data[i - sum - 1].push_back(i);
            newData[i - sum - 1] = i;
        }
        data.push_back(newData);
        sum = sum + k;
        ++k;
    }
    cout << data.size() << endl;
    for (int i = 0; i < data.size(); ++i) {
        for (int j = 0; j < data[i].size(); ++j)
            cout << data[i][j] << " ";
        cout << endl;
    }

    
    return 0;
}