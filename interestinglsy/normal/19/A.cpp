#include <bits/stdc++.h>
#define il inline
#define For(i,j) for( int (i) = 1 ; (i) <= (j) ; (i)++ )
#define For0(i,j) for( int (i) = 0 ; (i) < (j) ; (i)++ )
using namespace std;

#define MAXN 55
struct Team{
	string name;
	int point,scored,missed;
	Team(){}
	Team( string nn , int pp , int ss , int mm ){
		name = nn;
		point = pp;
		scored = ss;
		missed = mm;
	}
};
bool operator<( Team t1 , Team t2 ){
	if( t1.point != t2.point )
		return t1.point > t2.point;
	if( t1.scored-t1.missed != t2.scored-t2.missed )
		return t1.scored-t1.missed > t2.scored-t2.missed;
	return t1.scored > t2.scored;
}
bool cmp( Team t1 , Team t2 ){
	return t1.name < t2.name;
}

int n,tot;
map<string,int> nameid;
Team team[MAXN];

il void Read( int &x ){
	char c = getchar();
	while( !isdigit(c) ) c = getchar();
	x = 0;
	while( isdigit(c) ){
		x *= 10;
		x += c-'0';
		c = getchar();
	}
}
il void Readname( string &ret ){
	char c = getchar();
	while( !isalpha(c) ) c = getchar();
	ret = "";
	while( isalpha(c) ){
		ret += c;
		c = getchar();
	}
}
il void Addmatch( string t1 , string t2 , int p1 , int p2 ){
	int a = nameid[t1], b = nameid[t2];
	team[a].scored += p1; team[b].scored += p2;
	team[a].missed += p2; team[b].missed += p1;
	if( p1 == p2 ){
		team[a].point++;
		team[b].point++;
	}
	if( p1 > p2 )
		team[a].point += 3;
	if( p1 < p2 )
		team[b].point += 3;
}

int main(){
	#ifdef WIN32
		freopen("in.in","r",stdin);
	#endif

	Read(n);
	For(i,n){
		string s;
		Readname(s);
		team[i].name = s;
		nameid[s] = i;
	}

	tot = n*(n-1) >> 1;
	For(i,tot){
		string t1,t2; int p1,p2;
		Readname(t1);
		Readname(t2);
		Read(p1); Read(p2);
		Addmatch(t1,t2,p1,p2);
	}

	sort(team+1,team+1+n);
	sort(team+1,team+1+(n>>1),cmp);

	For(i,n>>1)
		cout << team[i].name << endl;

	return 0;
}