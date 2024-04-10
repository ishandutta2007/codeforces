#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;

int xd[10][10][10][10], cc;
int invv[1000][4];

void initins() {
	int c = 0;
	for (int i=0; i<10; i++)
		for (int j=i; j<10; j++)
			for (int k=j; k<10; k++)
				for (int l=k; l<10; l++) {
					invv[c][0] = i;
					invv[c][1] = j;
					invv[c][2] = k;
					invv[c][3] = l;
					xd[i][j][k][l] = c++;
				}
	cc = c;
}

struct state {
	int floor;
	int nextToEnter;
	int inside_id;
};

int dist[10][2005][777];
int a[2005], b[2005];

bool is_finals(state s) {
	return s.nextToEnter == n+1 && s.inside_id == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i] >> b[i];

	initins();
	cerr << cc << '\n';

	memset(dist, 255, sizeof(dist));

	queue<state> q;
	q.push({1, 1, 0});
	dist[1][1][0] = 0;

	int sol = 123123123;

	while (q.size()) {
		state s = q.front(); q.pop();

		int d = dist[s.floor][s.nextToEnter][s.inside_id];
		// cerr << s.floor << ' ' << s.nextToEnter << ' ' << s.inside_id <<
		// 	' ' << d << '\n';

		if (is_finals(s))
			sol = min(sol, d);

		// pomeri se gore
		if (s.floor != 9) {
			auto s1 = s;
			s1.floor++;

			int& d1 = dist[s1.floor][s1.nextToEnter][s1.inside_id];
			if (d1 == -1 || d + 1 < d1) {
				d1 = d + 1;
				q.push(s1);
			}
		}

		// pomeri se dole
		if (s.floor != 1) {
			auto s1 = s;
			s1.floor--;

			int& d1 = dist[s1.floor][s1.nextToEnter][s1.inside_id];
			if (d1 == -1 || d + 1 < d1) {
				d1 = d + 1;
				q.push(s1);
			}
		}

		// utovar/istovar
		{
			auto s1 = s;

			int ljudi[4];
			copy(invv[s.inside_id], invv[s.inside_id] + 4, ljudi);
			int kraj = 4;
			kraj = remove(ljudi, ljudi+kraj, 0) - ljudi;
			int rem = remove(ljudi, ljudi+kraj, s.floor) - ljudi;
			int consumed = kraj - rem;

			// ubacuj
			while (a[s1.nextToEnter] == s1.floor && rem < 4) {
				// cerr << "iedmo\n";
				ljudi[rem++] = b[s1.nextToEnter];
				s1.nextToEnter++;
				consumed++;
			}

			fill(ljudi+rem, ljudi+4, 0);

			sort(ljudi, ljudi+4);
			s1.inside_id = xd[ljudi[0]][ljudi[1]][ljudi[2]][ljudi[3]];

			int& d1 = dist[s1.floor][s1.nextToEnter][s1.inside_id];

			if (d1 == -1 || d + consumed < d1) {
				d1 = d + consumed;
				q.push(s1);
			}
		}
	}

	cout << sol << '\n';
}