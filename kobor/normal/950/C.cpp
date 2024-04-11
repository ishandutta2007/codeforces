#include <bits/stdc++.h>

using namespace std;

bool wzi[200001];
int newek[200001];
vector<int> odp[200001];
vector<int> c;
vector<pair<bool, int> > d;
deque<int> otw;
deque<int> zam;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int op=0, cl=0, ile=-1;
	cin>>s;
	if(s[0]=='1'||s[s.length()-1]=='1'){
		cout<<-1<<'\n';
		return 0;
	}
	wzi[0]=true;
	c.push_back(0);
	for(int i=0; i<s.length()-1; i++){
		if(s[i]=='1'&&s[i+1]=='0'){
			wzi[i]=true;
			wzi[i+1]=true;
			c.push_back(i);
			c.push_back(i+1);
		}
	}
	for(int i=0; i<s.length(); i++){
		if(!wzi[i]){
			d.push_back(make_pair(s[i]-'0', i));
		}
	}
	if(d.empty()){
		cout<<1<<'\n';
		cout<<c.size()<<' ';
		for(int i=0; i<c.size(); i++){
			cout<<c[i]+1<<' ';
		}
		cout<<'\n';
		return 0;
	}
	if(d[0].first){
		cout<<-1<<'\n';
		return 0;
	}
	for(int i=0; i<d.size(); i++){
		if(d[i].first==false){
			op++;
			if(cl){
				cl--;
				newek[i]=zam[0];
				zam.pop_front();
				otw.push_back(newek[i]);
			}
			else{
				ile++;
				newek[i]=ile;
				otw.push_back(ile);
			}
		}
		else{
			if(op){
				op--;
				cl++;
				newek[i]=otw[0];
				otw.pop_front();
				zam.push_back(newek[i]);
			}
			else{
				cout<<-1<<'\n';
				return 0;
			}
		}
	}
	if(cl){
		cout<<-1<<'\n';
		return 0;
	}
	for(int i=0; i<d.size(); i++){
		odp[newek[i]].push_back(d[i].second);
	}
	cout<<ile+2<<'\n';
	cout<<c.size()<<' ';
	for(int i=0; i<c.size(); i++){
		cout<<c[i]+1<<' ';
	}
	cout<<'\n';
	for(int i=0; i<=ile; i++){
		cout<<odp[i].size()<<' ';
		for(int j=0; j<odp[i].size(); j++){
			cout<<odp[i][j]+1<<' ';
		}
		cout<<'\n';
	}
	return 0;
}

/*
00000000010101110001111001111000110000000
*/