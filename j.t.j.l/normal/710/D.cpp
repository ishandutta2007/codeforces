#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;
ll a1,a2,b1,b2,L,R;

void read(){
	scanf("%lld%lld%lld%lld%lld%lld", &a1, &b1, &a2, &b2, &L, &R);
}

ll exgcd(ll a, ll b, ll& x, ll& y){//xyax+by=gcd(a,b)
    if(!b) return x=1,y=0,a;
    ll u=exgcd(b,a%b,y,x);
    return y-=a/b*x,u;
}

ll equation(int n, ll m[], ll r[]){
    ll ans=0,lcm=1,x,y;
    for(int i=0;i<n;i++){
        ll g=exgcd(lcm,m[i],x,y);
        if((r[i]-ans)%g || r[i]>=m[i]) return -1;
        x*=(r[i]-ans)/g; y=m[i]/g;
        ans+=(x%y+y)%y*lcm;ans%=lcm*=y;
    }
    return ans;
}

ll gcd(ll x, ll y){
	return y ? gcd(y, x%y) : x;
}

ll _m[100], _r[100];

void solve(){
	L = max(L, b1);
	L = max(L, b2);
	if (L > R){
		puts("0");
		return ;
	}
	_m[0] = a1, _r[0] = (b1 % a1 + a1) % a1;
	_m[1] = a2, _r[1] = (b2 % a2 + a2) % a2;
	ll x = equation(2, _m, _r);
//	cout<<x<<endl;
	if (x == -1){
		puts("0");
	}
	else{
		ll y = a1 * a2 / gcd(a1, a2);
		ll z = -(L - 1 - x) / y + 1;
		if (z > 0){
			L += z * y;
			R += z * y;
		}
	//	cout<<L<<' '<<R<<endl;
		printf("%lld\n", max(0ll, (R - x) / y - (L - 1 - x) / y));
	}
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