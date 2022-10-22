#include<bits/stdc++.h>
using namespace std;
int n,x,a,b,c,y;

int next() {
	return x=(x*a+b)%c;
}

pair<int,string> team[64];
vector<string> basket[4];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>n>>x>>a>>b>>c;
	for(int i=0; i<n; i++) {
		string name;
		int rating;
		cin>>name>>rating;
		team[i]=make_pair(rating,name);
	}
	sort(team,team+n,greater<pair<int,string> >());
	for(int i=0; i<n; i++) {
		basket[i/(n>>2)].push_back(team[i].second);
	}
	for(int k=0; k< n/4; ++k) {
		printf("Group %c:\n",'A'+k);
		for(int i=0; i<4; i++) {
			int j=next()%(int)basket[i].size();
			printf("%s\n",basket[i][j].c_str());
			basket[i].erase(basket[i].begin()+j);
		}
	}
	return 0;
}

/*
8
1 3 1 7
Barcelona 158
Milan 90
Spartak 46
Anderlecht 48
Celtic 32
Benfica 87
Zenit 79
Malaga 16
*/