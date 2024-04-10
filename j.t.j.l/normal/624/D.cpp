#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
const long long INF = (1LL) << 60;

int a[MAXN];
int minp[MAXN + 1], plist[MAXN + 1];
int cnt;
int n, A, B;
long long f[MAXN][3];

int prime(int n = MAXN) {
    int num = 0;
    memset(minp, 0, sizeof(minp));
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) plist[num++] = i, minp[i] = i;
        for (int j = 0; j < num && i * plist[j] <= n; j++) {
            minp[i * plist[j]] = plist[j];
            if (i % plist[j] == 0) break;
        }
    }
    return num;
}

set<int> s;

void work(int n){
	for(int i = 0; i < cnt; i++)
		if (plist[i] * plist[i] > n)
			break;
		else{
			if (n % plist[i] == 0)
				s.insert(plist[i]);
			while (n % plist[i] == 0)
				n /= plist[i];
		}
	if (n != 1)
		s.insert(n);
}

long long gao(int p){
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 3; j++)
			f[i][j] = INF;
	f[0][0] = f[0][1] = f[0][2] = 0;
	for(int i = 1; i <= n; i++){
		if (a[i] % p == 0){
			f[i][0] = f[i-1][0];
			f[i][1] = min(f[i-1][0], f[i-1][1]) + A;
			f[i][2] = min(f[i-1][1], f[i-1][2]);
		}
		else{
			if ((a[i] + 1) % p == 0 || (a[i] - 1) % p == 0){
				f[i][0] = f[i-1][0] + B;
				f[i][1] = min(f[i-1][0], f[i-1][1]) + A;
				f[i][2] = min(f[i-1][1], f[i-1][2]) + B;
			}
			else{
				f[i][0] = INF;
				f[i][1] = min(f[i-1][0], f[i-1][1]) + A;
				f[i][2] = f[i-1][1] + A;
			}
		}
	}
	return min(f[n][0], min(f[n][1], f[n][2]));
}

int main(){
	cnt = prime();
	cin>>n>>A>>B;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	s.clear();
	work(a[1] - 1);
	work(a[1]);
	work(a[1] + 1);
	work(a[n] - 1);
	work(a[n]);
	work(a[n] + 1);
	long long ans = INF;
	for(auto j = s.begin(); j != s.end(); j++){
	//	cout<<(*j)<<endl;
		ans = min(ans, gao(*j));
	//	cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}