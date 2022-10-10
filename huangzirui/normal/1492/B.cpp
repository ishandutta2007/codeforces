#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int p[maxn];
int n;
vector<int> v;
int main() {
    int T;cin>>T;
    while (T--) {
        cin>>n;
        v.clear();
        for (int i = 1;i <= n;++i) {
            cin>>p[i];
            if (!v.size() || p[v.back()] < p[i])v.push_back(i);
        }
        v.push_back(n+1);
        for (int i = v.size()-2;~i;--i)
            for (int j = v[i];j < v[i+1];++j)printf("%d ",p[j]);
        puts("");
    }
    return 0;
}