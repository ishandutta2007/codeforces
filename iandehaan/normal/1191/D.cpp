#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    bool cWins = true;
    int n;
    cin >> n;
    int stones[n];
    int twos = 0;
    int aTow = -1;
    int twoIndex = -1;
    int threes = 0;
    unordered_map<int, int> st;
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
        if (st.find(stones[i]) == st.end()) {
            st[stones[i]] = 0;
        }
        st[stones[i]]++;
        if (st[stones[i]] == 2) {
            twos++;
            aTow = stones[i];
            twoIndex = i;
        } else if (st[stones[i]] == 3) {
            threes++;
        }
    }
    if (threes > 0) {
        cout << "cslnb" << endl;
        return 0;
    } else if (twos > 1) {
        cout << "cslnb" << endl;
        return 0;
    } else if (twos == 1) {
        //cout << "twos one" << endl;
        //cout << aTow << endl;
        if (aTow == 0) {
            cout << "cslnb" << endl;
            return 0;
        }
        if (st.find(aTow-1) != st.end()) {
            cout << "cslnb" << endl;
            return 0;
        } else {
            //cout << "here" << endl;
            stones[twoIndex]--;
            cWins = !cWins;
        }
    }
    sort(stones, stones+n);
    for (int i = 0; i < n; i++) {
        int diff = stones[i]-i;
        if (diff % 2 == 1) {
            //cout << "change" << endl;
            cWins = !cWins;
        }
    }
    if (cWins) {
        cout << "cslnb" << endl;
    } else {
        cout << "sjfnb" << endl;
    }
}