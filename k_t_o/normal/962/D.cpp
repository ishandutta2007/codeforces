#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

struct node{
	long long a,i;
	bool operator < (const node & o)const{
		if(a!=o.a)return a<o.a;
		return i<o.i;
	}
};
set<node>::iterator it;
set<node>S;
long long ii,s,a,d[150005],m,n,op[150006];
set<node> :: iterator it2; //o:;//_ _ //_ _...
int main() //signed //int
{
	n=read();
	for(int i=1; i<=n; ++i){
		a=read();
//		mp[a].insert(i);
		S.insert((node){a,i});
	}
	while(!S.empty()){
		if(S.size()==1){
			it=S.begin();
			d[(*it).i]=(*it).a;
			break;
		}
		//*S.begin()
		it=S.begin(); //=it+1
		it2=++S.begin();
		if((*it).a==(*it2).a){
			ii=(*it2).i;
			a=(*it2).a;
			S.erase(it); 
			S.erase(S.begin()); 
			S.insert((node){a*2,ii});//={};//,}// //map bianli
			continue;
		}
		d[(*it).i]=(*it).a;
		S.erase(it);
		//con
	}
	for(int i=1; i<=n; ++i){
		if(d[i]){
			op[++m]=d[i];
		}
	}
	printf("%d\n",m);//_ \n//duohe??dange
	for(int i=1; i<=m; ++i)printf("%lld ",op[i]);//<<  //-9 -7 >>1 /2
	//(int)  .0f   //-4.9  4.9  0.5f   0 5 
}