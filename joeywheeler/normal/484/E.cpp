#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

struct RTREE {
    int a[400005], al[400005], ar[400005];

    void clear() {
        memset(this, 0, sizeof(RTREE));
    }

    void set(int i, int rs, int re, int qi) {
        if (rs+1==re) {
            a[i]=al[i]=ar[i]=1;
        } else {
            int md=(rs+re)/2;
            if (qi<md) set(2*i+1,rs,md,qi);
            else set(2*i+2,md,re,qi);
            a[i] = max(max(a[2*i+1],a[2*i+2]),ar[2*i+1]+al[2*i+2]);
            al[i] = al[2*i+1] + (md-rs==al[2*i+1])*al[2*i+2];
            ar[i] = ar[2*i+2] + (re-md==ar[2*i+2])*ar[2*i+1];
        }
    }

    iii query(int i, int rs, int re, int qs, int qe) {
        // return (max in [rs,re), max block of 1 touch rs in [qs,qe], max block of 1 touch re in [qs,qe]
        if (rs == qs && re == qe) {
            return iii(a[i],ii(al[i],ar[i]));
        } else {
            int md = (rs+re)/2;
            iii r1, r2;
            if (qs < md) r1 = query(2*i+1,rs,md,qs,min(qe,md));
            if (qe > md) r2 = query(2*i+2,md,re,max(qs,md),qe);
            iii res;
            res.first = max(max(r1.first, r2.first), r1.second.second+r2.second.first);
            if (rs != qs) res.second.first = 0;
            else res.second.first = r1.second.first + (md-rs==r1.second.first)*r2.second.first;
            if (re != qe) res.second.second = 0;
            else res.second.second = r2.second.second + (re-md==r2.second.second)*r1.second.second;
            return res;
        }
    }
} RT;

int n, m;
int l[100005], r[100005], b[100005];
ii f[100005];
pair<iii,int> q[100005];

bool cmp(pair<iii,int> i, pair<iii,int> j) {
    return l[i.second]+r[i.second] > l[j.second]+r[j.second];
}

int main() {
    scanf("%d",&n);
    vector<int> HV;
    FO(i,0,n) {
        scanf("%d",&f[i].first);
        f[i].second=i;
        HV.push_back(f[i].first);
    }
    sort(HV.begin(),HV.end());HV.resize(unique(HV.begin(),HV.end())-HV.begin());
    FO(i,0,n) f[i].first = lower_bound(HV.begin(),HV.end(),f[i].first)-HV.begin();
    scanf("%d",&m);
    FO(i,0,m) {
        scanf("%d %d %d", &q[i].first.second.first, &q[i].first.second.second, &q[i].first.first);
        q[i].first.second.first--;
        q[i].second = i;
    }
    sort(f,f+n); reverse(f,f+n);
    FO(i,0,m) r[i]=sz(HV)-1;
    FO(_,0,32) {
        sort(q,q+m,cmp);
        RT.clear();
        int cf = 0, cq = 0;
        while (cq < m) {
            int cur = q[cq].second;
            int md = (l[cur]+r[cur])/2;
            if (cf<n && f[cf].first >= md) {
                RT.set(0,0,n,f[cf].second);
                cf++;
                continue;
            }
            if (l[cur] > r[cur]) {
                cq++; continue;
            }
            int qc = RT.query(0, 0, n, q[cq].first.second.first, q[cq].first.second.second).first;
            if (qc >= q[cq].first.first) {
                b[cur] = md;
                l[cur] = md+1;
            } else r[cur] = md-1;
            cq++;
        }
    }
    FO(i,0,m) printf("%d\n", HV[b[i]]);
}