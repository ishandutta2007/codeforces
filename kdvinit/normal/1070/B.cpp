#include<bits/stdc++.h>
#define int long long
using namespace std;


int get_num(vector<int> v) {
	int ans = 0;
	for(int i = 0; i < 4; ++i) {
		ans = ans * 256 + v[i];
	}
	return (((int)(1)<<32)+ans)/((int)(1)<<(32-v[4]));
}

void print_mask(int num, bool type) {
	int depth = 0;
	int num2 = num;
	while(num2/2 != 0) {
		++depth;
		num2/=2;
	}

	while(num < (1LL<<32)) {
		num *= 2;
	}
	num -= ((int)(1))<<32;

	vector<int> ans;
	for(int i = 0; i < 4; ++i) {
		ans.push_back(num%256);
		num /= 256;
	}
	reverse(ans.begin(),ans.end());


	//if(type) cout << '+';
	//else cout << '-';

	//cout << "here" << endl;

	cout << ans[0] << '.' << ans[1] << '.' << ans[2] << '.' << ans[3] << '/' << depth;
	cout << "\n";
}
int32_t main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;
cin >> n;
map<int,int> data[35];
for(int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    bool b = s[0] == '+';
    bool dig = false;
    int run = 0;
    vector<int> v;
    for(auto c : s) {
        if('0' <= c && c <= '9') {
            dig = true;
            run = run*10 + c-'0';
			}
        else {
            if(dig) {
                v.push_back(run);
                run = 0;
                dig = false;
				}
			}
		}
    v.push_back(run);
    if(v.size() == 4) v.push_back(32);
    int num = get_num(v);
    if(data[v[4]].count(num) && data[v[4]][num] != b) {
    cout << "-1\n";
    exit(0);
    }
    data[v[4]][num] = b;
	}

	// construct thing by pushing up
	set<pair<int,int>> move;
	set<pair<int,int>> stay;
	for(int k = 32; k >= 0; --k) {
		for(auto x : move) {
			if(data[k].count(x.first) && data[k][x.first] != x.second) {
				cout << "-1\n";
				exit(0);
			}
			data[k][x.first] = x.second;
		}
		move.clear();
		for(auto x : data[k]) {
			int num = x.first;
			int type = x.second;
			if(k == 0 || data[k].count(num^1)) {
				if(k != 0 && data[k][num^1] == type) {
					move.emplace(num/2, type);
				} else {
					move.emplace(num/2, 2);
					stay.insert(x);
				}
			} else {
				move.emplace(num/2, type);
			}
		}
	}
	int sz = 0;
	for(auto x : stay) {
		sz += x.second == 0;
	}
	cout << sz << "\n";
	for(auto x : stay) {
		if(x.second == 0)
			print_mask(x.first, x.second);
	}
}