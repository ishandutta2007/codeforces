#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
bool flag;
ll tmp, tmpp;
string s;
stack<ll> st1, st2;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    st2.push(0);
    for (int i=0; i<n; i++) {
        cin >> s;

        if (s=="for") {
            cin >> m;

            st1.push((ll)m);
            st2.push(0LL);
        }

        if (s=="add") {
            tmp = st2.top();
            st2.pop();

            if (tmp+1 > (1LL<<32)-1) flag = true;

            st2.push(tmp+1);
        }

        if (s=="end") {
            tmp = st2.top();
            st2.pop();

            tmpp = st2.top();
            st2.pop();

            if (tmpp+tmp*st1.top() > (1LL<<32)-1) flag = true;

            st2.push(tmpp+tmp*st1.top());
            st1.pop();
        }

        if (flag) break;
    }

    if (flag) printf("OVERFLOW!!!");
    else printf("%lld", st2.top());
}