#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {
    int k, c=0;
    cin >> k;
    int sum = k*-1;
    string s;
    cin >> s;
    int l = (int)s.at(0)-'0';
    for(int a=0; a<s.size(); a++) {
        arr.push_back((int)s.at(a)-'0');
        sum+=arr[a];
    }
    sort(arr.begin(), arr.end());
    for(c=0; c<arr.size() && sum<0; c++) {
            sum+=9;
            sum-=arr[c];
    }
    cout << c;
}