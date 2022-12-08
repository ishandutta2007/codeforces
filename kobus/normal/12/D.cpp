#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX/2
#define MOD 1000000

int bit[MAXN];
pair<int,pii> v[MAXN];
int n;

int helpme[MAXN];

void upd(int a, int x){
	if(a==0)return;
	for(int i=a;i<MAXN;i+=(i&-i)){
		bit[i]=max(bit[i],x);
	}
}

int get(int a){
	int resp=0;
	for(int i=a;i>0;i-=(i&-i)){
		resp=max(resp,bit[i]);
	}
	return resp;
}

bool rev(pair<int,pii> a,pair<int,pii> b){
	return a.f>b.f;
}

bool forcomp(pair<int,pii> a,pair<int,pii> b){
	return a.s.f<b.s.f;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;

	//ler entrada
	for(int i=0;i<n;i++){
		cin>>v[i].f;
	}
	for(int i=0;i<n;i++){
		cin>>v[i].s.f;
	}
	for(int i=0;i<n;i++){
		cin>>v[i].s.s;
	}
	//comprimir coordenada
	sort(v,v+n,forcomp);
	int mark=0;
	for(int i=0;i<n;i++){
		helpme[i]=mark;
		if(i==n-1||v[i+1].s.f!=v[i].s.f)mark++;
	}
	for(int i=0;i<n;i++){
		v[i].s.f=helpme[i];
	}
	//preparar pra bit
	sort(v,v+n,rev);

	//rodar na bit
	int resp=0;
	queue<pii> q;
	for(int i=0;i<n;){
		if(get(MAXN-v[i].s.f-1)>v[i].s.s){
			//cout<<i<<" : "<<v[i].s.f<<" "<<v[i].s.s<<endl;
			//cout<<"   "<<get(MAXN-v[i].s.f-1)<<endl;
			resp++;
		}
		q.push(mp(MAXN-v[i].s.f,v[i].s.s));
		i++;
		while(i<n && v[i].f==v[i-1].f){
			if(get(MAXN-v[i].s.f-1)>v[i].s.s){
				resp++;
			}
			q.push(mp(MAXN-v[i].s.f,v[i].s.s));
			i++;
		}
		while(!q.empty()){
			pii aux=q.front();
			q.pop();
			upd(aux.f,aux.s);
		}
	}


	cout<<resp<<endl;

	return 0;
}