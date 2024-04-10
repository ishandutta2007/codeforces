#include<iostream>
#include<vector>
using namespace std;

int p[803] , N , pos[803];

bool qry(vector < int > cur){
	cout << "? " << cur.size() << ' '; for(auto t : cur) cout << t << ' ';
	cout << endl; bool flg; cin >> flg; return flg;
}

void pro1(){
	for(int i = 1 ; i <= 4 && N >= 2 * i ; ++i){
		bool found = 0;
		for(int j = 1 ; j <= N ; ++j)
			if(!p[j]){
				vector < int > now;
				for(int k = 1 ; k <= N ; ++k)
					if((!p[k] || p[k] == i || p[k] == N - i + 1) && k != j)
						now.push_back(k);
				if(qry(now)){
					int val = 0;
					if(i == 1) val = found ? 1 : N;
					else val = qry({pos[1] , j}) ^ (i & 1) ? N - i + 1 : i;
					pos[p[j] = val] = j; if(!found) found = 1; else break; 
				}
			}
	}
}

const int val[5] = {3,4,5,7,8};
int mval[5][803];
void pro4(){
	for(int i = 1 ; i <= N ; ++i){
		if(p[i]) continue;
		for(int j = 0 ; j < 4 ; ++j){
			vector < int > pot{1,2,3,N-3,N-2,N-1}; int num = 0;
			while(1){
				vector < int > tmp{i}; int sum = 0;
				for(int t = 7 - val[j] ; t < 6 ; ++t){tmp.push_back(pos[pot[t]]); sum = (sum + pot[t]) % val[j];}
				if(++num == val[j] || qry(tmp)){mval[j][i] = (val[j] - sum) % val[j]; break;}
				++pot[6 - num];
			}
		}
	}

	for(int i = 1 ; i <= N ; ++i)
		if(!p[i]){
			vector < int > pot{pos[N-1],pos[N-2],pos[N-3],pos[N],i}; int sum = 4 * N - 6;
			for(int j = 1 ; j <= 4 ; ++j) if(j % 4 != mval[1][i]){pot.push_back(pos[j]); sum += j;}
			mval[4][i] = (8 - sum % 8) % 8 ^ ((!qry(pot)) * 4);
		}
}

void pro6(){
	for(int i = 5 ; i <= N - 4 ; ++i)
		for(int j = 1 ; j <= N ; ++j){
			bool flg = 1;
			for(int k = 0 ; k < 5 ; ++k)
				flg &= i % val[k] == mval[k][j];
			if(flg) p[j] = i;
		}
	if(p[1] > N / 2) for(int i = 1 ; i <= N ; ++i) p[i] = N + 1 - p[i];
}

int main(){
	cin >> N; pro1(); pro4(); pro6();
	cout << "! "; for(int i = 1 ; i <= N ; ++i) cout << p[i] << ' ';
	return 0;
}