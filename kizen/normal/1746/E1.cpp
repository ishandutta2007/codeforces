#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	vector<int> gr(n);
	iota(gr.begin(), gr.end(), 1);

	while((int)gr.size() > 3){
		vector<vector<int>> vc;

		int p = 0;
		for(int i = 0; i < 4; ++i){
			int q = p + (((int)gr.size() - p) / (4 - i));

			vector<int> nvc;
			while(p < q){
				nvc.push_back(gr[p++]);
			}
			vc.push_back(nvc);
		}

		cout << "? " << (int)vc[0].size() + (int)vc[1].size() << ' ';
		for(auto&i:vc[0]) cout << i << ' ';
		for(auto&i:vc[1]) cout << i << ' ';
		cout << '\n';
		cout.flush();

		string x; cin >> x;

		cout << "? " << (int)vc[1].size() + (int)vc[2].size() << ' ';
		for(auto&i:vc[1]) cout << i << ' ';
		for(auto&i:vc[2]) cout << i << ' ';
		cout << '\n';
		cout.flush();

		string y; cin >> y;

		gr.clear();
		if(x == "NO" && y == "NO"){
			for(auto&i:vc[0]) gr.push_back(i);
			for(auto&i:vc[2]) gr.push_back(i);
			for(auto&i:vc[3]) gr.push_back(i);
		}
		if(x == "NO" && y == "YES"){
			for(auto&i:vc[1]) gr.push_back(i);
			for(auto&i:vc[2]) gr.push_back(i);
			for(auto&i:vc[3]) gr.push_back(i);
		}
		if(x == "YES" && y == "NO"){
			for(auto&i:vc[0]) gr.push_back(i);
			for(auto&i:vc[1]) gr.push_back(i);
			for(auto&i:vc[3]) gr.push_back(i);
		}
		if(x == "YES" && y == "YES"){
			for(auto&i:vc[0]) gr.push_back(i);
			for(auto&i:vc[1]) gr.push_back(i);
			for(auto&i:vc[2]) gr.push_back(i);
		}
	}
	if((int)gr.size() == 3){
		cout << "? 1 "; cout << gr[0] << '\n'; cout.flush();
		string x; cin >> x;
		cout << "? 1 "; cout << gr[1] << '\n'; cout.flush();
		string y; cin >> y;
		cout << "? 1 "; cout << gr[1] << '\n'; cout.flush();
		string z; cin >> z;
		cout << "? 1 "; cout << gr[0] << '\n'; cout.flush();
		string w; cin >> w;

		auto ngr = gr;
		gr.clear();

		int cnt = 0;
		cnt += (x == "YES" || y == "NO");
		cnt += (y == "NO" || z == "NO");
		cnt += (z == "NO" || w == "YES");
		if(cnt == 3) gr.push_back(ngr[0]);

		cnt = 0;
		cnt += (x == "NO" || y == "YES");
		cnt += (y == "YES" || z == "YES");
		cnt += (z == "YES" || w == "NO");
		if(cnt == 3) gr.push_back(ngr[1]);

		cnt = 0;
		cnt += (x == "NO" || y == "NO");
		cnt += (y == "NO" || z == "NO");
		cnt += (z == "NO" || w == "NO");
		if(cnt == 3) gr.push_back(ngr[2]);
	}

	cout << "! ";
	cout << gr[0] << '\n';
	cout.flush();

	string x; cin >> x;

	if(x == ":("){
		cout << "! ";
		cout << gr[1] << '\n';
		cout.flush();
	}
	
	return 0;
}