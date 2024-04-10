#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

const int MAXN = 100005;

int n, w, h;
int g[MAXN], p[MAXN], t[MAXN];
int solx[MAXN], soly[MAXN];
set < pair <int, int> > s[2*MAXN], r[2*MAXN];
set < pair <int, int> > :: iterator it, it2;
vector <int> v;

void rjesi (int val) {
    v.clear();
    for (it=r[val].begin(); it!=r[val].end(); it++) {
        int pos=it->first;
        int ind=it->second;
        v.push_back(pos);
    }
    for (it=s[val].begin(); it!=s[val].end(); it++) {
        int pos=it->first;
        int ind=it->second;
        if (r[val].empty()) {
            solx[ind]=pos;
            soly[ind]=h;
            continue;
        }
        int noviy=r[val].begin()->first;
        it2=r[val].end(); it2--;
        //cout << "van ide " << (it2->first) << " " << (it2->second) << " " << r[val].size() << endl;
        solx[it2->second]=pos;
        soly[it2->second]=h;
        r[val].erase(it2);
        r[val].insert(make_pair(noviy-1, ind));
    }
    int br=0;
    for (it=r[val].begin(); it!=r[val].end(); it++) {
        int pos=it->first;
        int ind=it->second;
        solx[ind]=w;
        soly[ind]=v[br];
        br++;
    }
}

int main () {
    cin >> n >> w >> h;
    for (int i=0; i<n; i++) {
        scanf("%d%d%d", &g[i], &p[i], &t[i]);
        if (g[i]==1) {
            s[t[i]-p[i]+MAXN].insert(make_pair(p[i], i));
        } else {
            r[t[i]-p[i]+MAXN].insert(make_pair(p[i], i));
        }
    }
    for (int i=0; i<2*MAXN; i++) {
        rjesi(i);
    }
    for (int i=0; i<n; i++) {
        printf("%d %d\n", solx[i], soly[i]);
    }
    return 0;
}