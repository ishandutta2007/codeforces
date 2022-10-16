#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 305;
int n, sum_l, t, off, inv[N], sum_r, s[N], inv2[N], cnt;

int query(int l, int r) {
	
	cout << "? " << l << ' ' << r << endl;
	fflush(stdout);
	int er; cin >> er;
	assert(er != -1);
	return er;
}


void get1() {

	while(1) {
		int newt = query(2, n);
		
		if(t % 2 == newt % 2) {

			for(int i = 2; i <= n; i++)
				inv[i] ^= 1;

			if(t + newt < n) s[1] = 0 ^ inv[1];
			else s[1] = 1 ^ inv[1], sum_l++;
			
			t = newt;

			return;
		} else {
			for(int i = 1; i <= n; i++)
				inv[i] ^= 1;
		}
		t = newt;
	}
}

void get(int pos) {

	// inv2[pos] ^= inv2[pos - 1];

	while(1) {
		int newt = query(pos - off, pos);
		// dbg(t, newt, pos);
		if( (((newt % 2) == (t % 2)) && (pos % 2 == 0)) || ((pos % 2 == 1) && (newt % 2) != (t % 2))) {
			// am schimbat in stanga
			for(int i = 1; i <= pos; i++) inv[i] ^= 1;	
			// inv[pos] ^= 1;

			int new_sum_l = pos - 1 - sum_l;
			int dif1 = new_sum_l - sum_l;
			int dif2 = newt - t;
				
			// dbg(dif1,dif2);
			// assert(abs(dif1 - dif2) <= 1);

			sum_l = new_sum_l;
			if(dif2 - dif1 < 0) s[pos] = 0 ^ inv[pos];// ^ inv2[pos];
			else s[pos] = 1 ^ inv[pos], sum_l++;// ^ inv2[pos], sum_l++;

			t = newt;
			return;
		} else {
			// am schimbat in dreapta
			// inv2[pos + off] ^= 1;
			for(int i = pos - off; i <= n; i++) inv[i] ^= 1;

			if(off) {
				if((inv[pos - 1] ^ s[pos - 1]) == 1) sum_l++;
				else sum_l--;
			} 
		}
		t = newt;
	}
	// assert(false);
}



int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> t;
	
	if(n == 1) {
		cout << "! " << t << endl;
		return 0;
	}



	sum_r = t;
	off = n % 2;

	if(n % 2 == 1) {

		get1();

		// sum_l = s[1] ^ inv[1];
		dbg(s[1], sum_l);

		for(int i = 2; i <= n; i++)
			get(i);

	} else {	

		for(int i = 1; i <= n; i++) {
			get(i);
			dbg(s[i], t, sum_l);
		}
	}

	// dbg(t);
	// dbg(sum_l);
	// s[n] = (t - sum_l) ^ inv[n];
	

	cout << "! ";
	for(int i = 1; i <= n; i++)
		cout << s[i];
	cout << endl;
	fflush(stdout);

}


//010000101010101001100101010101010101010100111
//01000011110000001100111111100011000000001100-3