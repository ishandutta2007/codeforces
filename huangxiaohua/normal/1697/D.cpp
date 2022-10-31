#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[10500],sb[6666],it,cur,res;
char ans[6666];
string s1="$",s2="$";

int get(int l,int r){
	set<int >s;
	for(int i=l;i<=r;i++)s.insert(s1[i]);
	return s.size();
}

void ask(int l,int r){
	if(l>it){
		f[cur]=++it;
		res=-1;
		return;
	}
	if(l>r)return;
	int md=(l+r)/2;
	int i,j,k;
	cout<<"? "<<2<<' '<<sb[md]<<' '<<cur<<endl;
	cin>>k;
	//k=get(sb[md],cur);
	if(k==(md+1)){
		ask(md+1,r);
	}
	else{
		res=min(res,md);
		ask(l,md-1);
	}
}

int main(){
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	uniform_int_distribution<int>lim('a','z');
	ios::sync_with_stdio(0);
	
	cin>>n;
	//n=rng()%1000+1;cout<<n<<endl;
	/*for(i=1;i<=n;i++){
		string NMSL="X";
		NMSL[0]=lim(rng);
		s1+=NMSL;
	}*/
	
	f[1]=it=1;
	for(i=2;i<=n;i++){
		cur=i;
		res=666;
		for(j=1;j<i;j++)sb[f[j]]=j;
		sort(sb+1,sb+it+1);
		reverse(sb+1,sb+it+1);
		ask(1,it);
		if(res!=-1){
			f[i]=f[sb[res]];
		}
	}
	for(j=1;j<i;j++)sb[f[j]]=j;
	for(i=1;i<=it;i++){
		cout<<"? "<<1<<' '<<sb[i]<<endl;
		cin>>ans[i];
		//ans[i]=s1[sb[i]];
	}
	cout<<"! ";
	for(i=1;i<=n;i++){
		cout<<ans[f[i]];
		//s2+=ans[f[i]];
	}
	
	//cout<<endl;cout<<"!! "<<s1<<endl;cout<<"!! "<<s2<<endl;
	//if(s1!=s2)return 1;
}