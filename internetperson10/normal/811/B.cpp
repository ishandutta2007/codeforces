#include <bits/stdc++.h>

using namespace std;

vector<int> book;

int main() {
    int n, q, c, l, r;
    cin >> n >> q;
    for(int a=0; a<n; a++) {
        cin >> c;
        book.push_back(c);
    }
    for(int a=0; a<q; a++) {
        int lessthan=0;
        cin >> l >> r >> c;
        l--;
        r--;
        c--;
        for(int b=l; b<=r; b++) {
            if(book[b]<book[c]) {
                lessthan++;
            }
        }
        cout << (lessthan==c-l ? "Yes\n" : "No\n");
    }
}