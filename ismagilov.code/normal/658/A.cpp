#include <iostream>
#define int long long
using namespace std;

main() {
	int aa = 0;
	int n, c;
	cin >> n >> c;
	int t[n], p[n];
	for (int i = 0; i < n; i++){
		cin >> p[i];
	}
	for (int i = 0; i < n; i++){
		cin >> t[i];
	}
	int kol1 = 0;
	int kol2 = 0;
	int tu1 = 0;
	for (int i = 0; i < n; i++){
		tu1 += t[i];
		kol1 += max(aa, p[i] - c * tu1);
	}
	kol2 = kol1;
	tu1 = 0;
	kol1 = 0;
	for (int i = n-1; i >= 0; i--){
		tu1 += t[i];
		kol1 += max(aa, p[i] - c * tu1);
	}
	if (kol1 < kol2){
		cout << "Limak";
	}
	else{
		if (kol2 < kol1){
			cout << "Radewoosh";
		}
		else{
			cout << "Tie";
		}
	}
	return 0;
}