#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<pair<int,string> > v[100005];
int n, m;
char buf[100];

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,n) {
        int x, s;
        scanf(" %s %d %d", buf, &x, &s);
        v[x].emplace_back(s,buf);
    }
    FO(i,1,m+1) {
        sort(v[i].begin(),v[i].end()); reverse(v[i].begin(), v[i].end());
        if (sz(v[i]) == 2 || v[i][1].first != v[i][2].first) {
            printf("%s %s\n", v[i][0].second.c_str(),
                    v[i][1].second.c_str());
        } else printf("?\n");
    }
}