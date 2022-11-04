// my font is too big I guess
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct Node{
	int res=INT_MAX,dpt=0,mnval=INT_MAX,mxval=INT_MIN;
	Node*l=0,*r=0;
	void recalc(){
		if(dpt){
			res=min(l->res,r->res);
			if(l->mxval!=INT_MIN&&r->mnval!=INT_MAX)res=min(res,abs((r->mnval|1<<(dpt-1))-l->mxval));
			mxval=max(l->mxval,r->mxval|1<<(dpt-1));
			mnval=min(l->mnval,r->mnval|1<<(dpt-1));
		}
	}
	void swap(){
		auto tmp=r;
		r=l;l=tmp;
		recalc();
//		cerr<<l->mxval<<" "<<r->mnval<<endl;
	}
	void build(int d,int val);
};


const int N=20;
vector<Node*>depths[N];
int pres[1<<N];
int n,k,a[1<<N];

Node*add(){
	return new Node();
}

void Node::build(int d,int val){
	dpt=d;
	if(!d&&pres[val])mnval=mxval=0;
	if(d){
		l=add();
		r=add();
		if(d-1)depths[d-1].push_back(l);
		if(d-1)depths[d-1].push_back(r);
		l->build(d-1,val);
		r->build(d-1,val|(1<<(d-1)));
		recalc();
	}
//	cerr<<d<<" "<<val<<" "<<pres[val]<<" "<<res<<endl;
}


void ProGamerMove(){
	cin>>n>>k;
	for(int i=0;i<n;++i)cin>>a[i],pres[a[i]]=true;
	Node*root=add();
	depths[k].push_back(root);
	root->build(k,0);
	vector<int>res(1<<k),gray(1);
	for(int i=0;i<k;++i){
		for(int j=gray.size()-1;j>=0;--j)gray.push_back(1<<i|gray[j]);
	}
	res[0]=root->res;
	for(int i=1;i<gray.size();++i){
		for(int l=k-1,r=0;l>r;--l,++r){
			bool a=1<<l&gray[i],b=1<<r&gray[i];
			gray[i]&=-1^1<<r^1<<l;
			gray[i]|=a<<r;
			gray[i]|=b<<l;
		}
		int lvl=__builtin_ctz(gray[i]^gray[i-1])+1;
		for(int j=lvl;j<=k;++j)
			for(auto&u:depths[j])
				if(j==lvl)u->swap();
				else u->recalc();
		res[gray[i]]=root->res;
//		cerr<<lvl<<" "<<gray[i]<<" "<<root->res<<endl;
//		exit(0);
	}
	for(auto v:res)cout<<v<<" ";
	cout<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}