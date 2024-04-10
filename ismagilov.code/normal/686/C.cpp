#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define fs first
#define sc second
using namespace std;

int n, m;
int ans = 0;
int len1 = 1;
int len2 = 1;
int bb[8];
vector<int> chis1;
vector<int> chis2;
vector<bool> uuu(8);

int perevod(vector<int> a){
	int tek = a.size();
	int res = 0;
	for (int i = 0; i < tek; i++){
		res += (a[i] * bb[i+1]);
	}
	return res;
}

int gen1(int k, vector<bool> used, vector<int> chislo2, int kek){
	
	if (k != 0){
		chislo2.push_back(kek);
		used[kek] = 1;
	}
	if (k == len2){
		return perevod(chislo2) < m;
	}
	
	int reres = 0;
	for (int i = 0; i < 7; i++){
		if (!used[i]){
			reres += gen1(k+1, used, chislo2, i);
		}
	}
	return reres;
}

int gen(int k, vector<bool> used, vector<int> chislo1, int kek){
	if (k != 0){
		chislo1.push_back(kek);
		used[kek] = 1;
	}
	if (k == len1){
		if(perevod(chislo1) < n){
			return gen1(0, used, chis2, 0);
		}
		return 0;
	} 
	
	
	int reres = 0;
	for (int i = 0; i < 7; i++){
		if (!used[i]){
			reres += gen(k+1, used, chislo1, i);
		}
	}
	return reres;
}




main() {
	bb[1] = 1;
	for (int i = 2; i < 8; i++){
		bb[i] = bb[i-1] * 7;	
	}
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	int kol1 = 7;
	while(kol1 < n){
		len1++;
		kol1 *= 7;
	}
	int kol2 = 7;
	while(kol2 < m){
		len2++;
		kol2 *= 7;
	}
	if ((len1+len2) > 7){
		cout << 0 << endl;
        return 0;
	}
	ans = gen(0, uuu, chis1, 0);
	cout << ans;
}