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
int n,loop;
char s[100005];
void doit(int f,int s,int i){
	if(loop%2==0){
		REP(i,f) putchar('4');
		REP(i,s) putchar('7');
	}else{
		if(i%2==0) ++f,--s;
		else --f,++s;
		REP(i,f) putchar('4');
		REP(i,s) putchar('7');
	}
	loop=0;
}
int main(){
	cin>>n>>loop;
	scanf("%s",s);
	if(loop==0){
		printf("%s\n",s);
		return 0;
	}

	REP(i,n){
		if(s[i]!='4' || loop==0){
			putchar(s[i]);
			continue;
		}
		int j=i;
		while(j<n && s[j]=='4'){
			++j;
		}
		int k=j;
		while(k<n && s[k]=='7') ++k;

		int four=j-i,sev=k-j;
		if(sev==0){
			REP(it,four) putchar('4');
		}else if(four==1 && sev==1){
			if((j-1)%2==0) printf("44");
			else printf("77");
			--loop;
		}else if(four==1){
			if((j-1)%2==0){
				doit(four,sev,j-1);
			}else{
				REPN(it,k,i) putchar('7');
				--loop;
			}
		}else if(sev==1){
			if((j-1)%2==1){
				doit(four,sev,j-1);
			}else{
				REPN(it,k,i) putchar('4');
				--loop;
			}
		}else{
			doit(four,sev,j-1);
		}
		i=k-1;
	}
	putchar('\n');

	return 0;
}