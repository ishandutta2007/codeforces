#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rev(s) reverse(s.begin(),s.end());
int i,j,k,n,m,t,x,y;
string s1;
struct sb{
	string l,r;
	set<string> s[14];
}s[250];

void add(int x,string s1){
	int i,j,k=s1.size();
	for(i=1;i<=12;i++){
		for(j=0;j+i-1<k;j++){
			s[x].s[i].insert(s1.substr(j,i));
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>s1;
		add(i,s1);
		s[i].l=s1.substr(0,13);rev(s1);
		s[i].r=s1.substr(0,13);rev(s[i].r);
	}
	cin>>m;
	for(i=n+1;i<=n+m;i++){
		cin>>x>>y;
		for(j=1;j<=12;j++){
			set_union(s[x].s[j].begin(),s[x].s[j].end(),s[y].s[j].begin(),s[y].s[j].end(),inserter(s[i].s[j],s[i].s[j].begin()));
		}
		s1=s[x].l+s[y].l;
		s[i].l=s1.substr(0,13);
		s1=s[x].r+s[y].r;rev(s1);
		s[i].r=s1.substr(0,13);rev(s[i].r);
		s1=s[x].r+s[y].l;
		add(i,s1);
		for(j=1;j<=12;j++){
			if(s[i].s[j].size()!=(1<<j)){
				cout<<j-1<<'\n';break;
			}
		}
	}
}