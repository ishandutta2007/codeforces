#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define ll long long
#define alok(n,t) ((t*)malloc((n)*sizeof(t)))
#define pf printf
#define sf scanf
#define pln pf("\n")


int *rs = alok(11111, int);
int *as = alok(11111, int);
int *bs = alok(11111, int);
int *cs = alok(11111, int);
int *ds = alok(11111, int);
int *es = alok(11111, int);
int *fs = alok(11111, int);
int *rz = alok(11111, int);
int *az = alok(11111, int);
int *bz = alok(11111, int);
int *cz = alok(11111, int);
int *dz = alok(11111, int);
int *ez = alok(11111, int);
int *fz = alok(11111, int);
int vs[111] = {0, 4, 7, 40, 44, 47, 70, 74, 77, 400, 404, 407, 440, 444, 447, 470, 474, 477, 700, 704, 707, 740, 744, 747, 770, 774, 777, 4000, 4004, 4007, 4040, 4044, 4047, 4070, 4074, 4077, 4400, 4404, 4407, 4440, 4444, 4447, 4470, 4474, 4477, 4700, 4704, 4707, 4740, 4744, 4747, 4770, 4774, 4777, 7000, 7004, 7007, 7040, 7044, 7047, 7070, 7074, 7077, 7400, 7404, 7407, 7440, 7444, 7447, 7470, 7474, 7477, 7700, 7704, 7707, 7740, 7744, 7747, 7770, 7774, 7777,40000};

void numbs(int n, int *rs, int *as, int *bs, int *cs, int *ds, int *es, int *fs, int Lm) {
	fe(i,0,n) rs[i] = 0;
	int lm = 0;
	while (vs[lm]<Lm)lm++;
	fr(i,lm) {
		int s = vs[i];
		fe(j,0,i){
			int s2 = s + vs[j];
			if (s2 > n) break;
			fe(k,0,j) {
				int s3 = s2 + vs[k];
				if (s3 > n) break;
				fe(l,0,k) {
					int s4 = s3 + vs[l];
					if (s4 > n) break;
					fe(m,0,l) {
						int s5 = s4 + vs[m];
						if (s5 > n) break;
						fe(N,0,m) {
							int s6 = s5 + vs[N];
							if (s6 > n) break;
							rs[s6] = 1;
							as[s6] = vs[i];
							bs[s6] = vs[j];
							cs[s6] = vs[k];
							ds[s6] = vs[l];
							es[s6] = vs[m];
							fs[s6] = vs[N];
						}
					}
				}	
			}
		}
	}
}

ll a, b, c, d, e, f;
int srepr(ll n) {
	if (n <= 10000) {
		if (rs[n]) {
			a = as[n];
			b = bs[n];
			c = cs[n];
			d = ds[n];
			e = es[n];
			f = fs[n];
			return 1;
		} else {
			return 0;
		}
	} else {
		ll q = n / 1000 - 1;
		ll r = n % 1000 + 1000;
		while (q <= 10000 and !rs[q]) {
			r += 1000;
			q -= 1;
		}
		srepr(q);
		a = a * 1000 + az[r];
		b = b * 1000 + bz[r];
		c = c * 1000 + cz[r];
		d = d * 1000 + dz[r];
		e = e * 1000 + ez[r];
		f = f * 1000 + fz[r];
		return 1;
	}
}

int main() {
	numbs(10000,rs,as,bs,cs,ds,es,fs,10000);
	numbs(4500,rz,az,bz,cz,dz,ez,fz,1000);
	int z;
	sf("%d", &z);
	fq(cas,z) {
		ll n;
		sf("%I64d", &n);
		if (srepr(n)) {
			pf("%I64d %I64d %I64d %I64d %I64d %I64d\n", a, b, c, d, e, f);
		} else {
			pf("-1\n");
		}
	}	
}