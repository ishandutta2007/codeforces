#include<bits/stdc++.h>
using namespace std;

char in[1003]; int T , N , id;
int query(string s){
	cout << "? " << s << endl;
	int num; cin >> num;
	if(num == -1) exit(0);
	for(int i = 1 ; i <= num ; ++i){
		int pos; cin >> pos;
		for(int j = 0 ; j < s.size() ; ++j)
			in[pos + j] = s[j];
	}
	return num;
}

#define getans() cout << "! "; for(int i = 1 ; i <= N ; ++i) cout << in[i];\
	cout << endl; cin >> id; if(!id) exit(0); return;

void work(){
	int r;
	if(!(query("CO") + query("CH") + query("HC") + query("HO")))
		if(query("CCC") || query("HHH")){r = N; while(in[r]) --r; while(r) in[r--] = 'O'; getans();}
		else if(query("OOO")){
			string now; r = 1; while(in[r]){now += 'O'; ++r;}
			int pos = r; while(r <= N){now += 'H'; ++r;}
			if(!query(now)) while(pos <= N) in[pos++] = 'C';
			getans();
		}
		else{if(!query("OOHH")){in[1] = in[2] = 'O'; in[3] = in[4] = 'C';} getans();}
	else{
		string now; r = N; while(!in[r]) --r; now = in[r];
		for(int i = r - 1 ; i ; --i){
			if(!in[i])
				if(in[i + 1] == 'O') in[i] = 'O';
				else{query(in[i + 1] + now); if(!in[i]) in[i] = 'O';}
			now = in[i] + now;
		}
		for(int i = r + 1 ; i <= N ; ++i){
			if(in[i - 1] == 'H') in[i] = 'H';
			else if(in[i - 1] == 'C') in[i] = 'C';
			else{
				query(now + 'O');
				if(!in[i]){
					for(int j = i ; j <= N ; ++j) now += 'H';
					if(!query(now)) for(int j = i ; j <= N ; ++j) in[j] = 'C';
				}
			}
			now = now + in[i];
		}
		getans();
	}
}

int main(){for(cin >> T ; T ; --T){cin >> N; memset(in , 0 , sizeof(in)); work();} return 0;}