#include<iostream>
#include<vector>

using namespace std;

int main() {
int n;
cin >> n;
vector<int> data(n), answer;;
long long a = 0;
for (int i = 0; i < n; ++i) {
cin >> data[i];
a += data[i];
}
for(int i = 0; i < n; ++i)
if (data[i] * n == a)
answer.push_back(i + 1);
cout << answer.size() << endl;
for (int i = 0; i < answer.size(); ++i)
cout << answer[i] << endl;
return 0;
}