#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

char s[MAXN];

map<string, int> st;

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		char t[10];
		scanf("%s", t);
		long long x, y;
		if (t[0] == '+'){
			scanf("%lld", &x);
			string str = "";
			while(x){
				str = (x % 2 == 0 ? "0" : "1") + str;
				x /= 10;
			}
			while(str[0] == '0')
				str = str.substr(1);
		//	cout<<"+ "<<str<<endl;
			st[str]++;
		}
		else if (t[0] == '-'){
			scanf("%lld", &x);
			string str = "";
			while(x){
				str = (x % 2 == 0 ? "0" : "1") + str;
				x /= 10;
			}
			while(str[0] == '0')
				str = str.substr(1);
		//	cout<<"- "<<str<<endl;
			st[str]--;
		}
		else{
			scanf("%s", s);
			string t = "";
			int l = strlen(s);
			for(int i = 0; i < l; i++)
				t += (s[i] == '0') ? "0" : "1";
			while(t[0] == '0')
				t = t.substr(1);
		//	cout<<"? "<<t<<endl;
			printf("%d\n", st[t]);
		}
	}
	return 0;
}