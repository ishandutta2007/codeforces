#include<iostream>
#include<cstdio>
#include<vector>
//This code is written by Itst
using namespace std;

#define PII pair < int , int >
int N;
vector < PII > Edge;
vector < int > S , T , arr , son;

bool query(int u){
	cout << S.size() << endl;
	for(auto t : S) cout << t << ' ';
	cout << endl << T.size() << endl;
	for(auto t : T) cout << t << ' ';
	cout << endl << u << endl;
	int x; cin >> x; return x;
}

void answer(){
	cout << "ANSWER" << endl;
	for(auto t : Edge) cout << t.first << ' ' << t.second << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> N;
	S.push_back(1);	arr.push_back(2);
	for(int i = 3 ; i <= N ; ++i){
		int L = 0 , R = i - 2;
		while(L < R){
			int mid = (L + R + 1) >> 1;
			T.clear(); T.insert(T.begin() , arr.begin() , arr.begin() + mid);
			query(i) ? R = mid - 1 : L = mid;
		}
		arr.insert(arr.begin() + L , i);
	}
	son.push_back(*--arr.end());
	auto it = --arr.end();
	while(it-- != arr.begin()){
		auto t = son.begin();
		while(t != son.end()){
			T.clear(); T.insert(T.begin() , t , son.end());
			if(!query(*it)) break;
			int L = 0 , R = son.end() - t - 1;
			while(L < R){
				int mid = (L + R) >> 1;
				T.clear(); T.insert(T.begin() , t , t + mid + 1);
				query(*it) ? R = mid : L = mid + 1;
			}
			while(L){++t; --L;}
			auto t1 = t; Edge.push_back(PII(*it , *t)); son.erase(t1);
		}
		son.push_back(*it);
	}
	for(auto t : son) Edge.push_back(PII(t , 1));
	answer();
	return 0;
}