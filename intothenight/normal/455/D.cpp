#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	#ifdef LOCAL
	const int B = 2;
	#else
	const int B = sqrt(100000);
	#endif
	const int C = (n + B - 1) / B;
	vector<vector<int>> cnt(C, vector<int>(n));
	vector<deque<int>> seg(C);
	for(auto id = 0; id < C; ++ id){
		int l = B * id, r = min(n, B * (id + 1));
		seg[id] = {a.begin() + l, a.begin() + r};
		for(auto x: seg[id]){
			++ cnt[id][x];
		}
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		static int lastans = 0;
		int type, ql, qr;
		cin >> type >> ql >> qr;
		ql = (ql + lastans - 1) % n, qr = (qr + lastans - 1) % n;
		if(ql > qr){
			swap(ql, qr);
		}
		int id_l = ql / B, id_r = qr / B;
		++ qr;
		if(type == 1){
			if(id_l == id_r){
				int id = id_l;
				rotate(
					seg[id].begin() + (ql - B * id),
					seg[id].begin() + (qr - 1 - B * id),
					seg[id].begin() + (qr - B * id)
				);
			}
			else{
				int px = seg[id_l].back();
				for(auto id = id_l + 1; id < id_r; ++ id){
					++ cnt[id][px];
					-- cnt[id][seg[id].back()];
					seg[id].push_front(px);
					px = seg[id].back();
					seg[id].pop_back();
				}
				{
					++ cnt[id_r][px];
					-- cnt[id_r][seg[id_r][qr - 1 - B * id_r]];
					swap(px, seg[id_r][qr - 1 - B * id_r]);
					rotate(
						seg[id_r].begin(),
						seg[id_r].begin() + (qr - 1 - B * id_r),
						seg[id_r].begin() + (qr - B * id_r)
					);
				}
				{
					++ cnt[id_l][px];
					-- cnt[id_l][seg[id_l].back()];
					swap(px, seg[id_l].back());
					rotate(
						seg[id_l].begin() + (ql - B * id_l),
						seg[id_l].end() - 1,
						seg[id_l].end()
					);
				}
			}
		}
		else{
			int x;
			cin >> x;
			x = (x + lastans - 1) % n;
			if(id_l == id_r){
				int res = 0, id = id_l;
				for(auto i = ql; i < qr; ++ i){
					res += seg[id][i - B * id] == x;
				}
				cout << (lastans = res) << "\n";
			}
			else{
				int res = 0;
				for(auto i = ql; i < B * (id_l + 1); ++ i){
					res += seg[id_l][i - B * id_l] == x;
				}
				for(auto i = B * id_r; i < qr; ++ i){
					res += seg[id_r][i - B * id_r] == x;
				}
				for(auto id = id_l + 1; id < id_r; ++ id){
					res += cnt[id][x];
				}
				cout << (lastans = res) << "\n";
			}
		}
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////