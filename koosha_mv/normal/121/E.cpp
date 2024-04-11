#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+99,sq=1000,mx=1e4+99;

int n, m, a[N], is_lucky[N], lazy[N], cnt[sq][mx];
vector<int> lucky;

void makelucky(int x){
	if(x > mx) return ;
	lucky.pb(x);
	is_lucky[x]=1;
	makelucky(x*10+4);
	makelucky(x*10+7);
}
void add(int l,int r,int val){
	while(l<=r && l%sq!=0){
		cnt[l/sq][a[l]]--;
		a[l] += val;
		cnt[l/sq][a[l]]++;
		l++;
	}
	if(l>r) return ;
	while((r+1)%sq!=0){
		cnt[r/sq][a[r]]--;
		a[r] += val;
		cnt[r/sq][a[r]]++;
		r--;
	}
	while(l<r){
		lazy[l/sq] += val;
		l+=sq;
	}
}
int get(int l,int r){
	int ans=0;
	while(l<=r && l%sq!=0){
		ans += is_lucky[a[l] + lazy[l/sq]];
		l++;
	}
	if(l>r) return ans;
	while((r+1)%sq!=0){
		ans += is_lucky[a[r] + lazy[r/sq]];
		r--;
	}
	while(l<r){
		f(i,0,lucky.size()){
			ans += cnt[l/sq][max(0,lucky[i]-lazy[l/sq])];
		}
		l += sq;
	}
	return ans;
}

int main(){
	makelucky(4);
	makelucky(7);
	cin >> n >> m;
	f(i,0,n){
		cin >> a[i] ;
		cnt[i/sq][a[i]]++;
	}
	f(i,0,m){
		string s;
		int l, r, val;
		cin>>s;
		if(s[0] == 'a'){
			cin >> l >> r >> val;
			add(l-1, r-1, val);
		}
		else{
			cin >> l >> r;
			cout << get(l-1, r-1) << '\n';
		}
	}
}