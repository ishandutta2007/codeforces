#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

struct p {
    ll x[3];

    p() {
        FO(i,0,3)x[i]=0;
    }

    bool operator<(const p &o) const {
        FO(i,0,3) if (x[i] != o.x[i]) return x[i] < o.x[i];
        return false;
    }
    bool operator==(const p &o) const {
        FO(i,0,3) if (x[i] != o.x[i]) return false;
        return true;
    }
};

ll dot(p a, p b) {
    ll r = 0;
    FO(i,0,3) r += a.x[i] * b.x[i];
    return r;
}

p sub(p a, p b) {
    p r;
    FO(i,0,3) r.x[i] = a.x[i] - b.x[i];
    return r;
}

p add(p a, p b) {
    p r;
    FO(i,0,3) r.x[i] = a.x[i] + b.x[i];
    return r;
}

ll d(p a, p b) {
    ll r = 0;
    FO(i,0,3) r += (a.x[i] - b.x[i]) * (a.x[i] - b.x[i]);
    return r;
}

bool issq(vector<p> v) {
    FO(i,1,sz(v)) v[i] = sub(v[i],v[0]);
    v[0] = p();
    ll md = 1e15;
    FO(i,1,sz(v)) md = min(md, d(v[0],v[i]));
    if (md == 0) return false;

    int cl[3], cls = 0;
    FO(i,1,sz(v)) if (d(v[0],v[i]) == md) {
        if (cls == 3) return false;
        cl[cls++] = i;
    }
    if (cls != 3) return false;
    FO(i,0,3) FO(j,0,i) if (dot(v[cl[i]],v[cl[j]])) return false;
    vector<p> nv;
    nv.push_back(p());
    FO(i,0,3) nv.push_back(v[cl[i]]);
    FO(i,0,3) FO(j,0,i) nv.push_back(add(v[cl[i]],v[cl[j]]));
    nv.push_back(add(v[cl[0]],add(v[cl[1]],v[cl[2]])));
    sort(nv.begin(),nv.end());
    sort(v.begin(),v.end());
    return nv == v;
}

vector<p> v(8);

void f(int c) {
    if (c == 8) {
        if (issq(v)) {
            printf("YES\n");
            FO(i,0,8) {
                FO(j,0,3) printf("%lld ", v[i].x[j]);
                printf("\n");
            }
            exit(0);
        }
    } else {
        do {
            f(c+1);
        } while (next_permutation(v[c].x, v[c].x+3));
    }
}

int main() {
    FO(i,0,8) {
        FO(j,0,3) scanf("%lld", &v[i].x[j]);
        sort(v[i].x,v[i].x+3);
    }
    f(1);
    printf("NO\n");
}