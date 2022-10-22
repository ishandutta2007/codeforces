#include <bits/stdc++.h>

using namespace std;

vector<int> line;

int main() {
    int n, c, s=0;
    cin >> n;
    for(int a=0; a<n; a++) {
        cin >> c;
        line.push_back(c);
    }
    sort(line.begin(), line.end());
    c=0;
    for(int a=0; a<n; a++) {
        if(s<=line[a]) {
            c++;
            s+=line[a];
        }
    }
    cout << c;
}