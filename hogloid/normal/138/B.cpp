#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
char n[100005];
int cnt[2][15],back[2][15];
int len;
int sum[2][15];
string ans,ans2;
int main(){
	scanf("%s",n);
	len=strlen(n);
	REP(i,len) cnt[0][n[i]-'0']++,++cnt[1][n[i]-'0'];
	
	memcpy(back,cnt,sizeof(cnt));
	int res=-1;
	REP(i,10) REP(j,10) if(i+j==10 && cnt[0][i]>0 && cnt[1][j]>0){
		--cnt[0][i];--cnt[1][j];
		int tmp=(i+j==10);
		for(int k=1;k<10;++k){
			tmp+=min(cnt[0][k],cnt[1][9-k]);
			cnt[1][9-k]-=min(cnt[1][9-k],cnt[0][k]);
		}
		tmp+=min(cnt[0][0],cnt[1][9]+cnt[1][0]);
		res=max(res,tmp);
		memcpy(cnt,back,sizeof(cnt));
	}
	if(res<cnt[0][0]){
		sort(n,n+len,greater<char>());
		cout<<n<<'\n'<<n<<endl;
		return 0;
	}
	dump(res);
	REP(i,10) REP(j,10) if(i+j==10 && cnt[0][i]>0 && cnt[1][j]>0){
		--cnt[0][i];--cnt[1][j];
		int tmp=(i+j==10);
		for(int k=1;k<10;++k){
			tmp+=min(cnt[0][k],cnt[1][9-k]);
			cnt[1][9-k]-=min(cnt[1][9-k],cnt[0][k]);
		}
		tmp+=min(cnt[0][0],cnt[1][9]+cnt[1][0]);

		if(res==tmp){
			memcpy(cnt,back,sizeof(cnt));
			--cnt[0][i];--cnt[1][j];
			ans+=i+'0';
			ans2+=j+'0';
			int t;
			for(int k=1;k<10;++k){
				t=min(cnt[0][k],cnt[1][9-k]);
				REP(hoge,t) ans+=k+'0',ans2+=(9-k+'0');
				cnt[1][9-k]-=t;
				cnt[0][k]-=t;
			}

			t=min(cnt[0][0],cnt[1][9]+cnt[1][0]);
			int prev=cnt[1][0];
			REP(hoge,t){
				--cnt[0][0];
				if(hoge<prev){
					ans2='0'+ans2;
					ans='0'+ans;
					--cnt[1][0];
				}
				else {
					--cnt[1][9];
					ans+='0';
					ans2+='9';
				}
			}
			dump(ans);dump(ans2);

			REP(k,10) {
				REP(hoge,cnt[0][k]) ans+=k+'0';
				REP(hoge,cnt[1][k]) ans2+=k+'0';
			}
			reverse(ALL(ans2));
			reverse(ALL(ans));

			cout<<ans<<'\n'<<ans2<<endl;
			return 0;
		}
		memcpy(cnt,back,sizeof(cnt));
	}





	return 0;
}