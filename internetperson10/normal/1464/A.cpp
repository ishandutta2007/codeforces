#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> v1, v2;
bool stuff[100001];

int main() {
    int t, n, r, z, a, b;
    cin >> t;
    while(t--) {
        bool sad = false;
        cin >> n >> r;
        z = r;
        for(int i = 0; i <= n; i++) v1.push_back(-1);
        for(int i = 0; i < r; i++) {
            cin >> a >> b;
            v1[a] = b;
        }
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] == i) {
                v1[i] = -1;
                z--;
            }
            else if(v1[i] > 0) {
                int j = v1[i];
                v1[i] = -1;
                while(j > 0 && j != i) {
                    int k = v1[j];
                    v1[j] = -1;
                    j = k;
                }
                if(j > 0) z++;
            }
        }
        cout << z << '\n';
        vector<int>().swap(v1);
    }
}