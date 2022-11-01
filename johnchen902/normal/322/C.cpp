#include <iostream>
#include <cstring>

char s[101];
int a, b, len;

using namespace std;

const int NO_SUCH_K = -1;
const int ANY_SUCH_K = -2;

int check3(int p, int q, int r){
	// check if such k exists that k >= 0 && p == k * q + r
	if( q == 0 )
		return p == r ? ANY_SUCH_K : NO_SUCH_K;
	int k = (p - r) / q;
	if(k < 0 || p != k * q + r)
		return NO_SUCH_K;
	return k;
}
inline bool check2(int w, int h, int x, int y){
	int k1 = check3(a, w, x), k2 = check3(b, h, y);
	return k1 != NO_SUCH_K && k2 != NO_SUCH_K && (k1 == ANY_SUCH_K || k2 == ANY_SUCH_K || k1 == k2);
}
bool check(){
	int w = 0, h = 0;
	for(int i = 0; i < len; i++){
		switch(s[i]){
		case 'U': h++; break;
		case 'D': h--; break;
		case 'R': w++; break;
		case 'L': w--; break;
		}
	}
	if(check2(w, h, 0, 0))
		return true;
	for(int i = 0, x = 0, y = 0; i < len; i++){
		switch(s[i]){
		case 'U': y++; break;
		case 'D': y--; break;
		case 'R': x++; break;
		case 'L': x--; break;
		}	
		if(check2(w, h, x, y))
			return true;
	}
	return false;
}
int main(){
	cin >> a >> b;
	cin >> s;
	len = strlen(s);
	cout << (check() ? "Yes" : "No") << endl;
	return 0;
}