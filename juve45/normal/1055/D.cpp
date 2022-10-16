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

// const int N = ;
int n;
string s[3333], t[3322];

void preKMP(string pattern, int f[]) {
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++) {
        k = f[i - 1];
        while (k >= 0) {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}
 
//check whether target string contains pattern and return first position
int KMP(string pattern, string target) {
    int m = pattern.length();
    int n = target.length();
    int f[m];     
    preKMP(pattern, f);     
    int i = 0;
    int k = 0;        
    while (i < n) {
        if (k == -1) {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k]) {
            i++; k++;
            if (k == m)
                return i - m;
        }
        else
            k = f[k];
    }
    return -1;
}
 
deque <int> diff[3010];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) cin >> t[i];

	string cand, tar;

	for(int i = 1; i <= n; i++) {
		for(int j = 0;j < s[i].size(); j++)
			if(s[i][j] != t[i][j])
				diff[i].push_back(j);
	}

	


	for(int ok = 1; ok; ) {

		char c = '^';
		for(int i = 1; i <= n; i++) {
		
			if(diff[i].empty()) continue;
		
			int pos = diff[i][0] - 1;
			if(pos < 0) { ok = 0; break;}
		
			if(c == '^') c = s[i][pos];
			else if(c != s[i][pos]) ok = 0;
		}

		if(ok) 
			for(int i = 1; i <= n; i++) {
				if(diff[i].empty()) continue;
				diff[i].push_front(diff[i][0] - 1);
			}
	}


	for(int ok = 1; ok; ) {

		char c = '^';
		for(int i = 1; i <= n; i++) {
		
			if(diff[i].empty()) continue;
		
			int pos = diff[i].back() + 1;
			if(pos >= s[i].size()) { ok = 0; break;}
		
			if(c == '^') c = s[i][pos];
			else if(c != s[i][pos]) ok = 0;
		}

		if(ok) 
			for(int i = 1; i <= n; i++) {
				if(diff[i].empty()) continue;
				diff[i].push_back(diff[i].back() + 1);
			}
	}

	for(int i = 1; i <= n; i++) {
		if(diff[i].empty()) continue;
		if(diff[i].back() - diff[i][0] + 1 > cand.size()) {
			cand = s[i].substr(diff[i][0], diff[i].back() - diff[i][0] + 1);
			tar = t[i].substr(diff[i][0], diff[i].back() - diff[i][0] + 1);
		}
	}

	dbg(cand, tar);

	for(int i= 1; i <= n; i++) {
		int pos = KMP(cand, s[i]);
		
		if(pos != -1) 
			for(int j = 0; j < cand.size(); j++)
				s[i][j + pos] = tar[j];
 
		if(s[i] != t[i]) 
			return cout << "NO\n", 0;
		// dbg(i, s[i], t[i]);
	}
	cout << "YES\n";
	cout << cand << '\n' << tar << '\n';
}