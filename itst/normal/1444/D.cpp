#include<bits/stdc++.h>
using namespace std;

bitset < 500003 > dph[503] , dpu[503];
int NH , NU , H[1003] , ph[1003] , U[1003] , pu[1003] , T;

int main(){
	for(cin >> T ; T ; --T){
		cin >> NH; for(int i = 1 ; i <= NH ; ++i) cin >> H[i];
		cin >> NU; for(int i = 1 ; i <= NU ; ++i) cin >> U[i];
		if(NH != NU){cout << "No" << endl; continue;}

		int sum = 0; for(int i = 1 ; i <= NH ; ++i) sum += H[i];
		dph[0].reset(); dph[0].set(0); for(int i = 1 ; i <= NH ; ++i) dph[i] = dph[i - 1] | (dph[i - 1] << H[i]);
		if((sum & 1) || !dph[NH][sum / 2]){cout << "No" << endl; continue;}
		int cur = sum / 2; for(int i = NH ; i ; --i) if(!dph[i - 1][cur]){ph[i] = 1; cur -= H[i];} else ph[i] = 0;
		
		sum = 0; for(int i = 1 ; i <= NU ; ++i) sum += U[i];
		dpu[0].reset(); dpu[0].set(0); for(int i = 1 ; i <= NU ; ++i) dpu[i] = dpu[i - 1] | (dpu[i - 1] << U[i]);
		if((sum & 1) || !dpu[NU][sum / 2]){cout << "No" << endl; continue;}
		cur = sum / 2; for(int i = NU ; i ; --i) if(!dpu[i - 1][cur]){pu[i] = 1; cur -= U[i];} else pu[i] = 0;

		vector < int > ph0 , ph1 , pu0 , pu1;
		for(int i = 1 ; i <= NH ; ++i) (ph[i] ? ph1 : ph0).push_back(H[i]);
		for(int i = 1 ; i <= NU ; ++i) (pu[i] ? pu1 : pu0).push_back(U[i]);
		sort(ph0.begin() , ph0.end()); sort(ph1.begin() , ph1.end());
		sort(pu0.begin() , pu0.end()); sort(pu1.begin() , pu1.end());
		vector < pair < int , int > > pot;
		if(ph0.size() < pu0.size()){
			reverse(pu0.begin() , pu0.end()); reverse(pu1.begin() , pu1.end());
			int x = 0 , y = 0;
			for(int i = 0 ; i < NH + NU ; ++i){
				if(!(i & 1)){int X; if(ph0.size()){X = ph0.back(); ph0.pop_back();} else{X = -ph1.back(); ph1.pop_back();} x += X; }
				else{int Y; if(pu0.size()){Y = pu0.back(); pu0.pop_back();} else{Y = -pu1.back(); pu1.pop_back();} y += Y;}
				pot.push_back(make_pair(x , y));
			}
		}else{
			reverse(ph0.begin() , ph0.end()); reverse(ph1.begin() , ph1.end());
			int x = 0 , y = 0;
			for(int i = 0 ; i < NH + NU ; ++i){
				if((i & 1)){int X; if(ph0.size()){X = ph0.back(); ph0.pop_back();} else{X = -ph1.back(); ph1.pop_back();} x += X; }
				else{int Y; if(pu0.size()){Y = pu0.back(); pu0.pop_back();} else{Y = -pu1.back(); pu1.pop_back();} y += Y;}
				pot.push_back(make_pair(x , y));
			}
		}
		cout << "Yes" << endl;
		for(auto t : pot) cout << t.first << ' ' << t.second << endl;
	}
	return 0;
}