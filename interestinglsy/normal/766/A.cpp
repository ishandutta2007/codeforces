#include <iostream>
#include <cstdio>
#include <string.h>
#define ms(n) memset(n,0,sizeof(n))
using namespace std;

string a,b;
int lena,lenb;
int ans;
int app[30];

int main(){
	ms(app);
	
	cin >> a >> b;
	
	lena = a.length();
	lenb = b.length();
	
	bool flag = true;
	
	if(lena == lenb){
		flag = false;
		for(int i = 0;i < lena;i++)
			if(a[i] != b[i]){
				flag = true;
				break;
			}
	}
	
	if(flag) cout << max(lena,lenb) << endl;
	else cout << -1 << endl;
	
	return 0;
}