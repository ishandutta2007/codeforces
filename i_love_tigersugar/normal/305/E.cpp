#include<set>
#include<cstdio>
#include<vector>
#include<cstring>
#define MAX   6005
#define x   first
#define y   second
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
/*const ll mod=(ll)1e9+33;
const ll base=31LL;*/
char s[MAX];
int n;
int sp[MAX];
/*ll fh[MAX];
ll bh[MAX];
ll pw[MAX];*/
vector<ii> fst;
void init(void) {
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(sp,-1,sizeof sp);
}
/*void gethash(void) {
	int i;
	pw[0]=1LL;
	for (i=1;i<=n;i=i+1) pw[i]=(pw[i-1]*base)%mod;
	for (i=1;i<=n;i=i+1) fh[i]=(fh[i-1]+pw[i-1]*(s[i]-'a'))%mod;
	for (i=n;i>=1;i=i-1) bh[i]=(bh[i+1]+pw[n-i]*(s[i]-'a'))%mod;
}
bool palin(const int &l,const int &r) {
	ll x=(fh[r]-fh[l-1]+mod)%mod;
	ll y=(bh[l]-bh[r+1]+mod)%mod;
	if (l-1<n-r) x=(x*pw[n-r-l+1])%mod;
	if (n-r<l-1) y=(y*pw[l-1-n+r])%mod;
	return (x==y);
}*/
bool ok(const int &l,const int &r,const int &m) {
	if (m>=r || m<=l) return (false);
	return (s[m-1]==s[m+1]);
	/*if (2*m-l<=r) return (palin(l,2*m-l));
	return (palin(2*m-r,r));*/
}
int sprague(const int &l) {
	if (l<=0) return 0;
	if (sp[l]>=0) return (sp[l]);
	set<int> s; s.clear();
	int i;
	for (i=1;i<=l;i=i+1) s.insert(sprague(i-2)^sprague(l-i-1));
	for (sp[l]=0;s.find(sp[l])!=s.end();sp[l]++);
	return (sp[l]);
}
void process(void) {
	int res=0;
	int i,j;
	j=1;
	for (i=1;i<=n+1;i=i+1) {
		//printf("Ok %d %d\n",i,ok(1,n,i));
		if (ok(1,n,i)) {
			if (!ok(1,n,i-1)) j=i;
		}
		else {
			if (ok(1,n,i-1)) fst.push_back(ii(j,i-j));
		}
	}	
	for (i=0;i<fst.size();i=i+1) res=res^sprague(fst[i].y);
	//for (i=0;i<fst.size();i=i+1) printf("%d %d\n",fst[i].x,fst[i].y);
	if (res==0) {
		printf("Second");
		return;
	}
	printf("First\n");
	for (i=0;i<fst.size();i=i+1) {
		res=0;
		for (j=0;j<i;j=j+1) res=res^sprague(fst[j].y);
		for (j=i+1;j<fst.size();j=j+1) res=res^sprague(fst[j].y);
		for (j=1;j<=fst[i].y;j=j+1)
			if ((res^sprague(j-2)^sprague(fst[i].y-j-1))==0) {
				printf("%d",fst[i].x+j-1);
				return;
			}
	}
}
int main(void) {
	init();
//	gethash();
	process();
	return 0;
}