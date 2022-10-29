#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
const int o = 500;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int p[o], q[o];
int a[o];

int mp[o<<1][o<<1];

void pt(int x, int y, int z){
	mp[x+o][y+o] = z;
}

int ts(int x, int y){
	return mp[x+o][y+o];
}

void read(){

}

void solve(){
	cin>>n;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int x = 0, y = 0;
	int nd = 0;
	for(int i = 1; i <= n; i++){
		p[i] = x, q[i] = y;
		for(int j = 1; j <= a[i]; j++){
			x += dx[nd], y += dy[nd];
			pt(x,y,i);
		}
		nd = (nd + 1) % 8;
	}
	for(int i = n-1; i >= 1; i--){
		int zz;
		for(int xx = -150; xx <= 150; xx++)
			for(int yy = -150; yy <= 150; yy++){
				if ((zz = ts(xx,yy)) > i){
					if (dx[(i-1)%8] == 0) pt(2*p[i]-xx, yy, zz);
					else if (dy[(i-1)%8] == 0) pt(xx, 2*q[i]-yy, zz);
					else if (dx[(i-1)%8] == dy[(i-1)%8]) pt(yy-q[i]+p[i], xx+q[i]-p[i], zz);
					else pt(p[i]+q[i]-yy, p[i]+q[i]-xx, zz);
				}
			}
	}
	int ans = 0;
	for(int x = -150; x <= 150; x++)
		for(int y = -150; y <= 150; y++)
			ans += (ts(x, y) > 0);
	cout<<ans<<endl;
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