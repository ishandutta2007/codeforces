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
int n,r;
int getope(int a,int b){//a:=up b:=bot
	int ope=0;
	while(a>0 && b>0){
		if(a>=b){
			ope+=a/b;
			a%=b;
		}else{
			ope+=(b-1)/a;
			b-=(b-1)/a*a;
		}
	}
	if(a==0 && b==1) return ope;
	return -1;
}
int getmis(int a,int b){
	int ope=0,res=0;
	int last=-1;
	while(a>0 && b>0){
		if(a>=b){
			res+=a/b-1;
			a%=b;
			last=1;
		}else{
			res+=(b-1)/a-1;
			b-=(b-1)/a*a;
			last=2;
		}
	}
	dump(last);dump(res);
	if(last!=1) return INF;
	return res;
}
string answer;
void makeans(int a,int b){
	int ope=0,res=0;
	while(a>0 && b>0){
		if(a>=b){
			REP(i,a/b) answer+='T';
			a%=b;
		}else{
			REP(i,(b-1)/a) answer+='B';
			b-=(b-1)/a*a;
		}
	}
	reverse(ALL(answer));
}
int main(){
	scanf("%d%d",&n,&r);
	int least=INF,t,b;
	for(int i=1;i<=r;++i){
		if(getope(i,r)==n){
			int tmp=getmis(i,r);
			if(least>tmp){
				least=tmp;
				t=i;b=r;
			}
		}
		if(getope(r,i)==n){
			int tmp=getmis(r,i);
			if(least>tmp){
				least=tmp;
				t=r;b=i;
			}
		}
	}
	if(least>=INF){
		puts("IMPOSSIBLE");
		return 0;
	}
	makeans(t,b);
	printf("%d\n",least);
	cout<<answer<<endl;
	return 0;
}