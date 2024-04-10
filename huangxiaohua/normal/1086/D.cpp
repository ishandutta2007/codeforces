#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,res,fs[200500],fj[200500],fb[200500];
char s[200500];
set<int> ss,sj,sb;
int shi,jian,bu;
string st;

void add(int *f,int x,int y){
	for(;x<=n;x+=(-x&x)){f[x]+=y;}
}

int get(int *f,int x,int y=0){
	for(;x;x-=(-x&x)){y+=f[x];}return y;
}

void change(int x,char c){
	//printf("a%d %d %d\n",shi,jian,bu);
	if(s[x]=='R'){shi--;ss.erase(x);add(fs,x,-1);}
	if(s[x]=='S'){jian--;sj.erase(x);add(fj,x,-1);}
	if(s[x]=='P'){bu--;sb.erase(x);add(fb,x,-1);}
	s[x]=c;
	if(s[x]=='R'){shi++;ss.insert(x);add(fs,x,1);}
	if(s[x]=='P'){bu++;sb.insert(x);add(fb,x,1);}
	if(s[x]=='S'){jian++;sj.insert(x);add(fj,x,1);}
	//printf("a%d %d %d\n",shi,jian,bu);
}

int get1(){//shi
	int res=shi,i,j,k,l1,r1,l2,r2;
	if(!shi){return 0;}
	if(!bu){return shi;}
	if(!jian){return 0;}
	
	l1=(*sb.begin());
	auto it1=sb.end();it1--;
	r1=*it1;
	
	l2=(*sj.begin());
	auto it2=sj.end();it2--;
	r2=*it2;
	if(l1<=l2){
		res-=get(fs,l2)-get(fs,l1);
	}
	
	if(r1>=r2){
		res-=get(fs,r1)-get(fs,r2);
	}
	//printf("shi %d\n",res);
	return res;
}

int get2(){//jian
	int res=jian,i,j,k,l1,r1,l2,r2;
	if(!jian){return 0;}
	if(!shi){return jian;}
	if(!bu){return 0;}
	
	l1=(*ss.begin());
	auto it1=ss.end();it1--;
	r1=*it1;
	
	l2=(*sb.begin());
	auto it2=sb.end();it2--;
	r2=*it2;
	if(l1<=l2){
		res-=get(fj,l2)-get(fj,l1);
	}
	
	if(r1>=r2){
		res-=get(fj,r1)-get(fj,r2);
	}
	//printf("jian %d\n",res);
	return res;
}

int get3(){//bu
	int res=bu,i,j,k,l1,r1,l2,r2;
	if(!bu){return 0;}
	if(!jian){return bu;}
	if(!shi){return 0;}
	
	l1=(*sj.begin());
	auto it1=sj.end();it1--;
	r1=*it1;
	
	l2=(*ss.begin());
	auto it2=ss.end();it2--;
	r2=*it2;
	if(l1<=l2){
		res-=get(fb,l2)-get(fb,l1);
	}
	
	if(r1>=r2){
		res-=get(fb,r1)-get(fb,r2);
	}
	//printf("bu %d %d %d %d %d\n",res,l1,r1,l2,r2);
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>t>>s+1;
	for(i=1;i<=n;i++){
		if(s[i]=='R'){
			shi++;
			ss.insert(i);
			add(fs,i,1);
		}
		if(s[i]=='P'){
			bu++;
			sb.insert(i);
			add(fb,i,1);
		}
		if(s[i]=='S'){
			jian++;
			sj.insert(i);
			add(fj,i,1);
		}
	}
	cout<<get1()+get2()+get3()<<'\n';
	while(t--){
		cin>>k>>st;
		change(k,st[0]);
		//cout<<s+1<<' '<<shi<<' '<<jian<<' '<<bu<<endl;
		cout<<get1()+get2()+get3()<<'\n';
	}
}