#include<iostream>
#include<vector>
#include<cstdio>
#include<set>

using namespace std;

typedef long long llint;

const int MAXN = 1000005;
const int MOD = 1000000007;

int q, sum;
int p[MAXN];
llint sol;
int pot[MAXN], nck[MAXN] [22], dp[MAXN] [22];
int prime[15]={2, 3, 5, 7, 11, 13, 17, 19};
set <int> s;
set <int> :: iterator it;
vector <int> g[MAXN];

int add (int a, int b) {
    if (a+b>=MOD) return a+b-MOD; return a+b;
}

void sito () {
	p[1]=1;
	for (int i=2; i*i<MAXN; i++) {
		if (p[i]) continue;
		p[i]=i;
		for (int j=i*i; j<MAXN; j+=i) {
			if (!p[j]) p[j]=i;
		}
	}
	pot[0]=1;
    for (int i=0; i<MAXN; i++) {
        if (!p[i]) p[i]=i;
        nck[i] [0]=1;
        if (i<=21) nck[i] [i]=1;
        if (i>0) pot[i]=add(pot[i-1], pot[i-1]);
    }
    for (int i=1; i<MAXN; i++) {
        for (int j=1; j<=i; j++) {
            if (j>21) break;
            nck[i] [j]=add(nck[i-1] [j-1], nck[i-1] [j]);
        }
    }
}

string gen (int val) {
    string v;
	int last=-1, cnt=0;
	sum=0;
	while (val!=1) {
		if (last!=p[val]) {
			if (last!=-1) v+=(char)('0'+cnt);
			sum+=cnt;
			last=p[val];
			cnt=1;
		} else {
			cnt++;
		}
		val/=p[val];
	}
	v+=(char)('0'+cnt);
	sum+=cnt;
	return v;
}

int pred (string v, int len) {
    int res=1;
    for (int i=0; i<len; i++) {
        for (char j='0'; j<v[i]; j++) {
            res*=prime[i];
        }
    }
    return res;
}

void precompute () {
    for (int i=2; i<MAXN; i++) {
        string str=gen(i);
        s.insert(pred(str, str.size()));
    }
    for (it=s.begin(); it!=s.end(); it++) {
        int val=*it;
        for (int i=2; i*i<=val; i++) {
            if (val%i==0) {
                string str=gen(i);
                g[val].push_back(pred(str, str.size()));
                if (i*i==val) continue;
                str=gen(val/i);
                g[val].push_back(pred(str, str.size()));
            }
        }
        dp[val] [1]=1;
        for (int i=2; i<=20; i++) {
            for (int j=0; j<g[val].size(); j++) {
                dp[val] [i]=add(dp[g[val] [j]] [i-1], dp[val] [i]);
            }
        }
    }
}

int f (int v, int ost) {
    if (ost==1) return 1;
    if (dp[v] [ost]!=0) return dp[v] [ost];
    int res=0;
    for (int i=0; i<g[v].size(); i++) {
        res=add(f(g[v] [i], ost-1), res);
    }
    dp[v] [ost]=res;
    return res;
}

int main () {
	sito();
	precompute();
	cin >> q;
	for (int ii=0; ii<q; ii++) {
        int x, y;
        scanf("%d%d", &x, &y);
        sol=0;
        string str=gen(x);
        int br=pred(str, str.size());
        int kud=min(sum, y);
        for (int i=1; i<=kud; i++) {
            sol+=dp[br] [i]*((llint) nck[y] [i])%MOD;
            if (sol>=MOD) sol-=MOD;
        }
        if (x==1) sol=1;
        sol=sol*pot[y-1]%MOD;
        printf("%d\n", sol);
	}
	return 0;
}