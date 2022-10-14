#include<iostream>
#include<vector>

using namespace std;

int w, m;
vector <int> v;

int main () {
    cin >> w >> m;
    if (w<4) {
        cout << "YES";
        return 0;
    }
    while (m) {
        v.push_back(m%w);
        m/=w;
    }
    v.push_back(0);
    for (int i=0; i<v.size(); i++) {
        if (v[i]==w-1) v[i]++;
        if (v[i]==w) {
            v[i]=0;
            v[i+1]++;
        }
    }
    for (int i=0; i<v.size(); i++) {
        if (v[i]>1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}