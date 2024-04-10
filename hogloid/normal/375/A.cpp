#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}

lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I64d",res);
#else
	printf("%lld",res);
#endif
}

//const int INF=5e8;

int nums[4]={1,8,6,9};
string s;

int app[10];
int main(){
	
	cin>>s;
	REP(i,4){
		REP(j,s.size()) if(s[j]-'0'==nums[i]){
			s.erase(s.begin()+j);
			break;
		}
	}
	sort(ALL(s));
	reverse(ALL(s));
	if(!s.empty() && s[0]=='0'){
		cout<<"1869";
		cout<<s<<endl;
		return 0;
	}

	cout<<s;
	int rest=0;
	REP(i,s.size()) rest=(rest*10+s[i]-'0')%7;
	do{
		int res=0;
		REP(i,4) res=res*10+nums[i];
		res%=7;
		if((res+rest*10000)%7==0){
			printf("%d%d%d%d\n",nums[0],nums[1],nums[2],nums[3]);
			break;
		}
	}while(next_permutation(nums,nums+4));

	return 0;
}