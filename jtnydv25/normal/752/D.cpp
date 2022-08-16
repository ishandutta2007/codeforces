#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define endl "\n"
bool is_pal(string &s)
{
	int n = s.length();
	for(int i = 0;i<n/2;i++) if(s[i]!=s[n-1-i]) return 0;
	return 1;
}
int mod1 = 1e9+7,mod2=1e9+9,base = 97;
map<pii,pii> ulta;
pii hash2(string &s)
{
	int x1 = 0,x2 = 0,x3=0,x4=0,n=s.length();
	for(int i = 0;i<n;i++)
	{
		int v = s[i]-'a',v1 = s[n-1-i]-'a';
		x1 = (x1*1ll*base + v)%mod1;
		x2 = (x2*1ll*base + v)%mod2;
		x3 = (x3*1ll*base + v1)%mod1;
		x4 = (x4*1ll*base + v1)%mod2;
	}
	ulta[mp(x1,x2)]=mp(x3,x4);
	return mp(x1,x2);
}
map<pii,int> freq;
const int N = 1e5+10;
int a[N];
string s[N];
set<pii> pals;
map<pii, vi> myp;
pii maxsm(vi &vec)
{
	sort(all(vec));
	int sm1 = 0, sm2 = vec.back();
	for(int i = sz(vec)-1;i>=1;i-=2)
	{
		if(vec[i]+vec[i-1]>=0) sm1+=vec[i]+vec[i-1];
		if(i-2>=0 && vec[i-1]+vec[i-2] > 0) sm2+=vec[i-1]+vec[i-2];
	}
	return mp(sm1,sm2);
}
map<pii,bool > done;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,k,ans = 0,evensm=0;
	cin>>k>>n;
	rep(i,1,k+1){
		cin>>s[i]>>a[i];
		pii p = hash2(s[i]);
		myp[p].eb(a[i]);
		if(is_pal(s[i])) pals.insert(p);
	}
	for(auto it:myp)
	{
		pii p1 = it.F, p2 = ulta[p1];
		if(!done[p1] && !done[p2] && p1 != p2)
		{
			vi vec1 = myp[p1],vec2=myp[p2];
			sort(all(vec1)),sort(all(vec2)),reverse(all(vec1)),reverse(all(vec2));
			for(int i = 0;i<sz(vec1)&&i<sz(vec2);i++)
			if(vec1[i]+vec2[i]>0) evensm += vec1[i]+vec2[i];
		}
		if(p1 == p2 && !done[p1])
		{
			vi vec = myp[p1];
			sort(all(vec)),reverse(all(vec));
			for(int i = 0;i<sz(vec)-1;i+=2)
			if(vec[i]+vec[i+1] > 0) evensm += vec[i] + vec[i+1];
		}
		done[p1]=1, done[p2]=1;
	}
	ans = evensm;
	for(pii it: pals)
	{
		vi vec = myp[it];
		sort(all(vec)), reverse(all(vec));
		int ans1 = 0, ans2 = vec[0];
		for(int i = 0;i<sz(vec)-1;i+=2)
		if(vec[i]+vec[i+1] > 0) ans1 += vec[i] + vec[i+1];
		for(int i = 1;i<sz(vec)-1;i+=2)
		if(vec[i]+vec[i+1] > 0) ans2 += vec[i] + vec[i+1];
		ans = max(ans,evensm+ans2-ans1);
	}
	cout<<ans;
}