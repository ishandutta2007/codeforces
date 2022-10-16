#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 
using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

int n, k, m, f[256], f2[256];
string s, t;
int lps[500100]; 

int presuf(string &s) 
{ 
    int n = s.length(); 
  
    lps[0] = 0;
 
    int len = 0; 
  
    int i = 1; 
    while (i < n) { 
        if (s[i] == s[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else { 
            if (len != 0)  { 
                len = lps[len-1]; 
            } 
            else { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
  
    int res = lps[n-1]; 
 		return res; 
    // return (res > n/2)? n/2 : res; 
} 


int main() {
	ios_base::sync_with_stdio(false);

	cin >> s >> t;

	int lg = presuf(t);

	for(auto i : s) f[i]++;
	for(auto i : t) f2[i]++;

	if(f[(int)'0'] < f2[(int)'0'] || f[(int)'1'] < f2[(int)'1']) {
		cout << s << '\n';
		return 0;
	}

	f[(int)'0'] -= f2[(int)'0'];
	f[(int)'1'] -= f2[(int)'1'];

	f2[(int)'0'] = f2[(int)'1'] = 0;

	string ans = t;

	for(int i = lg; i < t.size(); i++)
		f2[t[i]]++;

	int nr;
	if(f2[(int)'0'] != 0 && f2[(int)'1'] != 0)
		nr = min(f[(int)'0'] / f2[(int)'0'], f[(int)'1'] / f2[(int)'1']);
	else if(f2[(int)'0'] == 0)
		nr = f[(int)'1'] / f2[(int)'1'];
	else if(f2[(int)'1'] == 0)
		nr = f[(int)'0'] / f2[(int)'0'];
	
	
	if(nr < 0) while(1);

	for(int i = 0; i < nr; i++)
		ans += t.substr(lg);
	
	f[(int)'0'] -= f2[(int)'0'] * nr;
	f[(int)'1'] -= f2[(int)'1'] * nr;

	ans += string(f[(int)'0'], '0');
	ans += string(f[(int)'1'], '1');
	// while(f[(int)'1']) ans += '1', f[(int)'1']--;
	cout << ans << '\n';
	return 0;
}