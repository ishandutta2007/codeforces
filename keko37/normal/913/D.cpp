#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

typedef long long llint;

using namespace std;

const int MAXN = 200005;

int n, d;
int a[MAXN], t[MAXN];
vector <int> v, sol;

bool cmp (int br1, int br2) {
    return t[br1]<t[br2];
}

bool f (int k) {
    v.clear(); sol.clear();
    for (int i=0; i<n; i++) {
        if (a[i]>=k) v.push_back(i);
    }
    sort(v.begin(), v.end(), cmp);
    llint sum=0, br=0;
    for (int i=0; i<v.size(); i++) {
        sum+=t[v[i]];
        if (sum<=d) {
            br++;
            sol.push_back(v[i]);
        } else {
            break;
        }
    }
    return br>=k;
}

int main () {
    cin >> n >> d;
    for (int i=0; i<n; i++) {
        scanf("%d%d", &a[i], &t[i]);
    }
    int low=0, high=n, mid;
    while (low<high) {
        mid=(low+high+1)/2;
        if (f(mid)) {
            low=mid;
        } else {
            high=mid-1;
        }
    }
    f(low);
    cout << low << endl << low << endl;
    for (int i=0; i<low; i++) {
        cout << sol[i]+1 << " ";
    }
    return 0;
}