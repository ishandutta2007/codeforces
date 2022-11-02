#include<bits/stdc++.h>
using namespace std;
const int M = 256;

int n;

string a1[M], a2[M];

bool update (string &A, string &B) {
	if(B.size() == 0 || B.size() > A.size() || (B.size() == A.size() && B > A)) {
		B = A; return true;
	}
	return false;
}

int main()
{
	bool upd = true;
	a1[15] = "x";
	a2[15] = "x";
	a1[240] = "!x";
	a2[240] = "!x";
	a1[51] = "y";
	a2[51] = "y";
	a1[204] = "!y";
	a2[204] = "!y";
	a1[85] = "z";
	a2[85] = "z";
	a1[170] = "!z";
	a2[170] = "!z";
	while(upd) {
		upd = false;
		vector<int> nw;
		for(int i=0;i<M;i++) {
			if(a1[i].size() == 0) continue;
			string tmp = "(" + a1[i] + ")";
			upd |= update(tmp, a2[i]);
		}
		for(int i=0;i<M;i++) {
			if(a1[i].size() == 0) continue;
			int I = 255 & (~i);
			string tmp = "!(" + a1[i] + ")";
			upd |= update(tmp, a1[I]);
			upd |= update(tmp, a2[I]);
		}
		for(int i=0;i<M;i++) for(int j=0;j<M;j++) {
			if(a1[i].size() == 0 || a1[j].size() == 0) continue;
			string tmp = a1[i] + "|" + a1[j];
			upd |= update(tmp, a1[i|j]);
			if(a2[i].size() == 0 || a2[j].size() == 0) continue;
			tmp = a2[i] + "&" + a2[j];
			upd |= update(tmp, a1[i&j]);
			upd |= update(tmp, a2[i&j]);
		}
	}
	cin >> n;
	for(int i=1;i<=n;i++) {
		string tmp;
		int X = 0;
		cin >> tmp;
		for(int i=0;i<8;i++) {
			X *= 2; X += tmp[i] - '0';
		}
		cout << a1[X] << endl;
	}
}