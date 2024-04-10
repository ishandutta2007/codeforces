#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

typedef long long llint;

using namespace std;

const int MAXN = 1005;

int n, sol;
int l[MAXN];
vector <int> v[MAXN];

int main () {
    cin >> n;
    for (int i=2; i<=n; i++) {
        int p;
        cin >> p;
        v[p].push_back(i);
    }
    for (int i=2; i<=n; i++) {
        if (v[i].size()==0) l[i]=1;
    }
    int br=0;
    for (int i=1; i<=n; i++) {
        if (l[i]) continue;
        br++;
        int cnt=0;
        for (int j=0; j<v[i].size(); j++) {
            int sus=v[i] [j];
            if (l[sus]) cnt++;
        }
        if (cnt>=3) sol++;
    }
    if (br==sol) cout << "Yes"; else cout << "No";
    return 0;
}