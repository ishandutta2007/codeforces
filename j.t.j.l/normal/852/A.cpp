#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int stp[MAXN];
vector<string> STP[MAXN];

vector<string> ans;

void __add_1(int x, int ret){
	string s = "";
	for (int y = x; y; y /= 10){
		s.push_back('0' + y % 10);
		s.push_back('+');
	}
	s.pop_back();
	reverse(s.begin(), s.end());
	ans.push_back(s);
	s.clear();
	s.push_back(ret + '0');
	ans.push_back(s);
}

void __add_2(int x, int ret){
	string s = "";
	for (int y = x; y; y /= 10){
		s.push_back('0' + y % 10);
		s.push_back('+');
	}
	s.pop_back();
	reverse(s.begin(), s.end());
	ans.push_back(s);
	s.clear();
	ans.push_back(STP[ret][0]);
}

int __check(int x, int ret){
	if (ret < 10){
		__add_1(x, ret);
		return 1;
	}
	else if (ret < 100 && stp[ret] == 1){
		__add_2(x, ret);
		return 1;
	}
	return 0;
}

int gao(int x){
	int ret = 0;
	for (int y = x; y; y /= 10){
		ret += y % 10;
	}
	if (__check(x, ret)){
		return 1;
	}
	int __ret = ret;
	for (int y = x / 10, p = 1; y; y /= 10, p++){
		ret = __ret + 9 * (y % 10);
		if (ret < 10){
			string s = "";
			for (int z = x, q = 0; z; z /= 10, q++){
				s.push_back('0' + z % 10);
				if (q + 1 != p) s.push_back('+');
			}
			s.pop_back();
			reverse(s.begin(), s.end());
			ans.push_back(s);
			s.clear();
			s.push_back(ret + '0');
			ans.push_back(s);
			return 1;
		}
		else if (ret < 100 && stp[ret] == 1){
			string s = "";
			for (int z = x, q = 0; z; z /= 10, q++){
				s.push_back('0' + z % 10);
				if (q + 1 != p) s.push_back('+');
			}
			s.pop_back();
			reverse(s.begin(), s.end());
			ans.push_back(s);
			s.clear();
			ans.push_back(STP[ret][0]);
			return 1;
		}
	}
	return 0;
}

string s;

double Kotori[8] = {0.887366523123124, 
					0.775361231233123,
					0.676535651239293,
					0.599129882399192,
					0.449398213782333,
					0.398273817236687,
					0.920398987834732,
					0.333333333333333};

void prt(vector<int>&a, int x){
	string ss = "";
	sort(a.begin(), a.end());
	a.push_back(-10);
	for (int i = 0, j = 0; i < n; i++){
		ss.push_back(s[i]);
		if (i != a[j] && i != n - 1) ss.push_back('+');
		if (i == a[j]) j++;
	}
	cout << ss << endl;
	ss += '+';
	int sum = 0, now = 0;
	for (int i = 0; i < ss.length(); i++)
		if (ss[i] == '+'){
			sum += now;
			now = 0;
		}
		else{
			now = now * 10 + (ss[i] - '0');
		}
	//cout << sum << ' ' << x << endl;
	assert(sum == x);
	for (auto &s : ans)
		cout << s << endl;
}

int pw[100];
//char s[MAXN];

double getrand(){
	return 1.0 * rand() / RAND_MAX;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	cin >> n;
	cin >> s;
	/*
	if (n == 192999){
		int cnt = 0;
		for (int i = 0; i < n; i++)
			cnt += (s[i] != '0');
		cout << cnt << ' ' << endl;
		for (int i = 0; i < n; i++)
			if (s[i] != '0')
				cout << i << "-" << s[i] << '=';
		cout << endl;
		return ;
	}*/
	if (s == "0"){
		cout << 0 << endl << 0 << endl << 0 << endl;
		return ;
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
		ret += s[i] - '0';
	if (gao(ret)){
		vector<int> a;
		prt(a, ret);
		return ;
	}
	/*
	for (int _ = 1; _ < 6; _++){
		for (int i = 0; i + _ < n; i++){
			int x = 0;
			for (int j = 0; j < _; j++){
				x += ((s[i + j] - '0') * (pw[_ - j] - 1));
			}
			if (gao(ret + x)){
				vector<int> a;
				for (int j = 0; j < _; j++)
					a.push_back(i + j);
				prt(a, ret);
				return ;
			}
		}
	}
	*/
	for (int _ = 1; ; _++){
		double MAGIC = Kotori[_ & 7];
		vector<int> a;
		int x = 0;
		int ret = 0;
		for (int i = 0, pre = 1; i < n - 1; i++){
			x = x * 10 + (s[i] - '0');
			if (getrand() < pre * MAGIC){
				//a.push_back(i);
				ret += x;
				x = 0;
				pre = 1;
			}
			else{
				a.push_back(i);
				pre++;
			}
		}
		x = x * 10 + (s[n - 1] - '0');
		ret += x;
		if (gao(ret)){
			prt(a, ret);
			return ;
		}
	}
	
}

void printans(){

}

int main(){
	srand(time(NULL));
	pw[0] = 1;
	for (int i = 1; i <= 9; i++)
		pw[i] = pw[i-1] * 10;
	for (int i = 0; i <= 9; i++){
		stp[i] = 0;
		string s = "";
		s.push_back('0' + i);
		STP[i].push_back(s);
	}
	for (int i = 10; i <= 99; i++){
		if (i % 10 + i / 10 < 10){
			stp[i] = 1;
			string s = "";
			s.push_back(i / 10 + '0');
			s.push_back('+');
			s.push_back(i % 10 + '0');
			STP[i].push_back(s);
		}
	}
	for (int i = 10; i <= 99; i++){
		if (i % 10 + i / 10 >= 10){
			stp[i] = 2;
			string s = "";
			s.push_back(i / 10 + '0');
			s.push_back('+');
			s.push_back(i % 10 + '0');
			STP[i].push_back(s);
		}
	}
	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}