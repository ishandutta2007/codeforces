#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

long long n, sol;
int a[MAXN], b[MAXN];
priority_queue < pair <int, int> > pq;

int main () {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        pq.push(make_pair(a[i], 0));
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
        pq.push(make_pair(b[i], 1));
    }
    int r = 0;
    while (!pq.empty()) {
        int val = pq.top().first;
        int tip = pq.top().second;
        pq.pop();
        if (r == tip) {
            if (r == 0) sol += val; else sol -= val;
        }
        r = !r;
    }
    cout << sol;
	return 0;
}