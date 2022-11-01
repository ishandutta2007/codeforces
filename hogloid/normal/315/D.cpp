#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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
int b,d;
string a,c;

int where[105],done[105];

int solve(int len){
	string tmp;
	int n=a.size(),m=c.size();
	REP(i,len) tmp+=a[n-1-i%n];
	reverse(ALL(tmp));

	int pos=0;
	REP(i,tmp.size()){
		if(c[pos%m]==tmp[i]) ++pos;
	}
	return pos/m;
}

int main(){
	cin>>b>>d>>a>>c;

	int n=a.size(),m=c.size();
	
	int pos=0,cnt=0;

	int able=0;
	while(1){
		REP(i,m){
			int fail=1;
			REP(j,n) if(a[(pos+j)%n]==c[i]){
				pos+=j;
				fail=0;
				break;
			}
			++pos;
			if(fail){
				puts("0");
				return 0;
			}
		}
		if(pos>a.size()*b){
			able=cnt;
			break;
		}
		if(done[pos%n]){
			REP(j,cnt) if(where[j]%n==pos%n){
				int tot_len=a.size()*b;
				int rest=tot_len-pos;

				int block=pos-where[j],how=rest/block;
				int worth=cnt-j;

				int rest2=rest%block;
				able=solve(rest2)+cnt+1+how*worth;
				goto exi;
			}
		}
		where[cnt++]=pos;

		done[pos%n]=1;
	}
exi:;
	printf("%d\n",able/d);


	return 0;
}