#include <bits/stdc++.h>

using namespace std;
#define DIM  100007
#define DIM2 107
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 1000000007
#define MODULO2 MODULO*2
typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
struct pp {
	ll a, b;
	bool operator <(const pp& V)const {
		if (a == V.a)return b < V.b;
		return a < V.a;
	}
	bool operator ==(const pp& V)const {
		if (a == V.a && b == V.b)return 1;
		return 0;
	}
};
struct word {
	string s;
	ll num;
	char last;
	bool operator <(const word& V)const {
		if (num == V.num)return last < V.last;
		return num < V.num;
	}
};
set<char> S;
ll n;
word A[DIM];
queue<ps> P,F;

bool mycompare(word a, word b) {
	if (a.num == b.num) {
		return a.last < b.last;
	}
	return a.num < b.num;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//S.insert('a'); S.insert('e'); S.insert('i'); S.insert('o'); S.insert('u');
	cin >> n;
	for (int i = 1; i <= n; i++) {
		word j;
		string x;
		cin >> x;
		j.s = x;
		ll flag = 0;
		j.num = 0;
		for (int i = x.size()-1; i >=0; i--) {
			if (x[i]=='a'||x[i]=='e'||x[i]=='i'||x[i]=='o'||x[i]=='u') {
				j.num++;

				if (flag == 0) {
					j.last = x[i];
					flag = 1;
				}
			}
			
		}
		A[i] = j;
	}
	sort(A + 1, A + 1 + n, mycompare);
	word last;
	for (int i = 1; i <= n; i++) {
		if (A[i].num == A[i + 1].num && A[i].last == A[i + 1].last) {
			P.push({ A[i].s,A[i + 1].s });
			i++;
		}
		else {
			if (last.num == A[i].num) {
				F.push({ last.s,A[i].s });
				last.num = 0;
			}
			else {
				last = A[i];
			}
		}
	}
	if (F.size() < P.size()) {
		cout << (F.size() + P.size()) / 2 << endl;
		while (!P.empty()) {
			if (!F.empty()) {
				cout << F.front().first << ' ' << P.front().first << endl;
				cout << F.front().second << ' ' << P.front().second << endl;
				F.pop(); P.pop();
			}
			else {
				if (P.size() >= 2) {
					ps s1 = P.front();
					P.pop();
					ps s2 = P.front();
					P.pop();
					cout << s1.first << ' ' << s2.first << endl;
					cout << s1.second << ' ' << s2.second << endl;
				}
				else {
					break;
				}
			}
		}
	}
	else {
		cout << P.size() << endl;
		while (!P.empty()) {
			cout << F.front().first << ' ' << P.front().first << endl;
			cout << F.front().second << ' ' << P.front().second << endl;
			F.pop(); P.pop();
		}
	}
}