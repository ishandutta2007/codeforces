#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 3000005;


// lexicographic order for pairs
inline bool leq(int a1, int a2, int b1, int b2) {
	return(a1 < b1 || a1 == b1 && a2 <= b2);
}

// and triples
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
	return(a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3));
} // and triples

// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
static void radixPass(int* a, int* b, int* r, int n, int K) {// count occurrences
	int* c = new int[K + 1]; // counter array
	for (int i = 0; i <= K; i++) c[i] = 0; // reset counters
	for (int i = 0; i < n; i++) c[r[a[i]]]++; // count occurrences
	for (int i = 0, sum = 0; i <= K; i++) // exclusive prefix sums
	{
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for (int i = 0; i < n; i++) b[c[r[a[i]]]++] = a[i]; // sort
	delete[] c;
}

// find the suffix array SA of s[0..n-1] in {1..K}n
// require s[n]=s[n+1]=s[n+2]=0, n>=2
void suffixArray(int* s, int* SA, int n, int K) {
	int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n12 = n0 + n2;
	int* s12 = new int[n12 + 3]; s12[n12] = s12[n12 + 1] = s12[n12 + 2] = 0;
	int* SA12 = new int[n12 + 3]; SA12[n12] = SA12[n12 + 1] = SA12[n12 + 2] = 0;
	int* s0 = new int[n0];
	int* SA0 = new int[n0];
	// generate positions of mod 1 and mod 2 suffixes
	// the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
	for (int i = 0, j = 0; i < n + (n0 - n1); i++)
	if (i % 3 != 0) s12[j++] = i;
	// lsb radix sort the mod 1 and mod 2 triples
	radixPass(s12, SA12, s + 2, n12, K);
	radixPass(SA12, s12, s + 1, n12, K);
	radixPass(s12, SA12, s, n12, K);
	// find lexicographic names of triples
	int name = 0, c0 = -1, c1 = -1, c2 = -1;
	for (int i = 0; i < n12; i++) {
		if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
			name++;
			c0 = s[SA12[i]];
			c1 = s[SA12[i] + 1];
			c2 = s[SA12[i] + 2];
		}
		if (SA12[i] % 3 == 1) s12[SA12[i] / 3] = name; // left half
		else s12[SA12[i] / 3 + n0] = name; // right half
	}
	// recurse if names are not yet unique
	if (name < n12) {
		suffixArray(s12, SA12, n12, name);
		// store unique names in s12 using the suffix array
		for (int i = 0; i < n12; i++) s12[SA12[i]] = i + 1;
	}
	else // generate the suffix array of s12 directly
	for (int i = 0; i < n12; i++) SA12[s12[i] - 1] = i;
	// stably sort the mod 0 suffixes from SA12 by their first character
	for (int i = 0, j = 0; i < n12; i++)
	if (SA12[i] < n0) s0[j++] = 3 * SA12[i];
	radixPass(s0, SA0, s, n0, K);
	// merge sorted SA0 suffixes and sorted SA12 suffixes
	for (int p = 0, t = n0 - n1, k = 0; k < n; k++) {
#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
		int i = GetI(); // pos of current offset 12 suffix
		int j = SA0[p]; // pos of current offset 0 suffix
		if (SA12[t] < n0 ? // different compares for mod 1 and mod 2 suffixes
			leq(s[i], s12[SA12[t] + n0], s[j], s12[j / 3]) :
			leq(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j], s[j + 1], s12[j / 3 + n0]))
		{// suffix from SA12 is smaller
			SA[k] = i; t++;
			if (t == n12) // done --- only SA0 suffixes left
			for (k++; p < n0; p++, k++) SA[k] = SA0[p];
		}
		else {// suffix from SA0 is smaller
			SA[k] = j; p++;
			if (p == n0) // done --- only SA12 suffixes left
			for (k++; t < n12; t++, k++) SA[k] = GetI();
		}
	}
	delete[] s12; delete[] SA12; delete[] SA0; delete[] s0;
}

int ord[MAXN], nord[MAXN], cnt[MAXN], aux[MAXN];
void solve(int n, char *str, int *sfx, int *rev, int *lcp){
	int p = 1;
	memset(ord, 0, sizeof(ord));
	for(int i=0; i<n; i++){
		ord[i] = str[i] - 'a' + 1;
	}
	suffixArray(ord, sfx, n, 30);
	for(int i=0; i<n; i++) rev[sfx[i]] = i;
	int h = 0;
	for(int i=0; i<n; i++){
		if(rev[i]){
			int prv = sfx[rev[i] - 1];
			while(str[prv + h] == str[i + h]) h++;
			lcp[rev[i]] = h;
		}
		h = max(h-1, 0);
	}
}

int n, q;
char str[MAXN], buf[MAXN];
int sfx[MAXN], rev[MAXN], lcp[MAXN];
int idx[MAXN], sum[MAXN], ptr;

int getsum(int s, int e){
	int ans = 0;
	if(e >= 0) ans += sum[e];
	if(s > 0) ans -= sum[s-1];
	return ans;
}

struct swp{
	int s, e, x;
	bool operator<(const swp &f)const{
		return e - s > f.e - f.s;
	}
};

int ret[MAXN];
int fl[MAXN], fr[MAXN];

int sl(int x){
	if(fl[x] != x) return fl[x] = sl(fl[x]);
	return x;
}

int sr(int x){
	if(fr[x] != x) return fr[x] = sr(fr[x]);
	return x;
}

int main(){
	scanf("%s", str);
	n = strlen(str);
	scanf("%d",&q);
	str[n] = 'z' + 1;
	ptr = n + 1;
	vector<swp> v;
	for(int i=0; i<q; i++){
		scanf("%s", buf);
		int m = strlen(buf);
		v.push_back({ptr, ptr + m, i});
		for(int j=0; j<2*m; j++){
			str[ptr++] = buf[j%m];
		}
	}
	solve(ptr, str, sfx, rev, lcp);
	for(int i=0; i<n; i++) sum[rev[i]]++;
	for(int i=1; i<ptr; i++) sum[i] += sum[i-1];
	iota(fl, fl + ptr, 0);
	iota(fr, fr + ptr, 0);
	sort(v.begin(), v.end());
	int swp = 0;
	for(auto &i : v){
		vector<pi> qry;
		for(int j=i.s; j<i.e; j++){
			int pos = sl(rev[j]);
			while(lcp[pos] >= i.e - i.s){
				fl[pos] = sl(pos - 1);
				pos = fl[pos];
			}
			pos = sr(rev[j]);
			while(lcp[pos+1] >= i.e - i.s){
				fr[pos] = sr(pos + 1);
				pos = fr[pos];
			}
			int ps = sl(rev[j]), pe = sr(rev[j]);
			qry.push_back(pi(ps, 1));
			qry.push_back(pi(pe+1, -1));
		}
		sort(qry.begin(), qry.end());
		int ans = 0, cnt = 0;
		for(int i=0; i<qry.size(); ){
			int e = i;
			while(e < qry.size() && qry[i].first == qry[e].first){
				cnt+=qry[e].second;
				e++;
			}
			if(cnt > 0){
				ans += getsum(qry[i].first, qry[e].first - 1);
			}
			i = e;
		}
		ret[i.x] = ans;
	}
	for(int i=0; i<q; i++) printf("%d\n", ret[i]);
}