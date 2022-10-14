#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;
struct st {
    vi s,g = {0};
    st(){
        s.reserve(300000),g.reserve(300000);
    }
    void push(int a) {
        g.push_back(gcd(a,g.back()));
        s.push_back(a);
    }
    int pop() {
        g.pop_back();
        auto tmp = s.back(); s.pop_back();
        return tmp;
    }
} s1,s2;

void add(int a) { s2.push(a); }

void remove() { // remove from queue front
    if(s1.s.empty()) while(!s2.s.empty())
        s1.push(s2.pop());
    s1.pop();
}

int gcdsegment() {
    return gcd(s1.g.back(),s2.g.back());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int ans=0;
    for(int i=0,j=0;i<n;++i) {
        int a; cin >> a;
        // need GCD queue
        add(a);
        while(gcdsegment()<i-j+1) {
            remove(), j++;
        }
        if(gcdsegment()==i-j+1) {
            ans++;
            while(j<=i) {
                remove(), j++;
            }
        }
        cout << ans << ' ';
    }
}