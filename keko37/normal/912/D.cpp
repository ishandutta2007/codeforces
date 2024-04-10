#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint n, m, r, k, maxa, maxb, sol;
llint a[MAXN], b[MAXN], pos[MAXN];
vector <llint> v;
set < pair <llint, int> > s;
set < pair <llint, int> > :: iterator it;

void ispis () {
    for (it=s.begin(); it!=s.end(); it++) {
        cout << (it->first) << " " << (it->second) << endl;
    }
}

int main () {
    cin >> n >> m >> r >> k;
    for (llint i=1; i<=n; i++) {
        llint lef=max(1LL, i-r+1);
        llint rig=min(i, n-r+1);
        llint val=rig-lef+1;
        maxa=max(maxa, val);
        a[val]++;
    }
    for (llint i=1; i<=m; i++) {
        llint lef=max(1LL, i-r+1);
        llint rig=min(i, m-r+1);
        llint val=rig-lef+1;
        v.push_back(val);
        maxb=max(maxb, val);
        b[val]++;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (llint i=1; i<=maxa; i++) {
        pos[i]=v.size()-1;
        s.insert(make_pair(i*maxb, i));
    }
    while (1) {
        it=s.end(); it--;
        llint val=it->first;
        llint ind=it->second;
        llint br=a[ind]*b[val/ind];
        if (k>br) {
            k-=br;
            sol+=br*val;
            s.erase(it);
            pos[ind]--;
            if (pos[ind]>=0) s.insert(make_pair(ind*v[pos[ind]], ind));
        } else {
            sol+=k*val;
            break;
        }
    }
    printf("%.10f", ((double) sol)/((n-r+1)*(m-r+1)));
    return 0;
}