#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
using namespace std;

struct Vessel {
    int capacity, water;
    size_t fill_to;
};

vector<Vessel> vessels;

void fill_water(size_t p, int x) {
    stack<size_t> st;
    while(p < vessels.size() && vessels[p].water + x > vessels[p].capacity){
        st.push(p);
        x -= vessels[p].capacity - vessels[p].water;
        vessels[p].water = vessels[p].capacity;
        p = vessels[p].fill_to;
    }
    if(p < vessels.size())
        vessels[p].water += x;
    while(!st.empty()){
        vessels[st.top()].fill_to = p;
        st.pop();
    }
}

int main() {
    int n;
    cin >> n;
    vessels.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> vessels[i].capacity;
        vessels[i].water = 0;
        vessels[i].fill_to = i + 1;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int p, x;
            cin >> p >> x;
            fill_water(p - 1, x);
        } else {
            int k;
            cin >> k;
            cout << vessels[k - 1].water << endl;
        }
    }
    return 0;
}