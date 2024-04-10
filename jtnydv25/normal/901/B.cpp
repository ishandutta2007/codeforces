#include <bits/stdc++.h>
using namespace std;
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

vector<int> mul(vector<int> x, vector<int> y){
	vector<int> c(x.size()+y.size()-1);
	for(int i = 0; i < x.size(); i++)
		for(int j = 0; j < y.size(); j++)
			c[i + j] += x[i]*y[j];
	return c;
}

vector<int> add(vector<int> x, vector<int> y){
	int n = max(x.size(), y.size());
	x.resize(n); y.resize(n);
	vector<int> ret(n);
	for(int i = 0; i < n; i++)
		ret[i]=x[i]+y[i];
	return ret;
}

vector<int> sub(vector<int> x, vector<int> y){
	int n = max(x.size(), y.size());
	x.resize(n); y.resize(n);
	vector<int> ret(n);
	for(int i = 0; i < n; i++)
		ret[i]=x[i]-y[i];
	return ret;
}

void improve(vector<int> & vec){
	while(!vec.empty()){
		if(vec.back() == 0) vec.resize(vec.size()-1);
		else break;
	}
}

bool valid(vector<int> vec){
	improve(vec);
	for(int i = 0; i < vec.size(); i++) if(abs(vec[i]) > 1) return 0; return 1;
}
const int N = 155;
int done[N];
pair<vector<int>, vector<int> > store[N];
void go(vector<int> A, vector<int> B, int n){
	improve(A); improve(B);
	// if(n > 10) return;
	if(n > 153) return;
	if(!done[n]){
		cerr << n << endl;
		// print(A);
		// print(B);
		done[n] = 1;
		store[n] = {A, B};
	}
	vector<int> C1 = add(mul(A, {0, 1}), B);
	vector<int> C2 = sub(mul(A, {0, 1}), B);
	if(valid(C1)){
		go(C1, A, n + 1);
	}
	if(valid(C2)){
		go(C2, A, n + 1);
	}
}

void improve2(vector<int> & vec){
	if(vec.back() == -1){
		for(int i = 0; i < vec.size(); i++) vec[i] *= -1;
	}
}
int main(){
	vector<int> A= {0, 1}, B = {1};
	go(A, B, 1);
	int n;
	cin >> n;
	vector<int> P = store[n].first, Q = store[n].second;
	improve2(P); improve2(Q);
	cout << P.size()-1 << endl;
	for(int d : P) cout << d << " "; cout << endl;
	cout << Q.size()-1 << endl;
	for(int d : Q) cout << d << " "; cout << endl;
}