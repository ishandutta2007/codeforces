#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define xx first
#define yy second

typedef long long ll;

struct vec {
	ll x,y;int d;
	vec&operator+=(const vec&a) {
	 	x+=a.x,y+=a.y;
		return *this;
	}
	vec&operator-=(const vec&a) {
		x-=a.x,y-=a.y;
		return *this;
	}
	vec operator+(const vec&b)const {
		vec a=*this;a+=b;return a;
	}
	vec operator-(const vec&b) {
		vec a=*this;a-=b;return a;
	}
	ll operator%(const vec&a)const {
		return x*a.y-y*a.x;
	}
	void cald(){
		if(x>=0&&y>0)d=0;
		else if(x<0&&y>=0)d=1;
		else if(x<=0&&y<0)d=2;
		else d=3;
	}
	bool operator<(const vec&b)const{
		if(d!=b.d)return d<b.d;
		return (*this)%b>0;
	}
};

const int N = 2505;

int n;
vec s[N], t[N];
pair<vec,int>r[N*2];
bool use[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", &s[i].x, &s[i].y);
	ll ans=0;
	for (int i = 1; i <= n; i++) {
		int c = 0;
		for (int j = 1; j <= n;j ++) {
			if (j^i)t[++c]=s[j]-s[i],t[c].cald();
		}
		for(int j=1;j<=c;j++){
			r[j]=mp(t[j],j);
			r[j+c]=mp((vec){0,0}-t[j],-j);
			r[j+c].xx.cald();
		}
		std::sort(r+1,r+c*2+1);
		for(int j=1;j<=c;j++) use[j] = 0;
		int tc = 0;
		for(int j=1;j<=c*2;j++){
			if(r[j].yy>0){
				tc+=!use[r[j].yy];
				use[r[j].yy]=1;
			}else{
				tc-=use[-r[j].yy];
				use[-r[j].yy]=0;
			}
		}
		ll tans = 0;
		for(int j=1;j<=c*2;j++){
			if(r[j].yy>0){
				assert(!use[r[j].yy]);
				tans+=tc*(tc-1)/2;
				//printf("/%d %d %d\n",j,r[j].yy,tc);
				tc++;
				use[r[j].yy]=1;
			}else{
				assert(use[-r[j].yy]);
				//printf("@%d %d %d\n",j,r[j].yy,tc);
				tc--;
				use[-r[j].yy]=0;
			}
		}
		ans+=(ll)(n-1)*(n-2)*(n-3)/6-tans;
		//printf("%lld\n",tans);
	}
	//printf("%lld\n",ans);
	printf("%lld\n",ans*(n-4)/2);
}