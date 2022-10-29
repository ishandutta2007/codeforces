#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
char s[MAXN];

void read(){
	scanf("%d%d", &n, &m);
	scanf("%s", s);
}

void solve(){
	int p = 0;
	for(; s[p] != '.'; p++);
	p++;
//	cout<<p<<endl;
	int flag = 0;
	for(int i = p; i < n; i++){
		if (s[i] >= '5'){
			s[i] = 0;
			flag = 1;
			int j;
			for(j = i - 1; j >= p && flag && m;  j--){
				s[j+1] = 0;
				if (s[j] == '9') s[j] = 0, flag = 1;
				else {
					s[j]++;
					if (s[j] >= '5'){
						m--;
						flag = 1;
					}
					else{
						flag = 0;
					}
				}
			}
			if (j >= p) flag = 0;
			if (s[p-1] != '9' && m == 0) flag = 0; 
			break;
		}
	}
//	cout<<flag<<endl;
	int Qaq = 0;
	if (flag){
		s[p-1] = 0;
		for(int i = p - 2; i >= 0; i--){
			if (s[i] == '9')
				s[i] = '0';
			else{
				s[i]++;
				flag = 0;
				break;
			}
		}
		if (flag)
			Qaq = 1;
	}
	//if (s[p] == 0) s[p-1] = 0;
	if (Qaq) printf("1");
	printf("%s\n", s);
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}