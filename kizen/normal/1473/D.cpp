#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		string s;
		cin >> s;
		vector<int> l(N), r(N), pos(N);
		l[0] = r[0] = 0; pos[0] = 0;
		for(int i = 0; i < N - 1; ++i){
			l[i + 1] = l[i], r[i + 1] = r[i]; pos[i + 1] = pos[i];
			if(s[i] == '+'){
				++pos[i + 1];
			}
			else{
				--pos[i + 1];
			}
			l[i + 1] = min(l[i + 1], pos[i + 1]);
			r[i + 1] = max(r[i + 1], pos[i + 1]);
		}
		vector<int> bl(N), br(N), bpos(N);
		bl[N - 1] = br[N - 1] = bpos[N - 1] = 0;
		for(int i = N - 1; i; --i){
			bl[i - 1] = bl[i], br[i - 1] = br[i], bpos[i - 1] = bpos[i];
			if(s[i] == '+'){
				--bpos[i - 1];
			}
			else{
				++bpos[i - 1];
			}
			bl[i - 1] = min(bl[i - 1], bpos[i - 1]);
			br[i - 1] = max(br[i - 1], bpos[i - 1]);
		}
		while(M--){
			int x, y;
			cin >> x >> y; --x, --y;
			int a = min(l[x], pos[x] - (bpos[y] - bl[y]));
			int b = max(r[x], pos[x] + (br[y] - bpos[y]));
			cout << b - a + 1 << '\n';
		}
	}
	return 0;
}