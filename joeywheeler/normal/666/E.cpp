#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int m;
int s[600005];
int a[600005], ia[600005];

int h[600005], p[600005];
long long BASE = 1000003;
long long MOD = 1000000009;
int ansmx[600005];
int ansi[600005];

int hsh(int i, int j) {
	return (MOD + h[j] - h[i]) * p[600003-i] % MOD;
}

int lcp(int i, int j) {
	int S = 0, E = min(m-i,m-j), b = 0;
	while (S <= E) {
		int M = (S+E)/2;
		if (hsh(i,i+M) == hsh(j,j+M)) b=M, S=M+1;
		else E=M-1;
	}
	return b;
}

bool cmp(int i, int j) {
    int l = lcp(i,j);
    return s[i+l] < s[j+l];
}

void pbuf(int i) {
    FO(j,i,m) {
        if (s[j] < 420) printf("%c", s[j]);
        else printf("$");
    }
    printf("\n");
}

int ind[600005];
char buf[600005];

struct node {
    node *l, *r;
    int mxv, mxi;

    node() {
        l = r = NULL;
        mxv = 0;
        mxi = 1e9;
    }
};

node *crt(int rs, int re, int qi) {
    node *r = new node;
    r->mxv = 1; r->mxi = qi;
    if (rs+1 != re) {
        int md = (rs+re)/2;
        if (qi < md) r->l = crt(rs, md, qi);
        else r->r = crt(md, re, qi);
    }
    return r;
}

node *mrg(node *a, node *b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    if (!a->l && !a->r) {
        // leaf
        a->mxv += b->mxv;
        return a;
    }

    a->l = mrg(a->l, b->l);
    a->r = mrg(a->r, b->r);
    a->mxv = -1;
    if (a->l) {
        a->mxv = a->l->mxv;
        a->mxi = a->l->mxi;
    }
    if (a->r && a->r->mxv > a->mxv) {
        a->mxv = a->r->mxv;
        a->mxi = a->r->mxi;
    }
    return a;
}

pair<int,int> qmx(node *nd, int rs, int re, int qs, int qe) {
    if (nd == NULL) return make_pair(0,qs);
    if (rs == qs && re == qe) return {nd->mxv,nd->mxi};
    int md = (rs+re)/2;
    pair<int,int> r(0,qs);
    if (qs<md) {
        auto nr = qmx(nd->l, rs, md, qs, min(qe,md));
        if (nr.first > r.first) r = nr;
    }
    if (qe>md) {
        auto nr = qmx(nd->r, md, re, max(qs,md), qe);
        if (nr.first > r.first) r = nr;
    }
    return r;
}

int ps[600005], tp[600005], g;

bool sc(int i, int j) {
	if (ps[i] != ps[j]) return ps[i] < ps[j];
	i += g; j += g;
	return i<m && j<m ? ps[i] < ps[j] : i > j;
}

void sa() {
	FO(i,0,m) a[i] = i, ps[i] = s[i];
	for (g = 1;; g <<= 1) {
		sort(a,a+m,sc);
		FO(i,0,m-1) tp[i+1] = tp[i] + sc(a[i],a[i+1]);
		FO(i,0,m) ps[a[i]] = tp[i];
		if (tp[m-1] == m-1) break;
	}
	FO(i,0,m) ia[a[i]] = i;
}
int lp[20][600005];

int qlcp(int i, int j) {
    if (i>j) swap(i,j);
    int pw = 31-__builtin_clz(j-i);
    return min(lp[pw][i],lp[pw][j-(1<<pw)]);
}

int main() {
    scanf(" %s", buf);
    m = strlen(buf);
    FO(i,0,m) s[i] = buf[i];
    s[m] = 420+m; m++;

    int n; scanf("%d", &n);
    FO(i,0,n) {
        scanf(" %s", buf);
        int nm = strlen(buf);
        FO(j,0,nm) {
            ind[m] = i+1;
            s[m++] = buf[j];
        }
        s[m] = 420+m; m++;
    }
    //pbuf(0);

	p[0] = 1;
	FO(i,1,600005) p[i] = p[i-1] * BASE % MOD;
	FO(i,0,m) h[i+1] = (h[i] + p[i] * 1ll * s[i]) % MOD;

    sa();
    FO(i,0,m-1) lp[0][i] = lcp(a[i],a[i+1]);
    FO(i,1,20) FO(j,0,m) {
        if (j + (1<<i) < m) lp[i][j] = min(lp[i-1][j],lp[i-1][j+(1<<(i-1))]);
    }
    //FO(i,0,m) pbuf(a[i]);

    int q; scanf("%d", &q);
    vector<tuple<int,int,int,int,int,int> > qu;
    FO(z,0,q) {
        int l, r, p, q; scanf("%d%d%d%d", &l, &r, &p, &q);
        l--; p--;
        int sl = ia[p];
        //pbuf(a[sl]);
        int st = 0, en = sl-1, bl = sl;
        while (st <= en) {
            int md = (st+en)/2;
            if (qlcp(md,sl) >= q-p) {
                bl = md;
                en = md-1;
            } else st = md+1;
        }
        st = sl+1; en = m-1; int br = sl;
        while (st <= en) {
            int md = (st+en)/2;
            if (qlcp(md,sl) >= q-p) {
                br = md;
                st = md+1;
            } else en = md-1;
        }
        br++;
        //printf("[%d,%d)\n", bl, br);
        //pbuf(a[bl]);
        qu.emplace_back(br-bl, bl, br, l, r, z);
    }
    sort(qu.begin(),qu.end());
    set<tuple<int,int,node*> > rts;
    FO(i,0,m) if (ind[i] != 0) {
        //printf("%d: %d\n", ia[i], ind[i]-1);
        node *nd = crt(0,n,ind[i]-1);
        rts.emplace(ia[i],ia[i]+1,nd);
    }
    for (auto qq : qu) {
        int len, bl, br, l, r, z; tie(len, bl, br, l, r, z) = qq;
        node *rt = NULL;
        while (1) {
            auto it = rts.lower_bound(make_tuple(bl,-1,(node*)NULL));
            if (it == rts.end() || get<0>(*it) >= br) break;
            int sbl, sbr; node *snd; tie(sbl,sbr,snd) = *it;
            rts.erase(it);
            rt = mrg(rt,snd);
        }
        int mxv, mxi;
        tie(mxv,mxi) = qmx(rt,0,n,l,r);
        ansmx[z] = mxv;
        ansi[z] = mxi+1;

        rts.emplace(bl,br,rt);
    }

    FO(i,0,q) printf("%d %d\n", ansi[i], ansmx[i]);
}