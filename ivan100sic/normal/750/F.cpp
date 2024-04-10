#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int>> cache;
int h;

vector<int> guess(int x) {

	if (x <= 0) {
		return {};
	}
	
	if (cache[x].size()) {
		return cache[x];
	}

	cout << "? " << x << '\n' << flush;
	int b;
	cin >> b;
	vector<int> a(b);
	for (int& x : a) {
		cin >> x;
	}
	return cache[x] = a;
}

void answer(int x) {
	cout << "! " << x << '\n' << flush;
}

int pick(vector<int> ok, vector<int> no) {
	for (int x : ok) {
		if (find(no.begin(), no.end(), x) == no.end()) {
			return x;
		}
	}
	return ok[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;

	cin >> t;
	while (t--) {

		cache.clear();

		cin >> h;

		// izaberimo nasumican cvor i nadjimo node-udaljenost
		// od listova

		if (h <= 4) {
			for (int i=1; i<(1<<h); i++) {
				auto v = guess(i);
				if (v.size() == 2) {
					answer(i);
					break;
				}
			}
			continue;
		}

		int gdub = 0, y, g;
		{
			int x = 1;
			auto v = guess(x);

			if (v.size() == 2) {
				answer(x);
				continue;
			} else if (v.size() == 1) {
				gdub = 1;
				y = v[0];
				g = x;
			} else {
				int a = pick(v, {});
				int b = pick(v, {a});
				int ap = x, bp = x;
				int a1 = a, b1 = b;
				int dub = 2;

				int solved = 0;

				// drill down
				while (1) {
					auto av = guess(a);
					auto bv = guess(b);

					if (av.size() == 2) {
						answer(a);
						solved = 1;
						break;
					}

					if (bv.size() == 2) {
						answer(b);
						solved = 1;
						break;
					}

					if (av.size() == 1 && bv.size() == 1) {
						// obojica smo krenuli dole
						y = pick(guess(x), {a1, b1});
						g = x;
						break;
					}

					if (av.size() == 1) {
						y = b1;
						g = x;
						break;
					}

					if (bv.size() == 1) {
						y = a1;
						g = x;
						break;
					}

					int at = pick(av, {ap});
					int bt = pick(bv, {bp});

					ap = a;
					a = at;

					bp = b;
					b = bt;

					dub++;
				}

				if (solved) {
					continue;
				}

				gdub = dub;
			}
		}

		while (1) {
			if (h - gdub == 3) {
				// final solver
				auto vy = guess(y);

				int a1 = pick(vy, {g});
				int a2 = pick(vy, {g, a1});

				auto v1 = guess(a1);
				auto v2 = guess(a2);

				int a3 = pick(v1, {y});
				int a4 = pick(v1, {y, a3});

				int a5 = pick(v2, {y});
				int a6 = pick(v2, {y, a5});

				if (guess(a3).size() == 2) {
					answer(a3);
					break;
				}

				if (guess(a4).size() == 2) {
					answer(a4);
					break;
				}

				if (guess(a5).size() == 2) {
					answer(a5);
					break;
				}

				{
					answer(a6);
					break;
				}

			} else if (h - gdub == 2) {
				// uproscena verzija above
				auto vy = guess(y);
				
				int a1 = pick(vy, {g});
				int a2 = pick(vy, {g, a1});

				if (guess(a1).size() == 2) {
					answer(a1);
					break;
				}

				{
					answer(a2);
					break;
				}
			} else if (h - gdub == 1) {
				answer(y);
				break;
			}

			// else, repeat above

			{
				auto v = guess(y);
				int a = pick(v, {g});
				int b = pick(v, {g, a});
				int ap = y, bp = y;
				int a1 = a, b1 = b;

				int solved = 0;
				int x = y;

				// drill
				while (1) {
					auto av = guess(a);
					auto bv = guess(b);

					if (av.size() == 2) {
						answer(a);
						solved = 1;
						break;
					}

					if (bv.size() == 2) {
						answer(b);
						solved = 1;
						break;
					}

					if (av.size() == 1) {
						y = b1;
						g = x;
						gdub++;
						break;
					}

					if (bv.size() == 1) {
						y = a1;
						g = x;
						gdub++;
						break;
					}

					int at = pick(av, {ap});
					int bt = pick(bv, {bp});

					ap = a;
					a = at;

					bp = b;
					b = bt;
				}

				if (solved) {
					break;
				}
			}			
		}
	}
}