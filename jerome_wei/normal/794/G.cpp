#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
int ans=0;
const int N = 2e6+5;
char c[N], d[N];
int lc,ld,n;
int a1,b1,c1,a2,b2,c2;
void calc(char *s,int len,int &a,int &b,int &c){
	for(int i=0;i<len;i++){
		if(s[i]=='A')a++;
		else if(s[i]=='B')b++;
		else c++;
	}
}
vector < pair<int,int> > s;
int pw2[N];
int fac[N], ifac[N];
inline int binom(int a,int b){
	if(b<0||b>a)return 0;
	return mul(fac[a], mul(ifac[b], ifac[a-b]));
}

int ff[N];

void dododo(){
	for(int i=1;i<=n;i++)ff[i] = mul(n/i, n/i);
	for(int i=n;i;i--){
		for(int j=i*2;j<=n;j+=i){
			ff[i]=sub(ff[i],ff[j]);
		}
	}
}

int main()
{
	pw2[0]=1;for(int i=1;i<N;i++)pw2[i] = add(pw2[i-1],pw2[i-1]);
	ifac[0]=fac[0]=1;for(int i=1;i<N;i++)fac[i]=mul(fac[i-1],i);
	ifac[N-1]=qpow(fac[N-1],mod-2);for(int i=N-2;i;i--)ifac[i]=mul(ifac[i+1],i+1);
	scanf("%s%s%d",c,d,&n);
	dododo();
	lc = strlen(c), ld = strlen(d);
	calc(c,lc,a1,b1,c1);
	calc(d,ld,a2,b2,c2);
	int curs = -c2 +a1 -a2;
	for(int i=-max(lc,ld);i<=max(lc,ld);i++)s.push_back(make_pair(i, lc-ld-i));
	int w=1;
	if(lc==ld){
		for(int i=0;i<lc;i++){
			if(c[i]=='?' && d[i]=='?'){
				w=mul(w,2);
			}
			else if(c[i] != '?' && d[i] != '?' && c[i]!=d[i])w=0;
		}
		ans = add(ans, mul(w, mul(sub(pw2[n+1],2),sub(pw2[n+1],2))));
	}else w=0;
	// int tot = 0;
	// cout << ans << endl;
	// cout << curs << "::" << endl;
	for(int i=0;i<(int)s.size();i++){
		int x = s[i].first, y = s[i].second;//A1 - A2 = x, B1 - B2 = y, c != d
		// x*len1 + y*len2 = 0
		// len1 : len2 = y : -x
		// cout << x << ":" << y << endl;
		int way = binom(c1+c2,x-curs);
		// tot = add(tot, way);
		// cout << way << ":::";
		y = -y;
		if(x < 0 && y < 0)x = -x, y = -y;
		if(x < 0 || y < 0)continue;
		if((x == 0) != (y == 0))continue;
		// cout << x << ":" << y << endl;
		if(x==0 && y==0){
			// cout << c1+c2 << " " << x-curs << endl;
			way = sub(way,w);
			// cout << way << endl;
			int _s = 0;
			for(int i=1;i<=n;i++){
				// cout << ff[i] << " ";
				_s = add(_s, mul(ff[i], pw2[i]));
			}
			ans=add(ans, mul(_s,way));
		}else{
			int D, g = __gcd(x,y);
			x/=g,y/=g,g=1;D=n/max(x,y);
			// cout << D << ":" << g << "::";
			int RR = sub(qpow(pw2[g],D+1),1);
			int inv = qpow(sub(pw2[g],1),mod-2);
			RR=mul(RR,inv);
			RR=sub(RR,1);
			// cout << RR << "::" << way << "!" << endl;
			ans = add(ans, mul(RR,way));
		}
	}
	// cout << tot << endl;
	cout << ans << endl;
}