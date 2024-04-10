#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500],b[100500],it;
string s,res;
char c[100500];

vector<pair<int,int> >v;

void get(int x){
	int it1,it2,i,j,k;
	it1=it2=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	s.clear();
	for(i=x-1;i>=1;i--){
		a[++it1]=c[i]-'0';
	}
	for(i=n;i>=x;i--){
		b[++it2]=c[i]-'0';
	}
	k=max(it1,it2);
	for(i=1;i<=k;i++){
		a[i]+=b[i];
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	if(a[k+1]){k++;}
	for(i=k;i>=1;i--){
		s+=(char)('0'+a[i]);
	}
	//cout<<x<<' '<<s<<endl;
	if(!res.size()){res=s;return;}
	if(s.size()<res.size()){res=s;return;}
	if(s.size()==res.size()&&s<res){res=s;}
}

int main(){
	cin>>n>>c+1;
	for(i=2;i<=n;i++){
		if(c[i]!='0'){
			v.push_back({max(i,n-i),i});
		}
	}
	sort(v.begin(),v.end());
	for(auto [i,j]:v){
		//printf("%d %d\n",i,j);
		it++;
		get(j);
		if(it>=50){break;}
	}
	cout<<res;
}