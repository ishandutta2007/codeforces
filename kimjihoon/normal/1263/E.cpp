#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int smx[4000009], smn[4000009], lz[4000009];

void lazy(int tn, int s, int e)
{
	if (lz[tn] == 0) return;
	if (s != e) {
		lz[tn * 2 + 1] += lz[tn]; lz[tn * 2 + 2] += lz[tn];
	}
	smx[tn] += lz[tn]; smn[tn] += lz[tn];
	lz[tn] = 0;
}

void up(int tn, int s, int e, int ts, int te, int w)
{
	lazy(tn, s, e);
	if (s > te || ts > e) return;
	if (ts <= s && e <= te) {
		smx[tn] += w; smn[tn] += w;
		lz[tn * 2 + 1] += w; lz[tn * 2 + 2] += w;
		return;
	}
	int md = (s + e) / 2;
	up(tn * 2 + 1, s, md, ts, te, w); up(tn * 2 + 2, md + 1, e, ts, te, w);
	smn[tn] = min(smn[tn * 2 + 1], smn[tn * 2 + 2]);
	smx[tn] = max(smx[tn * 2 + 1], smx[tn * 2 + 2]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n; cin >> n;
	string s; cin >> s;
	int p = 0, mr = 0;
	string ts = " ";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'L') p = max(p - 1, 0);
		else if (s[i] == 'R') {
			p++;
			if (p >= (int)ts.length()) ts += " ";
		}
		mr = max(mr, p);
	}
	int c = 0; p = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') p = max(p - 1, 0);
		else if (s[i] == 'R') p++;
		else if (s[i] == '(') {
			if (ts[p] == ')') {
				up(0, 0, mr, p, mr, 2); c += 2;
			}
			else if (ts[p] != '(') {
				up(0, 0, mr, p, mr, 1); c++;
			}
			ts[p] = s[i];
		}
		else if (s[i] == ')') {
			if (ts[p] == '(') {
				up(0, 0, mr, p, mr, -2); c -= 2;
			}
			else if (ts[p] != ')') {
				up(0, 0, mr, p, mr, -1); c--;
			}
			ts[p] = s[i];
		}
		else {
			if (ts[p] == ')') {
				up(0, 0, mr, p, mr, 1); c++;
			}
			else if (ts[p] == '(') {
				up(0, 0, mr, p, mr, -1); c--;
			}
			ts[p] = s[i];
		}
		if (smn[0] < 0 || c != 0) cout << -1 << " ";
		else cout << smx[0] << " ";
	}
	cout << '\n';
	return 0;
}